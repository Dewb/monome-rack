# Credits

The original hardware and firmware projects were initiated by [@tehn](https://github.com/tehn) at [monome](https://monome.org) and grew with contributions from members of the [lines community](https://llllllll.co), including [@csboling](https://github.com/csboling), [@ngwese](https://github.com/ngwese), [@scanner-darkly](https://github.com/scanner-darkly), [@samdoshi](https://github.com/samdoshi), [@burnsauce](https://github.com/burnsauce), and many others. See the [individual upstream submodule repositories](https://github.com/Dewb/monome-rack/tree/main/firmware) for more details. 

The VCVRack-specific code is a separate community effort; the above parties should not be expected to support or warranty these ports or take any blame for its imperfections. [@dewb](https://github.com/Dewb) wrote the virtual grid module, the hardware simulation layer, and the VCV module wrappers and software UX for white whale, meadowphysics, earthsea, and teletype. Advice and encouragement from the [lines community](https://llllllll.co) and the adjacent Teletype Study Group Discord was instrumental.

## License

The firmware code for the hardware modules are licensed under the version 2 of the GPL. Panel graphics [incorporate elements](https://github.com/monome/teletype-hardware/blob/master/teletype-panel-graphic.pdf) of hardware panel PDFs licensed CC-BY-SA 3.0. 

Full source for the plugin is available at [https://github.com/Dewb/monome-rack](https://github.com/Dewb/monome-rack). The new code in this repository is also licensed under [version 2 of the GPL](https://github.com/Dewb/monome-rack/blob/main/LICENSE).



This project benefits from the inclusion of the following source libraries with GPL-compatible licenses:

* [base64](https://github.com/ReneNyffenegger/cpp-base64) by René Nyffenegger [License](https://github.com/Dewb/monome-rack/blob/main/lib/base64/LICENSE)
* [simple-svg](https://github.com/adishavit/simple-svg) by adishavit [License](https://github.com/Dewb/monome-rack/blob/main/lib/simple-svg/LICENSE)
* [oscpack](https://github.com/RossBencina/oscpack) by Ross Bencina [License](https://github.com/Dewb/monome-rack/blob/main/lib/oscpack/LICENSE)

Naturally, this project also couldn't exist without the [VCV Rack SDK](https://github.com/VCVRack/Rack) and the [many open-source libraries](https://github.com/vcvrack/rack#software-libraries) that it depends on.
