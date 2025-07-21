#include "interface_helper.h"

// Place contents of this folder in /src and add "mm_recomp_interface_helper" to mod.toml dependencies to build

START_BUTTON_POSITION_X_DECLARE
BUTTONS_ENABLED_DECLARE
START_BUTTON_TEXTURE_DECLARE
C_GLYPH_TEXTURES_DECLARE

RECOMP_CALLBACK("*", recomp_after_play_init) void after_play_init() {
    START_BUTTON_POSITION_X_REGISTER
    BUTTONS_ENABLED_REGISTER
    START_BUTTON_TEXTURE_REGISTER
    C_GLYPH_TEXTURES_REGISTER
}

extern TexturePtr gButtonBackgroundTex[];
int testIndex = 1;

RECOMP_CALLBACK(".", start_button_hook_init) void test_init(PlayState* play) {
    *pStartButtonPositionX += 1;

    (*pButtonsEnabled)[0] = false;
    (*pButtonsEnabled)[1] = false;
    (*pButtonsEnabled)[2] = false;
    (*pButtonsEnabled)[3] = false;

    *pStartButtonTexture = (u8*)gButtonBackgroundTex + ((32 * 32) * (2 + 1));
    
    (*pCGlyphTextures)[1] = (u8*)gButtonBackgroundTex + ((32 * 32) * (testIndex++ + 1));
    if (testIndex == 4) {
        testIndex = 1;
    }
}