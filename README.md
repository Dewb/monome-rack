monome-rack — VCVRack plugin for monome hardware
---

### What is this?

This is a work-in-progress repo for a plugin package for the [VCVRack open-source virtual modular synthesizer](https://github.com/VCVRack/Rack) that implements (some of) the Eurorack modules and control hardware manufactured by [monome](https://monome.org). This is an unofficial community-driven port and no support, warranty, or affiliation is implied.

<img width="75%" alt="white whale and virtual grid in VCVRack" src="https://user-images.githubusercontent.com/712405/33520884-380980be-d791-11e7-9259-ce5879837f8b.png">

This plugin includes:
* A virtual version of the venerable [grid 128](https://monome.org/docs/grid/), a flexible 16x8 grid controller
* The [white whale](https://monome.org/docs/modular/whitewhale/) grid-enabled probabilistic step sequencer
   * Uses either a virtual grid, or a real grid connected via serialosc

### Why is this?

In order of importance, the initial goals of this project were/are:

* Provide an easier environment for developing, debugging, and testing new and improved firmware features for the monome Eurorack modules
* Allow existing hardware users to practice, experiment, and/or record while traveling light
* Expose new users to the monome philosophy and ecosystem
* "Because it was there"

### How does this work?

The firmware for the monome modules are written in C for the AVR32 platform. (For more details, [go here](https://github.com/monome/libavr32).) In this project, these firmware projects are built into separate C shared libraries together with stub I/O implementations for parts of the AVR32 API. The Rack plugin will load a new copy of this firmware library into memory for each module that you load, so statics and globals work as expected within each module instance.

### How do I use this?

For now, this is a *source-only plugin*, no binary package is provided. *You must also build VCVRack from source before you can compile plugins* -- the downloadable version will not work.

This plugin has been built and tested on the following platforms:
* Mac OS X 10.12.6
* Windows 10 (with Msys2)
* Ubuntu 16.04

Instructions:

* Clone [VCVRack](https://github.com/VCVRack/Rack) 0.5.0 or later and follow its build instructions for your platform.
* Clone this repo into the `plugins` folder under VCVRack.
* Change into the `monome-rack` folder and clone submodules with `git submodule update --init --recursive`
* Build with `make`, or open the `monome-rack` folder in Visual Studio Code and select `Tasks > Run Build Task`.

Now that you've built the plugin, let's get to patching:

* Start VCVRack. Add a `white whale` and `grid 128` module to your patch.
* Right-click the `white whale` module and select your virtual grid from the list of devices. It should light up.
* Read the [white whale manual](https://monome.org/docs/modular/whitewhale/).
* Watch these videos:
   * [white whale possibilities](https://vimeo.com/104881064)
   * [white whale tutorial](https://vimeo.com/105368808)
* Read the [white whale manual](https://monome.org/docs/modular/whitewhale/) again.

### Who did this?

Original hardware and firmware code in linked submodules is by [monome](monome.org) with contributions from the community at [lines](https://llllllll.co) The VCVRack-specific code in this repository is a separate effort, and again, no support or warranty is implied.

[Michael Dewberry](http://dewb.org) ([@dewb](https://github.com/Dewb)) wrote the virtual grid module, the hardware simulation layer, and the VCV module wrapper for white whale.

Additional community contributions and feedback are very welcome! Discuss either in an [issue here](/../../issues) or in the [lines thread](https://llllllll.co/t/white-whale-in-vcvrack/10337). 

## License

The original monome firmware is licensed under the GPL version 2.

The new code in this repository is also licensed under the GPL version 2.

The base64, oscpack, and serialosc libraries are licensed from their authors via GPL-compatible licenses according to the LICENSE file in each subfolder under lib/.
