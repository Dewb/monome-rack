
#### To build with the Rack SDK:

* Clone this repo.
   ```bash
   $ git clone https://github.com/Dewb/monome-rack
   ```
* Change into the `monome-rack` folder and clone the plugin's submodules with `git submodule update --init --recursive`
   ```bash
   $ cd monome-rack
   $ git submodule update --init --recursive
   ```
* Download the Rack SDK.
   ```bash
   $ curl -O https://vcvrack.com/downloads/Rack-SDK-1.1.6.zip
   $ unzip Rack-SDK-1.1.6.zip
   ```
* Build with `make install`.
   ```bash
   $ RACK_DIR=$(PWD)/Rack-SDK make install
   ```

#### To build with the complete VCV Rack source:

* Read the [VCVRack](https://github.com/VCVRack/Rack) build instructions for your platform and follow them carefully. Build the `v1` branch. Run and test Rack to make sure it works as expected.
   ```bash
   $ git clone -b v1 https://github.com/VCVRack/Rack
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
* Change into the `monome-rack` folder and clone the plugin's submodules with `git submodule update --init --recursive`
   ```bash
   $ cd monome-rack
   $ git submodule update --init --recursive
   ```
* Build with `make`, or open the `monome-rack` folder in Visual Studio Code and select `Tasks > Run Build Task`.
   ```bash
   $ RACK_DIR=$(PWD)/../.. make
   ```
