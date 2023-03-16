# Inputs

To mimic the hardware behavior, CV inputs are internally sampled to 12 bits of resolution. Trigger/gate inputs have a low threshold of 0.8 V and a high threshold of 2.21 V.

# Outputs

On all modules, CV outs are unipolar with a range of 0-10 V. TR outs produce a gate/trigger at 8 V, with pulse length dependent on the application. Like inputs, CV ouputs are produced by simulating 12-bit ADC conversion.

# Timing

...

# Sequencer Reset

...

# Polyphony

All of these modules closely follow their original hardware and only carry monophonic signals on each jack. However, in many situations the modules can be used to create polyphonic signals or sequences across multiple outputs. For polyphonic downstream patching, you can use VCV Fundamental Merge module to combine multiple CV or TR outs from a single module into a single polyphonic cable. (For example, Ansible CV 1-4 into one Merge module and TR 1-4 into another Merge module give you polyphonic CV and gate when using the Kria app.)