
## To install prerelease builds:

Download a release for your platform from the [Releases page](../../releases) and place it in your `Rack2\plugins` folder.

More detailed instructions are available in the [Rack documentation on installing non-library plugins](https://vcvrack.com/manual/Installing#Installing-plugins-not-available-on-the-VCV-Library).

## To build the plugin using the Rack SDK:

* Clone this repo.
   ```bash
   $ git clone https://github.com/Dewb/monome-rack
   ```
* Change into the `monome-rack` folder and clone the plugin's submodules with `git submodule update --init --recursive`
   ```bash
   $ cd monome-rack
   $ git submodule update --init --recursive
   ```
* Download the latest Rack 2.x SDK.
   ```bash
   $ curl -O https://vcvrack.com/downloads/Rack-SDK-2.3.0.zip
   $ unzip Rack-SDK-2.3.0.zip
   ```

* Build dependencies.
   ```bash
   $ RACK_DIR=$(PWD)/Rack-SDK make dep
   ```

* Build with `make install`.
   ```bash
   $ RACK_DIR=$(PWD)/Rack-SDK make install
   ```

## To build the plugin using the complete VCV Rack source:

* Read the [VCVRack](https://github.com/VCVRack/Rack) build instructions for your platform and follow them carefully. Run and test Rack to make sure it works as expected.
   ```bash
   $ git clone -b v2 https://github.com/VCVRack/Rack
   $ cd Rack
   $ git submodule update --init --recursive
   $ make dep
   $ make
   $ make run
   ``` 
* Clone this repo into the `plugins` folder under VCVRack.
   ```bash
   $ cd plugins
   $ git clone https://github.com/Dewb/monome-rack
   ```
* Change into the `monome-rack` folder and clone the plugin's submodules with `git submodule update --init --recursive`, then `make dep` to build dependencies.
   ```bash
   $ cd monome-rack
   $ git submodule update --init --recursive
   $ make dep
   ```
* Build with `make`, or open the `monome-rack` folder in Visual Studio Code and select `Tasks > Run Build Task`.
   ```bash
   $ make
   ```

## Updating documentation

Prerequisites:
* Recent `pip` and `python` 3.x
* `mkdocs` and `mkdocs-terminal`. Install with:
   ```bash
   $ pip install -r docs/requirements.txt
   ```

Start a hot-reload server with `mkdocs serve`, and run `mkdocs build` to produce the static site.