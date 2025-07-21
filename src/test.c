#include "modding.h"
#include "global.h"

RECOMP_IMPORT("*", int recomp_printf(const char* fmt, ...));
RECOMP_IMPORT(".", void mButtonsEnabled_Register(bool (**pointer)[4]));
RECOMP_IMPORT(".", void mStartButtonPositionX_Register(s16 (**pointer)));
RECOMP_IMPORT(".", void mStartButtonTexture_Register(TexturePtr (**pointer)));
RECOMP_IMPORT(".", void mCGlyphTextures_Register(TexturePtr (**pointer)[3]));

s16* pStartButtonPositionX;
bool (*pButtonsEnabled)[4];
TexturePtr (*pStartButtonTexture);
TexturePtr (*pCGlyphTextures)[3];

RECOMP_CALLBACK("*", recomp_after_play_init) void after_play_init() {
    mStartButtonPositionX_Register(&pStartButtonPositionX);
    mButtonsEnabled_Register(&pButtonsEnabled);
    mStartButtonTexture_Register(&pStartButtonTexture);
    mCGlyphTextures_Register(&pCGlyphTextures);
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