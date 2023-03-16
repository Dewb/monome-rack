monome-rack — VCVRack plugin for monome hardware
---

### What is this?

This is a *PRERELEASE* plugin for the [VCVRack open-source virtual modular synthesizer](https://github.com/VCVRack/Rack) that implements (some of) the Eurorack modules and control hardware designed and manufactured by [monome](https://monome.org). This is an unofficial community-driven port, and no support guarantees, warranty, or affiliation is implied from any organization mentioned in this document.

This plugin is still in development. [The extremely hypothetical release roadmap is here](https://github.com/users/Dewb/projects/1). 

<img width="90%" alt="monome modules and virtual grid in VCVRack" src="https://user-images.githubusercontent.com/712405/211141286-85785c64-74d3-46a0-a81d-241824a77178.png">

This plugin currently includes:
* [teletype](https://monome.org/docs/teletype/), an algorithmic ecosystem
   * a dynamic, musical, scriptable event triggering platform.
   * 8 trigger ins, 1 CV in, 4 CV and 4 trigger outs
* [ansible](https://monome.org/docs/ansible/), a multi-mode module
   * with a grid, can run the [kria](https://monome.org/docs/ansible/kria/) sequencer, plus polyphonic versions of the [meadowphysics](https://monome.org/docs/ansible/meadowphysics/) and [earthsea](https://monome.org/docs/ansible/earthsea/) modules
   * with an arc controller, can run the apps [levels](https://monome.org/docs/ansible/levels/) or [cycles](https://monome.org/docs/ansible/cycles/)
   * 4 CV outs, 4 trigger outs, 2 trigger ins
* [white whale](https://monome.org/docs/whitewhale/), a grid-enabled probabilistic step sequencer
   * A 16-step sequencer with a focus on live-manipulation and controlled variations
   * 4 trigger outs, 2 CV outs
   * Controlled by internal or external clock
* [meadowphysics](https://monome.org/docs/meadowphysics/), a grid-enabled rhizomatic cascading counter
   * An event sequencer for polyrhythms and rule-based evolving patterns
   * 8 trigger outs
   * Controlled by internal or external clock
* [earthsea](https://monome.org/docs/earthsea/), a grid-enabled shape-memory pattern instrument
   * A live keyboard that can sequence melodies and recall CV with gestures
   * 1 trigger out, 4 CV outs
* Support for [monome grid](https://monome.org/docs/grid/) hardware controllers, both current editions and older models, plus virtual versions of the controllers within VCV Rack, in 64, 128, and 256-key flavors.
    
All of the modules can connect to either a virtual grid or a real hardware grid controller. ([Serialosc](https://monome.org/docs/setup/) is required to use real hardware, but no drivers are required for the virtual grids.) 

Through the virtual grid, all features of each module are accessible, but some features are awkward to use without multiple fingers on a real grid. Control-clicking (Linux/Windows) or Command-clicking (Mac OS) will allow you to "hold" keys to perform multi-press gestures.

### How do I use this?

1. Install [serialosc](https://monome.org/docs/setup/).
2. Download a release for your platform from the [Releases page](../../releases) and place it in your `Rack2\plugins` folder.

More detailed instructions are available in the [Rack documentation on installing non-library plugins](https://vcvrack.com/manual/Installing#Installing-plugins-not-available-on-the-VCV-Library).

#### Connecting modules to grids

* Start VCVRack. Add a `white whale` and `grid 128` module to your patch.
* Right-click the `white whale` module and select your virtual grid from the list of devices. It should light up.
* If you have a hardware grid connected, right-click the module and select your hardware grid from the list. The virtual grid should go dark and your physical grid should light up.

#### Learning

* The offical docs for the hardware modules:
   * [teletype](https://monome.org/docs/teletype/) + [manual](https://monome.org/docs/teletype/manual) + [command cheatsheet](https://monome.org/docs/teletype/TT_commands_3.0.pdf)
   * [ansible](https://monome.org/docs/ansible/)
   * [white whale](https://monome.org/docs/whitewhale/)
   * [meadowphysics](https://monome.org/docs/meadowphysics/)
   * [earthsea](https://monome.org/docs/earthsea/)
* Video tutorials for the original "trilogy" hardware:
   * [white whale possibilities](https://vimeo.com/104881064)
   * [white whale tutorial part 1](https://vimeo.com/105368808)
   * [white whale tutorial part 2](https://vimeo.com/105368874)
   * [white whale tutorial part 3](https://vimeo.com/105408057)
   * [white whale tutorial part 4](https://vimeo.com/105408747)
   * [meadowphysics possibilities](https://vimeo.com/107582557)
   * [meadowphysics tutorial](https://vimeo.com/107586549)
   * [meadowphysics two](https://vimeo.com/146731772)
   * [earthsea introduction](https://vimeo.com/113231441)
* Tutorials, videos, and resources for the Teletype hardware:
   * [a user's guide to the wonderful world of teletype](https://llllllll.co/t/a-users-guide-to-the-wonderful-world-of-teletype/35971)
   * ["teletype talk" series by Joe Filbrun](https://www.youtube.com/watch?v=mMAhjRKrpZE&list=PLoxHBVkj2rip4Ce4kxdz_k7mK9Z8Wygo-)
   * [teletype videos by The Ghost Saboteur](https://www.youtube.com/playlist?list=PLMHhQKTYXU657VGx48aj-0rs_tjoz7-Eo)
   * [teletype & generative 201](https://www.youtube.com/watch?v=cVHhZkG-pck) from mcpm - [slides and code](https://docs.google.com/presentation/d/1NpNET1D4FlF4zljdo58_u29eLRYLV7yAbxGCsyR12hA/edit#slide=id.gf9647da6be_0_189)
   * [flash crash livecoding events](https://flashcrash.net/) for teletype in performance
* VCV Rack-specific tutorials:
   * [Teletype review and tutorial for beginners by Jakub Ciupinski](https://www.youtube.com/watch?v=AMldf2W0mUw)
   * [Teletype Microtutorials by Obakegaku](https://youtube.com/playlist?list=PLt9Y2vOdxouMOWfxDrgVIY0hMZvFCSBw7) and [patch files](https://patchstorage.com/author/obakegaku/)

### Why is this?

In order of importance, the initial goals of this project were/are:

* Provide an easier environment for developing, debugging, and testing new and improved firmware features for the monome Eurorack modules
* Allow users of the hardware modules to practice, experiment, and/or record while away from their systems
* Expose new users to the monome hardware/software ecosystem
* Accelerate development of completely new grid applications
* "Because it was there"

### How does this work?

The firmwares for the monome modules are written in C for the AVR32 platform. ([More details here](https://github.com/monome/libavr32).) In this project, these firmware repos are built into separate C shared libraries, together with stub I/O implementations for parts of the AVR32 API. The Rack plugin will load a new copy of this firmware library into memory for each module instance you place, so statics and globals work as expected within each copy of the module.

### How can I build the source myself?

See [DEVELOPING.md](DEVELOPING.md).

### Who did this?

The original hardware and firmware projects were initiated by [@tehn](https://github.com/tehn) at [monome](https://monome.org) with contributions from many members of the [lines community](https://llllllll.co). See the [individual submodule repositories](firmware) for more details. The VCVRack-specific code in this repository is a separate community effort, and again, no support or warranty is implied.

[Michael Dewberry](http://dewb.org) ([@dewb](https://github.com/Dewb)) wrote the virtual grid module, the hardware simulation layer, and the VCV module wrappers for white whale, meadowphysics, earthsea, and teletype.

Additional community contributions and feedback are very welcome! Discuss either in an [issue here](/../../issues), in the [lines thread](https://llllllll.co/t/monome-vcv-rack-ports-development-log/10337), or in [the thread on the VCV Rack Community Forum](https://community.vcvrack.com/t/monome-modules-beta-dev-log/3683).

### What's next?

See the [release plan](https://github.com/users/Dewb/projects/1) for the current thinking, but no promises.

## License

The original monome firmware is licensed under the GPL version 2. Panel graphics [incorporate elements](https://github.com/monome/teletype-hardware/blob/master/teletype-panel-graphic.pdf) of hardware panel PDFs licensed CC-BY-SA 3.0. 

The new code in this repository is also licensed under the GPL version 2.

The base64, oscpack, and serialosc libraries are licensed from their authors via GPL-compatible licenses according to the LICENSE file in each subfolder under [lib/](lib).
