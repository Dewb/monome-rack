# Virtual grids

![original prototype virtual grid in VCV Rack 0.5](../images/prototype.jpg)

# Sizes

Virtual grids come in 64 (8x8), 128 (16x8), and 256 (16x16) key flavors. Most modules and modes are designed for the 128-key version, though all will work with every size; some features may not be available or might not work exactly the same way on the other sizes.

# Limitations vs. hardware

The virtual grids are something of a compromise. They're never going to be as performable or tactile as a physical controller. 

Using all features of these grid-supporting modules relies on gestures intended to be performed with two hands. Unfortunately, VCV Rack doesn't currently support multi-touch, so with a mouse alone you can only press one key at a time.

However, using the mouse and computer keyboard together, we can approximate some multi-handed gestures.

# Holding keys

To compensate for only having one pointer finger instead of ten, you can **Ctrl-click** keys (or **Cmd-click** on Mac) to hold them down momentarily. You can hold multiple grid keys while you hold down **Ctrl** (or **Cmd**) and all the held grid keys will be released when you stop holding it.

This is handy for typical gestures like [setting the loop length on White Whale](http://monome.org/docs/whitewhale/#position--clock). **Ctrl-click** a key in row 2 to set the loop start, and then while still holding **Ctrl**, click another key in row 2 to set the end point.

![ctrl-clicking keys to set white whale loop length](../images/whitewhale-ctrl-click.webp){: }

# Locking keys

Sometimes you need to hold a key down for a longer period of time. **Ctrl-Shift-click** a grid key (**Cmd-Shift-click** on Mac) to "lock" it down until you click it again. If you lock multiple keys, you can release them all at once by hitting **Esc** while hovering over the grid, or selecting **Release Locked Keys** from the right-click menu.

Locked keys are indicated by a dot in the lower left corner. 

Locking a key allows you to use mode/settings pages, where you might need to hold a key down while pressing several other keys. For example, to enter [Edge Mode](http://monome.org/docs/earthsea/#edge) on [Earthsea](../modules/earthsea), **Ctrl-Shift-click** the 6th key in the first column to enter the mode, and then click the glyphs to change the gate method and time. Click the locked key again to unlock it and return to the main mode.

![ctrl-shift-clicking keys to lock earthsea glyph mode](../images/earthsea-ctrl-shift-click.webp){: }

# Combining gestures

Locking and holding keys can work together. For example, to adjust loop length in Kria, **Ctrl-Shift-click** the [Loop Modifier key](https://monome.org/docs/ansible/kria/#modifiers) in row 8 to edit loop lengths, then **Ctrl-click** the start and end of the loop in rows 1-4.

![ctrl-shift-clicking to lock kria loop modifier mode, then ctrl-clicking to set loop length](../images/kria-combined-gestures.webp){: style="border-right: 0.2em solid #bfbfbf; border-bottom: 0.1em solid #bfbfbf;" }

# Theme and protocol options

...

