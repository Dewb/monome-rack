# Inputs

 Trigger/gate inputs have a low threshold of 0.8 V and a high threshold of 2.21 V. CV inputs respond to a 0-10 V range. To mimic the hardware behavior, CV inputs are internally sampled to 12 bits of resolution.

# Outputs

On all modules, CV outs are unipolar with a range of 0-10 V. TR outs produce a gate/trigger at 8 V, with pulse length dependent on the application. Like inputs, CV ouputs are produced by simulating 12-bit DAC conversion. In order to keep the average error introduced by the 12-bit DAC simulation, outputs will have a small and harmless offset at 0V.

# Timing

All of these modules produce control-rate modulation signals. Downsampling is enabled by default to save CPU. The amount of downsampling can be changed on a module-by-module basis by right-clicking the module and choosing **Firmware Tools > Input Rate** or **Output Rate**, ranging from *1x* (no downsampling, audio rate) to **/16** (the module ticks only every 16 samples.)

There's generally no benefit to reducing the downsampling and running at audio rate. Most modules process their internal event loops at much less than audio rate regardless of the downsampling setting. The one exception is Teletype trigger inputs will be responded to on the sample they are triggered, so Teletype can be used for rudimentary audio synthesis if you trigger it at audio rates.

# Sequencer Reset

The [VCV Rack voltage standards for sequencer timing](https://vcvrack.com/manual/VoltageStandards#Timing) describe the challenges in implementing a reset input when the reset and clock inputs might arrive on different samples. Ansible is the only module with a reset input, and rather than the Rack suggested fix, it implements the alternate "Nord reset protocol" strategy, where only clock triggers ever advance the clock, and a low-high transition on the reset input causes the sequence to reset on the next clock step. If a patch does not produce the expected reset behavior due to different propagation times on the clock and reset input, add logic delays to make sure your reset signal arrives *before* the clock signal.

# Polyphony

All modules only carry monophonic signals on each jack, like their physical counterparts. If a polyphonic Rack cable is connected to an input, only the first channel will be used.

However, in many modes the modules can be used to create polyphonic signals and sequences across several outputs. For polyphonic downstream patching, you can use the [VCV Merge](https://vcvrack.com/Fundamental#Split) module to combine multiple CV or TR outs from a single module into a single polyphonic cable. For example, when using the Kria app on Ansible, patching CV 1-4 into one Merge module and TR 1-4 into another Merge module would give you polyphonic CV and gate signals to control polyphonic VCOs and VCAs.