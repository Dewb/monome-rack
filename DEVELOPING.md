
## Installing prerelease builds

Download a release for your platform from the [Releases page](../../releases) and place the .vcvplugin file into the plugins subfolder inside your Rack 2 user folder. The user folder on your OS can be opened from the Rack menu bar at **Help** > **Open user folder**. The plugins subfolder will be named `plugins-<os>-<cpu>`

More detailed instructions for installing non-library plugins are available in the [Rack manual](https://vcvrack.com/manual/Installing#Installing-plugins-not-available-on-the-VCV-Library).

## Building the plugin using the Rack SDK

1. Set up a local [Rack development environment](https://vcvrack.com/manual/Building) as described in the Rack manual.
2. Clone this repo.
   ```bash
   $ git clone https://github.com/Dewb/monome-rack
   ```
3. Change into the `monome-rack` folder and clone the plugin's submodules with `git submodule update --init --recursive`
   ```bash
   $ cd monome-rack
   $ git submodule update --init --recursive
   ```
4. Download the latest Rack 2.x SDK. (The URL will depend on your OS and CPU architecture, see https://vcvrack.com/downloads).
   ```bash
   $ curl -O https://vcvrack.com/downloads/Rack-SDK-2.4.0-mac-arm64.zip
   $ unzip Rack-SDK-2.5.0-mac-arm64.zip
   $ rm Rack-SDK-2.5.0-mac-arm64.zip
   ```
5. Build dependencies with `make dep`.
   ```bash
   $ RACK_DIR=$(PWD)/Rack-SDK make dep
   ```
6. Run `make install` to build the plugin and copy it into the Rack plugins folder. (Alternately, open the `monome-rack` folder in Visual Studio Code and select `Tasks > Run Build Task`.)
   ```bash
   $ RACK_DIR=$(PWD)/Rack-SDK make -j4 install
   ```

## Building the plugin using the complete VCV Rack source

1. Read the [VCVRack](https://github.com/VCVRack/Rack) build instructions for your platform and follow them carefully. Run and test Rack to make sure it works as expected.
   ```bash
   $ git clone -b v2 https://github.com/VCVRack/Rack
   $ cd Rack
   $ git submodule update --init --recursive
   $ make dep
   $ make
   $ make run
   ``` 
2. Clone this repo into the `plugins` folder under VCVRack.
   ```bash
   $ cd plugins
   $ git clone https://github.com/Dewb/monome-rack
   ```
3. Change into the `monome-rack` folder and clone the plugin's submodules with `git submodule update --init --recursive`, then `make dep` to build dependencies.
   ```bash
   $ cd monome-rack
   $ git submodule update --init --recursive
   $ make dep
   ```
4. Build with `make`, or open the `monome-rack` folder in Visual Studio Code and select `Tasks > Run Build Task`.
   ```bash
   $ make -j4
   ```

## Updating documentation

Prerequisites:
* Recent `pip` and `python` 3.x
* `mkdocs` and `mkdocs-terminal`. Install with:
   ```bash
   $ pip install -r docs/requirements.txt
   ```

Start a hot-reload server with `mkdocs serve`, and run `mkdocs build` to produce the static site.

## Using monome-rack as a development environment for module firmware

This plugin can be used to accelerate firmware development for the hardware. The cycle of rebuilding the plugin and restarting Rack is faster than reflashing hardware, and desktop software debuggers are easier to set up than an in-circuit debugger.

First, some caveats: modifying the firmware can't change anything about the Rack "virtual hardware"; it will have the same panel, with the same inputs, outputs, and controls. If you want to making something new, pick as a starting point the module that best aligns with the I/O needs of your new idea. (The name of the firmware determines which module the firmware will be available for, and therefore which panel and I/O will be used, so when you create the new submodule, make sure your submodule folder name starts with the name of the base module.)

Similarly, if you want to change code that interacts directly with the physical hardware at a low level, like USB device detection or ADC/DAC timing, that code may not be executed in Rack. You'll have to skip to the last step and build and test directly on the hardware. 

Finally, keep in mind that a desktop computer has more resources than the AVR32 CPU inside each module. Memory is quite limited, and each module has limited time to compute its tasks inbetween event ticks. Taking too long on an operation risks delaying the next event, potentially throwing off the timing of sequences, or making input responses feel sluggish. Not everything that works on a desktop computer will easily translate to the hardware without further optimization. (It can be helpful to set these concerns aside during early development and brainstorming, of course -- first figure out if your idea works the way you want it to, and only then work on making it efficient.)

Let's walk through setting up a development environment for one of the modules. This example will use Teletype as it's the most actively developed firmware.

1. First, make sure you can build the monome-rack plugin using the instructions in either [Building the plugin using the Rack SDK](#building-the-plugin-using-the-rack-sdk) or [Building the plugin using the complete VCV Rack source](#building-the-plugin-using-the-complete-vcv-rack-source) above.
2. Find the GitHub URL and branch name for the firmware you want to modify. Right now, only Teletype is fully "Rack ready" in the upstream repository; the others need Rack-specific branches off forks.
    | module        | repository url                        | branch     |
    | ------------- | ------------------------------------- | ---------- |
    | ansible       | https://github.com/Dewb/ansible       | vcvrack    |
    | earthsea      | https://github.com/Dewb/earthsea      | vcvrack    |
    | meadowphysics | https://github.com/Dewb/meadowphysics | vcvrack    | 
    | teletype      | https://github.com/monome/teletype    | main       |
    | whitewhale    | https://github.com/Dewb/whitewhale    | vcvrack_pr |
3. Optional: Sign up for a [GitHub](https://github.com) account if you don't already have one, and use the "Fork" button on one of the repository pages above corresponding to the module you want to modify. On the subsequent page, **uncheck** the "Copy the main branch only" checkbox, so you have access to the non-main branches in your fork (necessary for any module besides teletype.)
    * Note: If you don't do this, you can run the following commands with the URL and branch listed above directly, but it will be more complicated to share your work with others later.
5. Use the `git submodule` command to create a new firmware submodule inside the `firmware` folder. Let's say we want to create a new development version of the teletype firmware and call it `teletype-dev` within the Rack environment.
    ```bash
    $ cd monome-rack
    $ cd firmware
    $ git submodule add -b main https://github.com/<your user name>/teletype teletype-dev
    ```
6. Run `git submodule update` to fetch the submodule children of the new submodule.
    ```bash
    $ git submodule update --init --recursive
    ```
7. Now we need to modify the plugin build process to include `teletype-dev` in our list of firmware binaries to build and add to the plugin. Edit `Makefile` in the monome-rack root folder and under the `firmware-build:` section, add the line:
    ```
    cd firmware && $(MAKE) -f teletype.mk TARGET_NAME=teletype-dev
    ```
   Make sure this line is indented with a single tab character, like the other lines in the section.
8. Rebuild the plugin using `make install` or the Visual Studio Code **Run Build Task...** command, as in step 1.
9. Run Rack and place a Teletype module. You should be able to see `teletype-dev` as one of the choices in the **Firmware Tools** > **Switch Firmware** right-click menu. Switch to it! You're now using the code from the new submodule folder you created in step 3.
10. Let's make some changes to the code. Close Rack and open `firmware/teletype-dev/module/live_mode.c` in your favorite editor. Go to line 771 and change the string `"TELETYPE "` to something else, like `"HELLO "`. Leave the space at the end of the string.
11. Rebuild the plugin again as in step 6.
12. Run Rack again, and now any Teletype modules in your patch running the `teletype-dev` firmware should say **HELLO** on the startup screen instead of **TELETYPE**.
13. Now you can make some more substantial changes. Fix a bug, add a new feature, or erase everything and create a completely new module. You can also repeat steps 4-7 more than once if you want to pursue multiple ideas in parallel; just make sure you give each new submodule folder a unique name.
    * Note: if your goal is to create new behavior for the module from scratch, you'll need to preserve the `initialize_module()` and `check_events()` functions, but most everything else is fair game. You'll need to use the `DECLARE_VRAM` and `DECLARE_NVRAM` macros on your key data structures to have them preserved in the Rack patch. Compare the `whitewhale` and `whitewhale-kria` submodules to see and example of two different firmware for the same module. 
14. When you have made something interesting and want to share it, you'll need to commit back to your firmware fork. It's probably a good idea to first create a branch:
    ```bash
    $ cd firmware/teletype-dev
    $ git checkout -b my_new_feature
    ```
15. Now push that branch to your fork:
    ```bash
    $ git push -u origin my_new_feature
    ```
16. Share your work! Note that this will *not* create any commits in your local copy of the monome-rack repo. This is okay, as you don't need to commit the changes to Rack to add your development firmware. You can share the firmware binaries from the `res` folder to other people and they won't have to build anything. Alternately, they can add your firmware to their build environment themselves by following steps 4-6, except instead of using the normal firmware URL and branch, they'll use your URL and branch in the `git submodule add` command:
    ```bash
    $ git submodule add -b my_new_feature https://github.com/<your user name>/teletype teletype-dev
    ```
17. Finally, once your new fix or feature is tested and working inside Rack, you can try building it for the hardware. The hardware build process uses a `Makefile` *inside* the specific firmware subfolder, instead of the Rack makefiles in the root of the `firmware/` folder. Building with these Makefiles requires [the avr32 toolchain](https://github.com/monome/avr32-toolchain) to be installed and in your path, a potentially complex process. However, if you have Docker or Rancher Desktop you can use a preconfigured image to make this easy.
    ```bash
    $ cd firmware/teletype-dev
    $ nerdctl run -v $(pwd):/target -t dewb/monome-build 
    ```
    See [the monome-build image README](https://github.com/Dewb/monome-build/blob/master/README.md) for more background on building with the image.
    * Note: The teletype Makefile runs git commands, but the Rack submodule structure moves the .git contents to the plugin root folder and puts it out of scope of the docker image. For now, to make the teletype build work, you'll need to comment out the last two lines of the Makefile, like so:
        ```make
        # Add the git commit id to a file for use when printing out the version
        #../module/gitversion.c: $(GIT_DIR)/HEAD $(GIT_DIR)/index
        #	echo "const char *git_version = \"$(shell cut -d '-' -f 1 ...
