
/*******************************************************************************
*  The "New BSD License" : http://www.opensource.org/licenses/bsd-license.php  *
********************************************************************************

Copyright (c) 2010, Mark Turney
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#include "simple_svg_1.0.0.hpp"

using namespace svg;

// Demo page shows sample usage of the Simple SVG library.

int main()
{
    Dimensions dimensions(100, 100);
    Document doc("my_svg.svg", Layout(dimensions, Layout::BottomLeft));

    // Red image border.
    Polygon border(Stroke(1, Color::Red));
    border << Point(0, 0) << Point(dimensions.width, 0)
        << Point(dimensions.width, dimensions.height) << Point(0, dimensions.height);
    doc << border;

    // Long notation.  Local variable is created, children are added to varaible.
    LineChart chart(5.0);
    Polyline polyline_a(Stroke(.5, Color::Blue));
    Polyline polyline_b(Stroke(.5, Color::Aqua));
    Polyline polyline_c(Stroke(.5, Color::Fuchsia));
    polyline_a << Point(0, 0) << Point(10, 30)
        << Point(20, 40) << Point(30, 45) << Point(40, 44);
    polyline_b << Point(0, 10) << Point(10, 22)
        << Point(20, 30) << Point(30, 32) << Point(40, 30);
    polyline_c << Point(0, 12) << Point(10, 15)
        << Point(20, 14) << Point(30, 10) << Point(40, 2);
    chart << polyline_a << polyline_b << polyline_c;
    doc << chart;

    // Condensed notation, parenthesis isolate temporaries that are inserted into parents.
    doc << (LineChart(Dimensions(65, 5))
        << (Polyline(Stroke(.5, Color::Blue)) << Point(0, 0) << Point(10, 8) << Point(20, 13))
        << (Polyline(Stroke(.5, Color::Orange)) << Point(0, 10) << Point(10, 16) << Point(20, 20))
        << (Polyline(Stroke(.5, Color::Cyan)) << Point(0, 5) << Point(10, 13) << Point(20, 16)));

    doc << Circle(Point(80, 80), 20, Fill(Color(100, 200, 120)), Stroke(1, Color(200, 250, 150)));

    doc << Text(Point(5, 77), "Simple SVG", Color::Silver, Font(10, "Verdana"));

    doc << (Polygon(Color(200, 160, 220), Stroke(.5, Color(150, 160, 200))) << Point(20, 70)
        << Point(25, 72) << Point(33, 70) << Point(35, 60) << Point(25, 55) << Point(18, 63));

    doc << Rectangle(Point(70, 55), 20, 15, Color::Yellow);

    doc.save();
}
