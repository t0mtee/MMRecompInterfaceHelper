# Majora's Mask: Recompiled Interface Helper

This is a library mod that exposes more data inside interface functions so mods can change interface drawing functionality in a more specific and simple manner.

## Usage

1. Download `interface_helper.h` from the `example` folder in this repo.
2. Place that header in your mod's `src` folder.
3. Add `#include "interface_helper.h"` to the top of your source file.
4. Scan the function patches in this repo and find the variables you want to change and then use their respective DECLARE and REGISTER macros in your source file.
- The DECLARE macro must be placed outside of any scope.
- The REGISTER macro should be ran once after the game has initalised, for example in a `recomp_after_play_init` callback.
5. Modify that variable by accessing it with the declared pointer - the pointer's name will be the same as the variable but with a 'p' instead of an 'm' prefix.