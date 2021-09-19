monome-rack — VCVRack plugin for monome hardware
---

### What is this?

This is a *PRERELEASE* plugin for the [VCVRack open-source virtual modular synthesizer](https://github.com/VCVRack/Rack) that implements (some of) the Eurorack modules and control hardware manufactured by [monome](https://monome.org). This is an unofficial community-driven port, and no support guarantees, warranty, or affiliation is implied from any organization mentioned in this document.

This plugin is still in development. [The extremely hypothetical release roadmap is here](../../projects/1). 

<img width="90%" alt="monome modules and virtual grid in VCVRack" src="https://user-images.githubusercontent.com/712405/33818500-4c54d158-de13-11e7-8a74-3b8b1fe8b21d.png">

This plugin currently includes:
* Virtual versions of the venerable [monome grid 64 and 128](https://monome.org/docs/grid/), a series of open, interactive grid instruments, in 8x8 and 16x8 versions.
* The [white whale](https://monome.org/docs/modular/whitewhale/) grid-enabled probabilistic step sequencer
   * A 16-step sequencer with a focus on live-manipulation and controlled variations
   * 4 trigger outs, 2 CV outs
   * Controlled by internal or external clock
* The [meadowphysics](https://monome.org/docs/modular/meadowphysics/) grid-enabled rhizomatic cascading counter
   * An event sequencer for polyrhythms and rule-based evolving patterns
   * 8 trigger outs
   * Controlled by internal or external clock
* The [earthsea](https://monome.org/docs/modular/earthsea/) grid-enabled shape-memory pattern instrument
   * A live keyboard that can sequence melodies and recall CV with gestures
   * 1 trigger out, 4 CV outs
   
All three of the modules can connect to either a virtual grid or a real hardware grid controller. ([Serialosc](https://monome.org/docs/setup/) is required to use real hardware, but no drivers are required for the virtual grids.) 

Through the virtual grid, all features of each module are accessible, but some features are awkward to use without multiple fingers on a real grid. Control-clicking (Linux/Windows) or Command-clicking (Mac OS) will allow you to "hold" keys to perform multi-press gestures.

### How do I use this?

Download a release for your platform from the [Releases page](../../releases) and place it in your `Rack\plugins-v1` folder.

More detailed instructions are available in the [Rack documentation on installing non-library plugins](https://vcvrack.com/manual/Installing#Installing-plugins-not-available-on-the-VCV-Library).

#### Connecting modules to grids

* Start VCVRack. Add a `white whale` and `grid 128` module to your patch.
* Right-click the `white whale` module and select your virtual grid from the list of devices. It should light up.
* If you have a hardware grid connected, right-click the module and select your hardware grid from the list. The virtual grid should go dark and your physical grid should light up.

#### Going deeper

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
* Allow users of the hardware modules to practice, experiment, and/or record while away from their systems
* Expose new users to the monome hardware/software ecosystem
* Accelerate development of completely new grid applications
* "Because it was there"

### How does this work?

The firmwares for the monome modules are written in C for the AVR32 platform. ([More details here](https://github.com/monome/libavr32).) In this project, these firmware repos are built into separate C shared libraries, together with stub I/O implementations for parts of the AVR32 API. The Rack plugin will load a new copy of this firmware library into memory for each module instance you place, so statics and globals work as expected within each copy of the module.

### How can I build the source myself?

See [DEVELOPING.md](DEVELOPING.md).

### Who did this?

Original hardware and firmware code in linked submodules is by [monome](monome.org) with contributions from the community at [lines](https://llllllll.co). The VCVRack-specific code in this repository is a separate effort, and again, no support or warranty is implied.

[Michael Dewberry](http://dewb.org) ([@dewb](https://github.com/Dewb)) wrote the virtual grid module, the hardware simulation layer, and the VCV module wrapper for white whale, meadowphysics, earthsea, and teletype.

Additional community contributions and feedback are very welcome! Discuss either in an [issue here](/../../issues), in the [lines thread](https://llllllll.co/t/white-whale-in-vcvrack/10337), or in [the thread on the VCV Rack Community Forum](https://community.vcvrack.com/t/monome-modules-thread/3683).

### What's next?

See the [release plan](../../projects/1).

## License

The original monome firmware is licensed under the GPL version 2. Panel graphics [incorporate elements](https://github.com/monome/teletype-hardware/blob/master/teletype-panel-graphic.pdf) of hardware panel PDFs licensed CC-BY-SA 3.0. 

The new code in this repository is also licensed under the GPL version 2.

The base64, oscpack, and serialosc libraries are licensed from their authors via GPL-compatible licenses according to the LICENSE file in each subfolder under lib/.
