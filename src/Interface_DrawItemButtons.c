#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

typedef enum {
    /* 0 */ PICTO_BOX_STATE_OFF,         // Not using the pictograph
    /* 1 */ PICTO_BOX_STATE_LENS,        // Looking through the lens of the pictograph
    /* 2 */ PICTO_BOX_STATE_SETUP_PHOTO, // Looking at the photo currently taken
    /* 3 */ PICTO_BOX_STATE_PHOTO
} PictoBoxState;

extern TexturePtr gTatlCUpENGTex[];
extern TexturePtr gTatlCUpGERTex[];
extern TexturePtr gTatlCUpFRATex[];
extern TexturePtr gTatlCUpESPTex[];
extern TexturePtr gButtonBackgroundTex[];
extern s16 sPictoState;
extern u16 sCUpInvisible;
extern u16 sCUpTimer;
extern Gfx* Gfx_DrawTexRectIA8_DropShadow(Gfx* gfx, TexturePtr texture, s16 textureWidth, s16 textureHeight, s16 rectLeft,
                                   s16 rectTop, s16 rectWidth, s16 rectHeight, u16 dsdx, u16 dtdy, s16 r, s16 g, s16 b,
                                   s16 a);

RECOMP_DECLARE_EVENT(button_hook_init(PlayState* play, EquipSlot button))
bool mButtonsEnabled[4] = {
    true,                               // EQUIP_SLOT_B
    true,                               // EQUIP_SLOT_C_LEFT
    true,                               // EQUIP_SLOT_C_DOWN
    true                                // EQUIP_SLOT_C_RIGHT
};
TexturePtr mButtonTextures[4] = {
    gButtonBackgroundTex,               // EQUIP_SLOT_B
    gButtonBackgroundTex,               // EQUIP_SLOT_C_LEFT
    gButtonBackgroundTex,               // EQUIP_SLOT_C_DOWN
    gButtonBackgroundTex                // EQUIP_SLOT_C_RIGHT
};
s16 mButtonTexturesWidth[4] = {
    32,                                 // EQUIP_SLOT_B
    32,                                 // EQUIP_SLOT_C_LEFT
    32,                                 // EQUIP_SLOT_C_DOWN
    32                                  // EQUIP_SLOT_C_RIGHT
};
s16 mButtonTexturesHeight[4] = {
    32,                                 // EQUIP_SLOT_B
    32,                                 // EQUIP_SLOT_C_LEFT
    32,                                 // EQUIP_SLOT_C_DOWN
    32                                  // EQUIP_SLOT_C_RIGHT
};
s16 mButtonPositionsX[4] = {
    167,                                // EQUIP_SLOT_B
    227,                                // EQUIP_SLOT_C_LEFT
    249,                                // EQUIP_SLOT_C_DOWN
    271                                 // EQUIP_SLOT_C_RIGHT
};
s16 mButtonPositionsY[4] = {
    17,                                 // EQUIP_SLOT_B
    18,                                 // EQUIP_SLOT_C_LEFT
    34,                                 // EQUIP_SLOT_C_DOWN
    18                                  // EQUIP_SLOT_C_RIGHT
};
s16 mButtonRectSizesX[4] = {
    29,                                 // EQUIP_SLOT_B
    27,                                 // EQUIP_SLOT_C_LEFT
    27,                                 // EQUIP_SLOT_C_DOWN
    27                                  // EQUIP_SLOT_C_RIGHT
};
s16 mButtonRectSizesY[4] = {
    29,                                 // EQUIP_SLOT_B
    27,                                 // EQUIP_SLOT_C_LEFT
    27,                                 // EQUIP_SLOT_C_DOWN
    27                                  // EQUIP_SLOT_C_RIGHT
};
s16 mButtonScalesX[4] = {
    ((s32)(1.1230469f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_B
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_C_LEFT
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_C_DOWN
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2  // EQUIP_SLOT_C_RIGHT
};
s16 mButtonScalesY[4] = {
    ((s32)(1.1230469f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_B
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_C_LEFT
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_C_DOWN
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2  // EQUIP_SLOT_C_RIGHT
};
s16 mButtonColours[4][3] = {
    {100, 255, 120},                    // EQUIP_SLOT_B
    {255, 240, 0},                      // EQUIP_SLOT_C_LEFT
    {255, 240, 0},                      // EQUIP_SLOT_C_DOWN
    {255, 240, 0}                       // EQUIP_SLOT_C_RIGHT
};
s16 mButtonAlphas[4] = {
    255,                                // EQUIP_SLOT_B
    255,                                // EQUIP_SLOT_C_LEFT
    255,                                // EQUIP_SLOT_C_DOWN
    255                                 // EQUIP_SLOT_C_RIGHT
};
RECOMP_DECLARE_EVENT(button_hook_return(PlayState* play, EquipSlot button))

bool mStartForceEnabled = false;

RECOMP_DECLARE_EVENT(start_button_hook_init(PlayState* play))
bool mStartButtonEnabled = true;
TexturePtr mStartButtonTexture = gButtonBackgroundTex;
s16 mStartButtonTextureWidth = 32;
s16 mStartButtonTextureHeight = 32;
s16 mStartButtonPositionX = 136;
s16 mStartButtonPositionY = 17;
s16 mStartButtonRectSizeX = 22;
s16 mStartButtonRectSizeY = 22;
u16 mStartButtonScaleX = (s32)(1.4277344f * (1 << 10));
u16 mStartButtonScaleY = (s32)(1.4277344f * (1 << 10));
s16 mStartButtonColour[3] = {255, 130, 60};
RECOMP_DECLARE_EVENT(start_button_hook_return(PlayState* play))

RECOMP_DECLARE_EVENT(start_label_hook_init(PlayState* play))
bool mStartLabelEnabled = true;
int mStartLabelPrimColour[3] = {255, 255, 255};
int mStartLabelEnvColour[4] = {0, 0, 0, 0};
TexturePtr mStartLabelTexture = NULL;
int mStartLabelTextureWidth = 48;
int mStartLabelTextureHeight = 16;
int mStartLabelPositionX = 126 << 2;
int mStartLabelPositionY = 21 << 2;
int mStartLabelRectSizeX = 55 << 2;
int mStartLabelRectSizeY = 18 << 2;
int mStartLabelScaleX = (s32)(1.16211f * (1 << 10));
int mStartLabelScaleY = (s32)(1.16211f * (1 << 10));
RECOMP_DECLARE_EVENT(start_label_hook_return(PlayState* play))

RECOMP_DECLARE_EVENT(c_up_button_hook_init(PlayState* play, s16* alpha))
bool mCUpButtonForceEnabled = false;
bool mCUpButtonEnabled = true;
TexturePtr mCUpButtonTexture = gButtonBackgroundTex;
int mCUpButtonTextureWidth = 32;
int mCUpButtonTextureHeight = 32;
s16 mCUpButtonPositionX = 254;
s16 mCUpButtonPositionY = 16;
s16 mCUpButtonRectSizeX = 16;
s16 mCUpButtonRectSizeY = 16;
u16 mCUpButtonScaleX = 2 << 10;
u16 mCUpButtonScaleY = 2 << 10;
s16 mCUpButtonColours[3] = {255, 240, 0};
RECOMP_DECLARE_EVENT(c_up_button_hook_return(PlayState* play, s16* alpha))

RECOMP_DECLARE_EVENT(c_up_label_hook_init(PlayState* play, s16* alpha))
bool mCUpLabelEnabled = true;
int mCUpLabelPrimColour[3] = {255, 255, 255};
int mCUpLabelEnvColour[4] = {0, 0, 0, 0};
TexturePtr mCUpLabelTextures[LANGUAGE_MAX] = {
    gTatlCUpENGTex, // LANGUAGE_JPN
    gTatlCUpENGTex, // LANGUAGE_ENG
    gTatlCUpGERTex, // LANGUAGE_GER
    gTatlCUpFRATex, // LANGUAGE_FRE
    gTatlCUpESPTex, // LANGUAGE_SPA
};
int mCUpLabelTextureWidths[LANGUAGE_MAX] = {
    32,             // LANGUAGE_JPN
    32,             // LANGUAGE_ENG
    32,             // LANGUAGE_GER
    32,             // LANGUAGE_FRE
    32,             // LANGUAGE_SPA
};
int mCUpLabelTextureHeights[LANGUAGE_MAX] = {
    12,             // LANGUAGE_JPN
    12,             // LANGUAGE_ENG
    12,             // LANGUAGE_GER
    12,             // LANGUAGE_FRE
    12,             // LANGUAGE_SPA
};
int mCUpLabelPositionX = 247 << 2;
int mCUpLabelPositionY = 18 << 2;
int mCUpLabelRectSizeX = 32 << 2;
int mCUpLabelRectSizeY = 12 << 2;
int mCUpLabelScaleX = 1 << 10;
int mCUpLabelScaleY = 1 << 10;
RECOMP_DECLARE_EVENT(c_up_label_hook_return(PlayState* play, s16* alpha))

RECOMP_DECLARE_EVENT(c_glyph_hook_init(PlayState* play))
bool mCGlyphsEnabled[3] = {
    true,                               // EQUIP_SLOT_C_LEFT
    true,                               // EQUIP_SLOT_C_DOWN
    true                                // EQUIP_SLOT_C_RIGHT
};
TexturePtr mCGlyphTextures[3] = {
    (u8*)gButtonBackgroundTex + ((32 * 32) * (1 + 1)),
    (u8*)gButtonBackgroundTex + ((32 * 32) * (2 + 1)),
    (u8*)gButtonBackgroundTex + ((32 * 32) * (3 + 1))
};
s16 mCGlyphTextureWidths[3] = {
    32,
    32,
    32
};
s16 mCGlyphTextureHeights[3] = {
    32,
    32,
    32
};
s16 mCGlyphPositionsX[3] = {
    227,                                // EQUIP_SLOT_C_LEFT
    249,                                // EQUIP_SLOT_C_DOWN
    271                                 // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphPositionsY[3] = {
    18,                                 // EQUIP_SLOT_C_LEFT
    34,                                 // EQUIP_SLOT_C_DOWN
    18                                  // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphRectSizesX[3] = {
    27,                                 // EQUIP_SLOT_C_LEFT
    27,                                 // EQUIP_SLOT_C_DOWN
    27                                  // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphRectSizesY[3] = {
    27,                                 // EQUIP_SLOT_C_LEFT
    27,                                 // EQUIP_SLOT_C_DOWN
    27                                  // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphScalesX[3] = {
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_C_LEFT
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_C_DOWN
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2  // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphScalesY[3] = {
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_C_LEFT
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2, // EQUIP_SLOT_C_DOWN
    ((s32)(1.2109375f * (1 << 10)) >> 1) * 2  // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphColours[3][3] = {
    {255, 240, 0},                      // EQUIP_SLOT_C_LEFT
    {255, 240, 0},                      // EQUIP_SLOT_C_DOWN
    {255, 240, 0}                       // EQUIP_SLOT_C_RIGHT
};
RECOMP_DECLARE_EVENT(c_glyph_hook_return(PlayState* play))

RECOMP_HOOK("Interface_DrawItemButtons") void Interface_DrawItemButtons_Init(PlayState* play) {
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    
    mButtonAlphas[0] = interfaceCtx->bAlpha;
    mButtonAlphas[1] = interfaceCtx->cLeftAlpha;
    mButtonAlphas[2] = interfaceCtx->cDownAlpha;
    mButtonAlphas[3] = interfaceCtx->cRightAlpha;
}

RECOMP_PATCH void Interface_DrawItemButtons(PlayState* play) {
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    PauseContext* pauseCtx = &play->pauseCtx;
    s16 temp; // Used as both an alpha value and a button index
    
    OPEN_DISPS(play->state.gfxCtx);
    
    gDPPipeSync(OVERLAY_DISP++);
    gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    // Fix green ammo (and potentially more if elements are disabled) bug described in Interface_DrawAmmoCount
    gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, 255);
    
    // B, C-Left, C-Down, C-Right
    for (temp = EQUIP_SLOT_B; temp <= EQUIP_SLOT_C_RIGHT; temp++) {
        if (mButtonsEnabled[temp]) {
            button_hook_init(play, temp);
            
            OVERLAY_DISP = Gfx_DrawTexRectIA8_DropShadow(
                OVERLAY_DISP, mButtonTextures[temp], mButtonTexturesWidth[temp], mButtonTexturesHeight[temp],
                mButtonPositionsX[temp], mButtonPositionsY[temp],
                mButtonRectSizesX[temp], mButtonRectSizesY[temp],
                mButtonScalesX[temp], mButtonScalesY[temp],
                mButtonColours[temp][0], mButtonColours[temp][1], mButtonColours[temp][2],
                mButtonAlphas[temp]);
            
            button_hook_return(play, temp);
        }
    }

    if (mStartForceEnabled || (!IS_PAUSE_STATE_GAMEOVER(pauseCtx) && (IS_PAUSED(pauseCtx)))) {
        // Start Button
        
        start_button_hook_init(play);
        
        if (mStartButtonEnabled) {
            OVERLAY_DISP =
                Gfx_DrawTexRectIA8_DropShadow(
                    OVERLAY_DISP, mStartButtonTexture, mStartButtonTextureWidth, mStartButtonTextureHeight,
                    mStartButtonPositionX, mStartButtonPositionY,
                    mStartButtonRectSizeX, mStartButtonRectSizeY,
                    mStartButtonScaleX, mStartButtonScaleY,
                    mStartButtonColour[0], mStartButtonColour[1], mStartButtonColour[2],
                    interfaceCtx->startAlpha);
        }

        start_button_hook_return(play);
        
        // Start Label

        start_label_hook_init(play);
        
        if (mStartLabelEnabled) {
            gDPPipeSync(OVERLAY_DISP++);
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0,
                mStartLabelPrimColour[0], mStartLabelPrimColour[1], mStartLabelPrimColour[2], interfaceCtx->startAlpha);
            gDPSetEnvColor(OVERLAY_DISP++, mStartLabelEnvColour[0], mStartLabelEnvColour[1], mStartLabelEnvColour[2], mStartLabelEnvColour[3]);
            gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
            if (mStartLabelTexture == NULL) {
                gDPLoadTextureBlock_4b(OVERLAY_DISP++, interfaceCtx->doActionSegment + DO_ACTION_OFFSET_START, G_IM_FMT_IA,
                    mStartLabelTextureWidth, mStartLabelTextureHeight, 0, G_TX_NOMIRROR | G_TX_WRAP,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            } else {
                gDPLoadTextureBlock_4b(OVERLAY_DISP++, mStartLabelTexture, G_IM_FMT_IA,
                    mStartLabelTextureWidth, mStartLabelTextureHeight, 0, G_TX_NOMIRROR | G_TX_WRAP,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            }
            gSPTextureRectangle(OVERLAY_DISP++, mStartLabelPositionX, mStartLabelPositionY,
                mStartLabelPositionX + mStartLabelRectSizeX, mStartLabelPositionY + mStartLabelRectSizeY,
                G_TX_RENDERTILE, 0, 0,
                mStartLabelScaleX, mStartLabelScaleY);
        }

        start_label_hook_return(play);
    }

    if (mCUpButtonForceEnabled || (interfaceCtx->tatlCalling && !IS_PAUSED(pauseCtx) && (play->csCtx.state == CS_STATE_IDLE) &&
        (sPictoState == PICTO_BOX_STATE_OFF))) {
        if (sCUpInvisible == 0) {
            // C-Up Button Texture, Color
            gDPPipeSync(OVERLAY_DISP++);

            if ((gSaveContext.hudVisibility == HUD_VISIBILITY_NONE) ||
                (gSaveContext.hudVisibility == HUD_VISIBILITY_NONE_ALT) ||
                (gSaveContext.hudVisibility == HUD_VISIBILITY_A_HEARTS_MAGIC_WITH_OVERWRITE) ||
                ((&play->msgCtx)->msgMode != MSGMODE_NONE)) {
                temp = 0;
            } else if (GET_PLAYER(play)->stateFlags1 & PLAYER_STATE1_200000) {
                temp = 70;
            } else {
                temp = interfaceCtx->aAlpha;
            }

            c_up_button_hook_init(play, &temp);
            
            if (mCUpButtonEnabled) {
                OVERLAY_DISP = Gfx_DrawTexRectIA8_DropShadow(
                    OVERLAY_DISP, mCUpButtonTexture, mCUpButtonTextureWidth, mCUpButtonTextureHeight,
                    mCUpButtonPositionX, mCUpButtonPositionY,
                    mCUpButtonRectSizeX, mCUpButtonRectSizeY,
                    mCUpButtonScaleX, mCUpButtonScaleY,
                    mCUpButtonColours[0], mCUpButtonColours[1], mCUpButtonColours[2], temp);
            }

            // C-Up Label (Tatl Text)
            if (mCUpLabelEnabled) {
                gDPPipeSync(OVERLAY_DISP++);
                gDPSetPrimColor(OVERLAY_DISP++, 0, 0, mCUpLabelPrimColour[0], mCUpLabelPrimColour[1], mCUpLabelPrimColour[2], temp);
                gDPSetEnvColor(OVERLAY_DISP++, mCUpLabelEnvColour[0], mCUpLabelEnvColour[1], mCUpLabelEnvColour[2], mCUpLabelEnvColour[3]);
                gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                    PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
                gDPLoadTextureBlock_4b(OVERLAY_DISP++, mCUpLabelTextures[gSaveContext.options.language], G_IM_FMT_IA,
                    mCUpLabelTextureWidths[gSaveContext.options.language], mCUpLabelTextureHeights[gSaveContext.options.language],
                    0, G_TX_NOMIRROR | G_TX_WRAP | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_WRAP | G_TX_CLAMP, G_TX_NOMASK,
                    G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(OVERLAY_DISP++, mCUpLabelPositionX, mCUpLabelPositionY,
                    mCUpLabelPositionX + mCUpLabelRectSizeX, mCUpLabelPositionY  + mCUpLabelRectSizeY, G_TX_RENDERTILE,
                    0, 0, mCUpLabelScaleX, mCUpLabelScaleY);
            }
            
            c_up_button_hook_return(play, &temp);
        }

        sCUpTimer--;
        if (sCUpTimer == 0) {
            sCUpInvisible ^= 1;
            sCUpTimer = 10;
        }
    }

    gDPPipeSync(OVERLAY_DISP++);

    // Empty C Button Arrows
    for (temp = EQUIP_SLOT_C_LEFT; temp <= EQUIP_SLOT_C_RIGHT; temp++) {
        int glyphTemp = temp - 1;
        if (mCGlyphsEnabled[glyphTemp] && GET_CUR_FORM_BTN_ITEM(temp) > 0xF0) {
            c_glyph_hook_init(play);
            
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0,
                mCGlyphColours[glyphTemp][0], mCGlyphColours[glyphTemp][1], mCGlyphColours[glyphTemp][2],
                mButtonAlphas[temp]);
            OVERLAY_DISP =
                Gfx_DrawTexRectIA8(
                    OVERLAY_DISP, mCGlyphTextures[glyphTemp], mCGlyphTextureWidths[glyphTemp], mCGlyphTextureHeights[glyphTemp],
                        mCGlyphPositionsX[glyphTemp], mCGlyphPositionsY[glyphTemp],
                        mCGlyphRectSizesX[glyphTemp], mCGlyphRectSizesY[glyphTemp],
                        mCGlyphScalesX[glyphTemp], mCGlyphScalesY[glyphTemp]);
            
            c_glyph_hook_return(play);
        }
    }
    
    CLOSE_DISPS(play->state.gfxCtx);
}