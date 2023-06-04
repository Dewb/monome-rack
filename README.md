monome-rack 
---

Read the manual here:
* https://dewb.github.io/monome-rack

monome-rack is a plugin for the [VCVRack open-source virtual modular synthesizer](https://github.com/VCVRack/Rack) that emulates (some of) the open-source Eurorack modules and control hardware designed and manufactured by [monome](https://monome.org). This is an unofficial community-driven port, made with permission, but no support guarantees, warranties, or suitability for purpose are provided by anyone.

<img width="90%" alt="monome modules and virtual grid in VCVRack" src="https://user-images.githubusercontent.com/712405/211141286-85785c64-74d3-46a0-a81d-241824a77178.png">

This plugin currently includes:
* [teletype](https://monome.org/docs/teletype/), a dynamic, musical, scriptable event triggering platform.
* [ansible](https://monome.org/docs/ansible/), a multi-mode sequencing and event-triggering module
* [white whale](https://monome.org/docs/whitewhale/), a probabilistic step sequencer
* [meadowphysics](https://monome.org/docs/meadowphysics/), an event sequencer for polyrhythms and rule-based evolving patterns
* [earthsea](https://monome.org/docs/earthsea/), a live keyboard that can sequence melodies and recall CV with shape memory gestures
* Support for [monome grid](https://monome.org/docs/grid/) and [monome arc](https://monome.org/docs/arc/) hardware controllers, both current editions and older models, plus virtual versions of the controllers within VCV Rack, in 64, 128, and 256-key flavors.
    
All of the modules can connect to either a virtual grid or a real hardware grid controller. ([Serialosc](https://monome.org/docs/setup/) is required to use real hardware, but no drivers are required for the virtual grids.) 

Through the virtual grid, all features of each module are accessible, but some features are awkward to use without multiple fingers on a real grid. [See the manual for tips on using virtual grids](https://dewb.github.io/monome-rack/modules/grids/).

## How do I use this?

To install the latest library release:

1. Visit the plugin's [page in the VCV Library](https://library.vcvrack.com/monome) and click **Add**.
2. Start VCV Rack and run **Library > Update All** to install the new modules.
3. Restart VCV Rack.
2. Optional: to use monome grid and arc hardware, make sure to [install serialosc](https://monome.org/docs/setup/).

### Connecting modules to grids

* Start VCVRack. Add a `white whale` and `grid 128` module to your patch.
* Right-click the `white whale` module and select your virtual grid from the list of devices. It should light up.
* If you have a hardware grid connected, right-click the module and select your hardware grid from the list. The virtual grid should go dark and your physical grid should light up.

### Deeping learning and getting help

See the [online manual](https://dewb.github.io/monome-rack), specifically the [Getting Help section](https://dewb.github.io/monome-rack/help/).

### Installing prerelease builds

For instructions on installing prerelease builds, see [DEVELOPING.md](DEVELOPING.md).

## How can I build the source myself?

See [DEVELOPING.md](DEVELOPING.md).

## Who did this? How is it licensed?

See the [Credits & License](https://dewb.github.io/monome-rack/general/credits/).

## What's next?

See the [release plan](https://github.com/users/Dewb/projects/1) for the current thinking, but no promises.

## Why does this exist?

In order of importance, the initial goals of this project were/are:

* Provide an easier environment for developing, debugging, and testing new and improved firmware features for the monome Eurorack modules
* Allow users of the hardware modules to practice, experiment, and/or record while away from their systems
* Expose new users to the monome hardware/software ecosystem
* Accelerate development of completely new grid applications
* "Because it was there"

## How does this work?

The firmwares for the monome modules are written in C for the AVR32 platform. ([More details here](https://github.com/monome/libavr32).) In this project, these firmware repos are built into separate C shared libraries, together with stub I/O implementations for parts of the AVR32 API. The Rack plugin will load a new copy of this firmware library into memory for each module instance you place, so statics and globals work as expected within each copy of the module.
