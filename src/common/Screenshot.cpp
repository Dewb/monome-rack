#include "Screenshot.hpp"
#include "osdialog.h"
#include "stb_image_write.h"

#if SCREENSHOT_SVG

#include <simple_svg_1.0.0.hpp>
#include <nanovg.h>
#include <memory>

struct SVGcontext
{
    svg::Document doc;
    int width;
    int height;
};

int svg__renderCreate(void* uptr, void* otherUptr)
{
    return 1;
}

int svg__renderCreateTexture(void* uptr, int type, int w, int h, int imageFlags, const unsigned char* data)
{
    return 1;
}

int svg__renderDeleteTexture(void* uptr, int image)
{
    return 1;
}

int svg__renderUpdateTexture(void* uptr, int image, int x, int y, int w, int h, const unsigned char* data)
{
    return 1;
}

int svg__renderGetTextureSize(void* uptr, int image, int* w, int* h)
{
    return 1;
}

void svg__renderViewport(void* uptr, float width, float height, float devicePixelRatio)
{
    
}

void svg__renderFlush(void* uptr)
{

}

svg::Point vertToPoint(SVGcontext* ctx, NVGvertex v)
{
    return svg::Point(v.x, ctx->height - v.y);
}

void svg__renderFill(void* uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, float fringe, const float* bounds, const NVGpath* paths, int npaths)
{
    SVGcontext* svgContext = reinterpret_cast<SVGcontext*>(uptr);
    if (svgContext == nullptr)
    {
        return;
    }

    for (int i = 0; i < npaths; i++)
    {
        auto c = paint->innerColor;
        svg::Color fillColor(c.r, c.g, c.b);
        svg::Polygon svgPolygon((svg::Fill(svg::Color::White), svg::Stroke(1, svg::Color::Black)));

        const NVGpath* path = &paths[i];
        for (int v = 0; v < path->nstroke; v++)
        {
            svgPolygon << vertToPoint(svgContext, path->stroke[v]);
        }

        svgContext->doc << svgPolygon;
    }
}

void svg__renderStroke(void* uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, float fringe, float strokeWidth, const NVGpath* paths, int npaths)
{
    SVGcontext* svgContext = reinterpret_cast<SVGcontext*>(uptr);
    if (svgContext == nullptr)
    {
        return;
    }

    for (int i = 0; i < npaths; i++)
    {
        svg::Polyline svgPolyline(svg::Stroke(strokeWidth, svg::Color::Black));

        const NVGpath* path = &paths[i];
        for (int v = 0; v < path->nstroke; v++)
        {
            svgPolyline << vertToPoint(svgContext, path->stroke[v]);
        }

        svgContext->doc << svgPolyline;
    }
}

void svg__renderTriangles(void* uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, const NVGvertex* verts, int nverts, float fringe)
{

}

void svg__renderDelete(void* uptr)
{
    SVGcontext* svgContext = reinterpret_cast<SVGcontext*>(uptr);
    if (svgContext == nullptr)
    {
        return;
    }

    svgContext->doc.save();

    delete svgContext;
}

struct NVGcontext* nvgCreateSVGRenderer(std::string svgPath, int width, int height, NVGcontext* other)
{
    struct NVGparams params;
    struct NVGcontext* ctx = NULL;
    struct SVGcontext* userData = new SVGcontext();

    svg::Dimensions dimensions(width, height);
    svg::Document doc(svgPath, svg::Layout(dimensions, svg::Layout::BottomLeft));

    svg::Polygon border(svg::Stroke(1, svg::Color::Red));
    border << svg::Point(0, 0) << svg::Point(dimensions.width, 0)
           << svg::Point(dimensions.width, dimensions.height) << svg::Point(0, dimensions.height);
    doc << border;
    //doc.save();

    userData->doc = doc;
    userData->width = width;
    userData->height = height;

    memset(&params, 0, sizeof(params));
    params.renderCreate = svg__renderCreate;
    params.renderCreateTexture = svg__renderCreateTexture;
    params.renderDeleteTexture = svg__renderDeleteTexture;
    params.renderUpdateTexture = svg__renderUpdateTexture;
    params.renderGetTextureSize = svg__renderGetTextureSize;
    params.renderViewport = svg__renderViewport;
    params.renderFlush = svg__renderFlush;
    params.renderFill = svg__renderFill;
    params.renderStroke = svg__renderStroke;
    params.renderTriangles = svg__renderTriangles;
    params.renderDelete = svg__renderDelete;
    params.userPtr = userData;
    params.edgeAntiAlias = 1;

    ctx = nvgCreateInternal(&params, other);
    return ctx;
}

void nvgDestroySVGRenderer(NVGcontext* ctx)
{
    nvgDeleteInternal(ctx);
}

void screenshotModuleSVG(rack::app::ModuleWidget* moduleWidget, std::string svgPath)
{
    auto size = moduleWidget->box.size;
    auto ctx = nvgCreateSVGRenderer(svgPath, size.x, size.y, nullptr);

    rack::widget::Widget::DrawArgs args;
    args.vg = ctx;
    args.fb = nullptr;
    args.clipBox = rack::math::Rect(0, 0, size.x, size.y);

    moduleWidget->draw(args);

    nvgDestroySVGRenderer(ctx);
}

#endif

void screenshotModulePNG(rack::app::ModuleWidget* moduleWidget, std::string defaultFileName)
{
    // adapted from rack::Window::screenshotModules()
    // https://github.com/VCVRack/Rack/blob/a811a9c78a4876824a2f721d91bdebced6a1a387/src/window/Window.cpp#L564

    float zoom = 2.0;

    auto fbw = new rack::widget::FramebufferWidget;
    fbw->oversample = 1;

    struct ModuleWidgetContainer : rack::widget::Widget
    {
        void draw(const DrawArgs& args) override
        {
            Widget::draw(args);
            Widget::drawLayer(args, 1);
        }
    };
    ModuleWidgetContainer* mwc = new ModuleWidgetContainer;
    fbw->addChild(mwc);

    rack::app::ModuleWidget* mw = moduleWidget->model->createModuleWidget(moduleWidget->module);
    mwc->box.size = mw->box.size;
    fbw->box.size = mw->box.size;
    mwc->addChild(mw);

    fbw->step();
    fbw->render(rack::math::Vec(zoom, zoom));

    char* path_result = osdialog_file(
        OSDIALOG_SAVE,
        NULL,
        defaultFileName.c_str(),
        NULL);

    if (!path_result)
        return;

    nvgluBindFramebuffer(fbw->getFramebuffer());
    int width, height;
    int depth = 4;

    nvgImageSize(APP->window->vg, fbw->getImageHandle(), &width, &height);
    uint8_t* pixels = new uint8_t[height * width * depth];
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

    for (int y = 0; y < height / 2; y++)
    {
        int flipY = height - y - 1;
        uint8_t tmp[width * depth];
        std::memcpy(tmp, &pixels[y * width * depth], width * depth);
        std::memcpy(&pixels[y * width * depth], &pixels[flipY * width * depth], width * depth);
        std::memcpy(&pixels[flipY * width * depth], tmp, width * depth);
    }

    stbi_write_png(path_result, width, height, depth, pixels, width * depth);

    delete[] pixels;
    nvgluBindFramebuffer(NULL);

    mw->module = nullptr;
    delete fbw;

    INFO("Screenshot saved to %s", path_result);
    std::free(path_result);
}