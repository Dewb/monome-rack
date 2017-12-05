monome-rack — VCVRack plugin for monome hardware
---

### What is this?

This is a work-in-progress repo for a plugin package for the [VCVRack open-source virtual modular synthesizer](https://github.com/VCVRack/Rack) that implements (some of) the Eurorack modules and control hardware manufactured by [monome](https://monome.org). This is an unofficial community-driven port and no support, warranty, or affiliation is implied.

This plugin has been built and tested on the following platforms:
* Mac OS X 10.12.6
* Windows 10 (with Msys2)
* Ubuntu 16.04

<img width="75%" alt="white whale and virtual grid in VCVRack" src="https://user-images.githubusercontent.com/712405/33520884-380980be-d791-11e7-9259-ce5879837f8b.png">

### What is included?

* A virtual version of the venerable [grid 128](https://monome.org/docs/grid/), a flexible 16x8 grid controller
* The [white whale](https://monome.org/docs/modular/whitewhale/) grid-enabled probabilistic step sequencer
   * Uses either a virtual grid, or a real grid connected via serialosc
   * Currently limited to one instance per rack, see [issues](#issues) below

### How do I use it?

1. Build the library using [the instructions below](#how-to-build) -- no binary release is provided yet.
2. Start VCVRack. Add a `white whale` and `grid 128` module to your patch.
3. Right-click the `white whale` module and select your virtual grid from the list of devices. It should light up.
4. Start reading the [white whale manual](https://monome.org/docs/modular/whitewhale/)!

### Why is this?

In order of importance, the initial goals of this project were/are:

* Provide an easier environment for developing, debugging, and testing new and improved firmware features for the monome Eurorack modules
* Allow existing hardware users to practice, experiment, and/or record while traveling light
* Expose new users to the monome philosophy and ecosystem
* "Because it was there"

### How does it work?

The firmware for the monome modules are written in C for the AVR32 platform. (For more details, [go here](https://github.com/monome/libavr32).) In this project, these firmware projects are built into separate C shared libraries together with stub I/O implementations for parts of the AVR32 API. The Rack plugin will load a new copy of this firmware library into memory for each module that you load, so statics and globals work as expected within each module instance.

### What's coming next?

* The Teletype module
* More grids

### Who did this?

Original hardware and firmware code in linked submodules is by [monome](monome.org). The VCVRack-specific code in this repository is a separate effort, and again, no support or warranty is implied.

[@dewb](https://github.com/Dewb) wrote the virtual grid module, the initial mock hardware layer, and ported white whale. 

Additional community contributions and feedback are very welcome! Discuss either in an [issue here](/../../issues) or in the [lines thread](https://llllllll.co/t/white-whale-in-vcvrack/10337). 


## Issues

* The state of working memory and the flash memory are persisted to the VCVRack patch, but something is wrong with the preset glyphs.
* The right-click menu system to assign grids to modules needs work. Unplugging a real monome’s USB cable while it’s connected to a virtual module can cause a crash. In some situations, deleting a virtual grid from a patch can cause a crash. Assigning two modules to the same virtual grid produces unexpected results.
* If Rack crashes while these modules are in your rack, some files may be left in your system temporary file folder.
* Currently, only modern varibright grid 128 models are supported, for both virtual and real grids. (A real varibright 256 will work, but will only use the top half.) 
* No performance analysis has been done. Changes were made with intent to be efficient, and initial testing sounds good, but no deep study of the timing or the CPU utilitization has been performed yet. There is likely room for improvement.

For more, see [the discussion thread here](https://llllllll.co/t/white-whale-in-vcvrack/10337).


## How to build

For now, this is a source-only plugin, no binary package is provided. The plugin has been built and tested on OS X 10.12.6, Windows 10 with Msys2, and Ubuntu 16.04.

1. Clone [VCVRack](https://github.com/VCVRack/Rack) 0.5.0 or later and follow its build instructions.
2. Clone this repo into the `plugins` folder under VCVRack.
4. Change into the `monome-rack` folder and clone submodules with `git submodule update --init --recursive`
5. Build with `make` or open the `monome-rack` folder in Visual Studio Code and select `Tasks > Run Build Task`.

## License

The original monome firmware is licensed under the GPL version 2.

The new code in this repository is also licensed under the GPL version 2.

The base64, oscpack, and serialosc libraries are licensed from their authors via GPL-compatible licenses according to the LICENSE file in each subfolder under lib/.
