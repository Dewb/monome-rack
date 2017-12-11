monome-rack — VCVRack plugin for monome hardware
---

### What is this?

This is a plugin for the [VCVRack open-source virtual modular synthesizer](https://github.com/VCVRack/Rack) that implements (some of) the Eurorack modules and control hardware manufactured by [monome](https://monome.org). This is an unofficial community-driven port and no support, warranty, or affiliation is implied.

This is a work-in-progress. [Here's the roadmap to get to a binary release on the package manager.](https://github.com/Dewb/monome-rack/projects/1) If you're not using the source version of VCV Rack, and you're not comfortable with git and make, you might want to wait until the binary release.

<img width="75%" alt="monome modules and virtual grid in VCVRack" src="https://user-images.githubusercontent.com/712405/33818500-4c54d158-de13-11e7-8a74-3b8b1fe8b21d.png">


This plugin currently includes:
* A virtual version of the venerable [grid 128](https://monome.org/docs/grid/), an open, interactive 16x8 grid instrument
* The [white whale](https://monome.org/docs/modular/whitewhale/) "Grid-enabled Probabilistic Step Sequencer"
   * A 16-step sequencer with a focus on live-manipulation and controlled variations
   * 4 trigger outs, 2 CV outs
   * Controlled by internal or external clock
* The [meadowphysics](https://monome.org/docs/modular/meadowphysics/) "Grid-enabled Rhizomatic Cascading Counter"
   * An event sequencer for polyrhythms and rule-based evolving patterns.
   * 8 trigger outs
   * Controlled by internal or external clock
* The [earthsea](https://monome.org/docs/modular/earthsea/) "Grid-enabled Shape-Memory Pattern Instrument"
   * A live keyboard that can sequence melodies and recall CV with gestures.
   * 1 trigger out, 4 CV outs
   
All three of the modules can connect to either a virtual grid or a real hardware grid controller through [serialosc](https://monome.org/docs/setup/).

### How do I use this?

For now, this is a *source-only plugin*, no binary package is provided. *You must also build VCVRack from source before you can compile plugins* -- this will not work with the downloadable version of VCVRack.

This plugin has been built and tested on the following platforms:
* Mac OS X 10.12.6
* Windows 10 (with Msys2)
* Ubuntu 16.04

Instructions:

* Clone [VCVRack](https://github.com/VCVRack/Rack) and follow its build instructions for your platform. Build the master branch, not 0.5.0.
* Clone this repo into the `plugins` folder under VCVRack.
* Change into the `monome-rack` folder and clone submodules with `git submodule update --init --recursive`
* Build with `make`, or open the `monome-rack` folder in Visual Studio Code and select `Tasks > Run Build Task`.

Now that you've built the plugin, let's get to patching:

* Start VCVRack. Add a `white whale` and `grid 128` module to your patch.
* Right-click the `white whale` module and select your virtual grid from the list of devices. It should light up.
* Read the manuals for the modules:
   * [white whale manual](https://monome.org/docs/modular/whitewhale/)
   * [meadowphysics manual](https://monome.org/docs/modular/meadowphysics/)
   * [earthsea manual](https://monome.org/docs/modular/earthsea/)
* Watch these videos:
   * [white whale possibilities](https://vimeo.com/104881064)
   * [white whale tutorial part 1](https://vimeo.com/105368808)
   * [white whale tutorial part 2](https://vimeo.com/105368874)
   * [white whale tutorial part 3](https://vimeo.com/105408057)
   * [white whale tutorial part 4](https://vimeo.com/105408747)
   * [meadowphysics possibilities](https://vimeo.com/107582557)
   * [meadowphysics tutorial](https://vimeo.com/107586549)
   * [meadowphysics two](https://vimeo.com/146731772)
   * [earthsea introduction](https://vimeo.com/113231441)
* Read the manuals again, watch the videos again, repeat.

### Why is this?

In order of importance, the initial goals of this project were/are:

* Provide an easier environment for developing, debugging, and testing new and improved firmware features for the monome Eurorack modules
* Allow existing hardware users to practice, experiment, and/or record while traveling light
* Expose new users to the monome hardware/software ecosystem
* Accelerate development of completely new grid applications
* "Because it was there"

### How does this work?

The firmware for the monome modules are written in C for the AVR32 platform. (For more details, [go here](https://github.com/monome/libavr32).) In this project, these firmware projects are built into separate C shared libraries together with stub I/O implementations for parts of the AVR32 API. The Rack plugin will load a new copy of this firmware library into memory for each module that you load, so statics and globals work as expected within each module instance.

### Who did this?

Original hardware and firmware code in linked submodules is by [monome](monome.org) with contributions from the community at [lines](https://llllllll.co). The VCVRack-specific code in this repository is a separate effort, and again, no support or warranty is implied.

[Michael Dewberry](http://dewb.org) ([@dewb](https://github.com/Dewb)) wrote the virtual grid module, the hardware simulation layer, and the VCV module wrapper for white whale.

Additional community contributions and feedback are very welcome! Discuss either in an [issue here](/../../issues) or in the [lines thread](https://llllllll.co/t/white-whale-in-vcvrack/10337). 

## License

The original monome firmware is licensed under the GPL version 2.

The new code in this repository is also licensed under the GPL version 2.

The base64, oscpack, and serialosc libraries are licensed from their authors via GPL-compatible licenses according to the LICENSE file in each subfolder under lib/.
