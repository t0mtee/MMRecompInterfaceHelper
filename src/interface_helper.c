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

#pragma region Interface_DrawItemButtons_Declares

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

RECOMP_DECLARE_EVENT(c_glyph_hook_init(PlayState* play, s16* alpha))
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
RECOMP_DECLARE_EVENT(c_glyph_hook_return(PlayState* play, s16* alpha))

#pragma endregion

RECOMP_PATCH void Interface_DrawItemButtons(PlayState* play) {
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    PauseContext* pauseCtx = &play->pauseCtx;
    s16 temp; // Used as both an alpha value and a button index
    
    OPEN_DISPS(play->state.gfxCtx);

    gDPPipeSync(OVERLAY_DISP++);
    gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    // Fix green ammo (and potentially more if elements are disabled) bug described in Interface_DrawAmmoCount
    gDPSetEnvColor(0, 0, 0, 0, 255);
    
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
                interfaceCtx->cLeftAlpha);
            
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
            s16 alpha;
            if (temp == EQUIP_SLOT_C_LEFT) {
                alpha = interfaceCtx->cLeftAlpha;
            } else if (temp == EQUIP_SLOT_C_DOWN) {
                alpha = interfaceCtx->cDownAlpha;
            } else { // EQUIP_SLOT_C_RIGHT
                alpha = interfaceCtx->cRightAlpha;
            }

            c_glyph_hook_init(play, &alpha);
            
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0,
                mCGlyphColours[glyphTemp][0], mCGlyphColours[glyphTemp][1], mCGlyphColours[glyphTemp][2],
                alpha);
            OVERLAY_DISP =
                Gfx_DrawTexRectIA8(
                    OVERLAY_DISP, mCGlyphTextures[glyphTemp], mCGlyphTextureWidths[glyphTemp], mCGlyphTextureHeights[glyphTemp],
                        mCGlyphPositionsX[glyphTemp], mCGlyphPositionsY[glyphTemp],
                        mCGlyphRectSizesX[glyphTemp], mCGlyphRectSizesY[glyphTemp],
                        mCGlyphScalesX[glyphTemp], mCGlyphScalesY[glyphTemp]);
            
            c_glyph_hook_return(play, &alpha);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}

#pragma region Interface_DrawAmmoCount_Declares

extern TexturePtr gAmmoDigit0Tex[];

RECOMP_DECLARE_EVENT(ammo_hook_init(PlayState* play, u8 item, u16* ammo))
int mAmmoPrimColour[3] = {255, 255, 255};
int mAmmoEnvColour[4] = {0, 0, 0, 255};
bool mAmmoForceMaxColour = false;
int mAmmoFullColour[3] = {120, 255, 0};
int mAmmoEmptyColour[3] = {100, 100, 100};

TexturePtr mAmmoTextureTens = NULL;
s16 mAmmoTextureWidthTens = 8;
s16 mAmmoTextureHeightTens = 8;
s16 mAmmoPositionsTensX[4] = {
    162,                                // EQUIP_SLOT_B
    228,                                // EQUIP_SLOT_C_LEFT
    250,                                // EQUIP_SLOT_C_DOWN
    272                                 // EQUIP_SLOT_C_RIGHT
};
s16 mAmmoPositionsTensY[4] = {
    35,                                 // EQUIP_SLOT_B
    35,                                 // EQUIP_SLOT_C_LEFT
    51,                                 // EQUIP_SLOT_C_DOWN
    35                                  // EQUIP_SLOT_C_RIGHT
};
s16 mAmmoRectSizeTensX[4] = {
    8,                                  // EQUIP_SLOT_B
    8,                                  // EQUIP_SLOT_C_LEFT
    8,                                  // EQUIP_SLOT_C_DOWN
    8                                   // EQUIP_SLOT_C_RIGHT
};
s16 mAmmoRectSizeTensY[4] = {
    8,                                  // EQUIP_SLOT_B
    8,                                  // EQUIP_SLOT_C_LEFT
    8,                                  // EQUIP_SLOT_C_DOWN
    8                                   // EQUIP_SLOT_C_RIGHT
};
u16 mAmmoUpperScaleTensX = 1 << 10;
u16 mAmmoUpperScaleTensY = 1 << 10;
u16 mAmmoLowerScaleTensX = 1 << 10;
u16 mAmmoLowerScaleTensY = 1 << 10;

TexturePtr mAmmoTextureOnes = NULL;
s16 mAmmoTextureWidthOnes = 8;
s16 mAmmoTextureHeightOnes = 8;
s16 mAmmoPositionsOnesX[4] = {
    168,                                // EQUIP_SLOT_B
    234,                                // EQUIP_SLOT_C_LEFT
    256,                                // EQUIP_SLOT_C_DOWN
    278                                 // EQUIP_SLOT_C_RIGHT
};
s16 mAmmoPositionsOnesY[4] = {
    35,                                 // EQUIP_SLOT_B
    35,                                 // EQUIP_SLOT_C_LEFT
    51,                                 // EQUIP_SLOT_C_DOWN
    35                                  // EQUIP_SLOT_C_RIGHT
};
s16 mAmmoRectSizeOnesX[4] = {
    8,                                  // EQUIP_SLOT_B
    8,                                  // EQUIP_SLOT_C_LEFT
    8,                                  // EQUIP_SLOT_C_DOWN
    8                                   // EQUIP_SLOT_C_RIGHT
};
s16 mAmmoRectSizeOnesY[4] = {
    8,                                  // EQUIP_SLOT_B
    8,                                  // EQUIP_SLOT_C_LEFT
    8,                                  // EQUIP_SLOT_C_DOWN
    8                                   // EQUIP_SLOT_C_RIGHT
};
u16 mAmmoUpperScaleOnesX = 1 << 10;
u16 mAmmoUpperScaleOnesY = 1 << 10;
u16 mAmmoLowerScaleOnesX = 1 << 10;
u16 mAmmoLowerScaleOnesY = 1 << 10;
RECOMP_DECLARE_EVENT(ammo_hook_return(PlayState* play, u8 item))

#pragma endregion

RECOMP_PATCH void Interface_DrawAmmoCount(PlayState* play, s16 button, s16 alpha) {
    u8 i;
    u16 ammo;

    OPEN_DISPS(play->state.gfxCtx);

    i = ((void)0, GET_CUR_FORM_BTN_ITEM(button));

    if ((i == ITEM_DEKU_STICK) || (i == ITEM_DEKU_NUT) || (i == ITEM_BOMB) || (i == ITEM_BOW) ||
        ((i >= ITEM_BOW_FIRE) && (i <= ITEM_BOW_LIGHT)) || (i == ITEM_BOMBCHU) || (i == ITEM_POWDER_KEG) ||
        (i == ITEM_MAGIC_BEANS) || (i == ITEM_PICTOGRAPH_BOX)) {

        if ((i >= ITEM_BOW_FIRE) && (i <= ITEM_BOW_LIGHT)) {
            i = ITEM_BOW;
        }

        ammo = AMMO(i);

        if (i == ITEM_PICTOGRAPH_BOX) {
            if (!CHECK_QUEST_ITEM(QUEST_PICTOGRAPH)) {
                ammo = 0;
            } else {
                ammo = 1;
            }
        }

        gDPPipeSync(OVERLAY_DISP++);
        //! @bug Missing a gDPSetEnvColor here, which means the ammo count will be drawn with the last env color set.
        //! Once you have the magic meter, this becomes a non issue, as the magic meter will set the color to black,
        //! but prior to that, when certain conditions are met, the color will have last been set by the wallet icon
        //! causing the ammo count to be drawn incorrectly. This is most obvious when you get deku nuts early on, and
        //! the ammo count is drawn with a shade of green.
        // @interface_helper Fixed in Interface_DrawItemButtons
        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, mAmmoPrimColour[0], mAmmoPrimColour[1], mAmmoPrimColour[2], alpha);
        gDPSetEnvColor(OVERLAY_DISP++, mAmmoEnvColour[0], mAmmoEnvColour[1], mAmmoEnvColour[2], mAmmoEnvColour[3]);
        
        ammo_hook_init(play, i, &ammo);

        if ((button == EQUIP_SLOT_B) && (gSaveContext.minigameStatus == MINIGAME_STATUS_ACTIVE)) {
            ammo = play->interfaceCtx.minigameAmmo;
        } else if ((button == EQUIP_SLOT_B) && (play->bButtonAmmoPlusOne > 1)) {
            ammo = play->bButtonAmmoPlusOne - 1;
        } else if (mAmmoForceMaxColour ||
                ((i == ITEM_BOW) && (AMMO(i) == CUR_CAPACITY(UPG_QUIVER))) ||
                ((i == ITEM_BOMB) && (AMMO(i) == CUR_CAPACITY(UPG_BOMB_BAG))) ||
                ((i == ITEM_DEKU_STICK) && (AMMO(i) == CUR_CAPACITY(UPG_DEKU_STICKS))) ||
                ((i == ITEM_DEKU_NUT) && (AMMO(i) == CUR_CAPACITY(UPG_DEKU_NUTS))) ||
                ((i == ITEM_BOMBCHU) && (AMMO(i) == CUR_CAPACITY(UPG_BOMB_BAG))) ||
                ((i == ITEM_POWDER_KEG) && (ammo == 1)) || ((i == ITEM_PICTOGRAPH_BOX) && (ammo == 1)) ||
                ((i == ITEM_MAGIC_BEANS) && (ammo == 20))) {
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0, mAmmoFullColour[0], mAmmoFullColour[1], mAmmoFullColour[2], alpha);
        }
        
        if ((u32)ammo == 0) {
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0, mAmmoEmptyColour[0], mAmmoEmptyColour[1], mAmmoEmptyColour[2], alpha);
        }

        for (i = 0; ammo >= 10; i++) {
            ammo -= 10;
        }

        // Draw upper digit (tens)
        if ((u32)i != 0) {
            if (mAmmoTextureTens == NULL) {
                OVERLAY_DISP =
                    Gfx_DrawTexRectIA8(OVERLAY_DISP, (u8*)gAmmoDigit0Tex + i * AMMO_DIGIT_TEX_SIZE,
                        mAmmoTextureWidthTens, mAmmoTextureHeightTens,
                        mAmmoPositionsTensX[button], mAmmoPositionsTensY[button],
                        mAmmoRectSizeTensX[button], mAmmoRectSizeTensY[button], mAmmoUpperScaleTensX, mAmmoUpperScaleTensY);
            } else {
                OVERLAY_DISP =
                    Gfx_DrawTexRectIA8(OVERLAY_DISP, mAmmoTextureTens,
                        mAmmoTextureWidthTens, mAmmoTextureHeightTens,
                        mAmmoPositionsTensX[button], mAmmoPositionsTensY[button],
                        mAmmoRectSizeTensX[button], mAmmoRectSizeTensY[button], mAmmoUpperScaleTensX, mAmmoUpperScaleTensY);
            }
        }

        // Draw lower digit (ones)
        if (mAmmoTextureOnes == NULL) {
            OVERLAY_DISP =
                Gfx_DrawTexRectIA8(OVERLAY_DISP, (u8*)gAmmoDigit0Tex + ammo * AMMO_DIGIT_TEX_SIZE,
                    mAmmoTextureWidthOnes, mAmmoTextureHeightOnes,
                    mAmmoPositionsOnesX[button], mAmmoPositionsOnesY[button],
                    mAmmoRectSizeOnesX[button], mAmmoRectSizeOnesY[button], mAmmoUpperScaleOnesX, mAmmoUpperScaleOnesY);
        } else {
            OVERLAY_DISP =
                Gfx_DrawTexRectIA8(OVERLAY_DISP, mAmmoTextureOnes,
                    mAmmoTextureWidthOnes, mAmmoTextureHeightOnes,
                    mAmmoPositionsOnesX[button], mAmmoPositionsOnesY[button],
                    mAmmoRectSizeOnesX[button], mAmmoRectSizeOnesY[button], mAmmoUpperScaleOnesX, mAmmoUpperScaleOnesY);
        }

        ammo_hook_return(play, i);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}

#pragma region Interface_DrawBButtonIcons_Declares

extern s16 sBButtonDoActionTextureScale;
extern f32 sBButtonDoActionTextureScales[];
extern s16 sBButtonDoActionXPositions[];
extern s16 sBButtonDoActionYPositions[];
extern void Interface_DrawItemIconTexture(PlayState* play, TexturePtr texture, s16 button);

bool mBButtonDrawn = false;
bool mBButtonEnabled[8] = {true, true, true, true, true, true, true, true};

RECOMP_DECLARE_EVENT(b_button_deku_init(PlayState* play))
RECOMP_DECLARE_EVENT(b_button_deku_return(PlayState* play))

RECOMP_DECLARE_EVENT(b_button_minigame_init(PlayState* play, u8* item))
RECOMP_DECLARE_EVENT(b_button_minigame_return(PlayState* play, u8* item))

RECOMP_DECLARE_EVENT(b_button_interface_init(PlayState* play))
RECOMP_DECLARE_EVENT(b_button_interface_return(PlayState* play))

RECOMP_DECLARE_EVENT(b_button_action_init(PlayState* play))
RECOMP_DECLARE_EVENT(b_button_action_return(PlayState* play))

#pragma endregion

RECOMP_PATCH void Interface_DrawBButtonIcons(PlayState* play) {
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    Player* player = GET_PLAYER(play);

    OPEN_DISPS(play->state.gfxCtx);

    gDPPipeSync(OVERLAY_DISP++);
    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 255, 255, 255, interfaceCtx->bAlpha);
    gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    u8 bButtonIcon = BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B);

    mBButtonDrawn = false;

    if (mBButtonEnabled[0] && !interfaceCtx->bButtonInterfaceDoActionActive && (player->stateFlags3 & PLAYER_STATE3_1000000)) {
        if (gSaveContext.buttonStatus[EQUIP_SLOT_B] != BTN_DISABLED) {
            mBButtonDrawn = true;
            
            b_button_deku_init(play);

            Interface_DrawItemIconTexture(play, interfaceCtx->iconItemSegment, EQUIP_SLOT_B);
            gDPPipeSync(OVERLAY_DISP++);
            gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

            Interface_DrawAmmoCount(play, EQUIP_SLOT_B, interfaceCtx->bAlpha);

            b_button_deku_return(play);
        }
    } else if (mBButtonEnabled[1] &&
                ((!interfaceCtx->bButtonPlayerDoActionActive && !interfaceCtx->bButtonInterfaceDoActionActive) ||
                ((interfaceCtx->bButtonPlayerDoActionActive && ((bButtonIcon < ITEM_SWORD_KOKIRI) ||
                (bButtonIcon > ITEM_SWORD_GILDED)) && bButtonIcon != ITEM_NONE) &&
                (bButtonIcon != ITEM_DEKU_NUT)))) {
        if (mBButtonEnabled[2] && ((player->transformation == PLAYER_FORM_FIERCE_DEITY) || (player->transformation == PLAYER_FORM_HUMAN))) {
            if (mBButtonEnabled[3] && bButtonIcon != ITEM_NONE) {
                mBButtonDrawn = true;
                
                b_button_minigame_init(play, &bButtonIcon);

                Interface_DrawItemIconTexture(play, interfaceCtx->iconItemSegment, EQUIP_SLOT_B);
                if (mBButtonEnabled[4] && ((player->stateFlags1 & PLAYER_STATE1_800000) || CHECK_WEEKEVENTREG(WEEKEVENTREG_08_01) ||
                    (play->bButtonAmmoPlusOne >= 2))) {
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE,
                                      0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

                    if (mBButtonEnabled[5] && (play->sceneId != SCENE_SYATEKI_MIZU) &&
                        (play->sceneId != SCENE_SYATEKI_MORI) && (play->sceneId != SCENE_BOWLING) &&
                        ((gSaveContext.minigameStatus != MINIGAME_STATUS_ACTIVE) ||
                         (gSaveContext.save.entrance != ENTRANCE(ROMANI_RANCH, 0))) &&
                        ((gSaveContext.minigameStatus != MINIGAME_STATUS_ACTIVE) || !CHECK_EVENTINF(EVENTINF_35)) &&
                        (!CHECK_WEEKEVENTREG(WEEKEVENTREG_31_80) || (play->bButtonAmmoPlusOne != 100))) {
                        Interface_DrawAmmoCount(play, EQUIP_SLOT_B, interfaceCtx->bAlpha);
                    }
                }
                
                b_button_minigame_return(play, &bButtonIcon);
            }
        }
    } else if (mBButtonEnabled[6] && interfaceCtx->bButtonInterfaceDoActionActive) {
        mBButtonDrawn = true;

        b_button_interface_init(play);

        gDPPipeSync(OVERLAY_DISP++);
        gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 255, 255, 255, interfaceCtx->bAlpha);
        gDPLoadTextureBlock_4b(OVERLAY_DISP++, interfaceCtx->doActionSegment + DO_ACTION_OFFSET_B_PLAYER, G_IM_FMT_IA,
                               DO_ACTION_TEX_WIDTH, DO_ACTION_TEX_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP,
                               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        
        sBButtonDoActionTextureScale =
            1024.0f / (sBButtonDoActionTextureScales[gSaveContext.options.language] / 100.0f);
        
        gSPTextureRectangle(OVERLAY_DISP++, sBButtonDoActionXPositions[gSaveContext.options.language] * 4,
                            sBButtonDoActionYPositions[gSaveContext.options.language] * 4,
                            (sBButtonDoActionXPositions[gSaveContext.options.language] + DO_ACTION_TEX_WIDTH) << 2,
                            (sBButtonDoActionYPositions[gSaveContext.options.language] + DO_ACTION_TEX_HEIGHT) << 2,
                            G_TX_RENDERTILE, 0, 0, sBButtonDoActionTextureScale, sBButtonDoActionTextureScale);

        b_button_interface_return(play);
    } else if (mBButtonEnabled[7] && interfaceCtx->bButtonPlayerDoAction != DO_ACTION_NONE) {
        mBButtonDrawn = true;
        
        b_button_action_init(play);

        gDPPipeSync(OVERLAY_DISP++);
        gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 255, 255, 255, interfaceCtx->bAlpha);
        gDPLoadTextureBlock_4b(OVERLAY_DISP++, interfaceCtx->doActionSegment + DO_ACTION_OFFSET_B_INTERFACE,
                               G_IM_FMT_IA, DO_ACTION_TEX_WIDTH, DO_ACTION_TEX_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP,
                               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        sBButtonDoActionTextureScale =
            1024.0f / (sBButtonDoActionTextureScales[gSaveContext.options.language] / 100.0f);

        gSPTextureRectangle(OVERLAY_DISP++, sBButtonDoActionXPositions[gSaveContext.options.language] * 4,
                            sBButtonDoActionYPositions[gSaveContext.options.language] * 4,
                            (sBButtonDoActionXPositions[gSaveContext.options.language] + DO_ACTION_TEX_WIDTH) << 2,
                            (sBButtonDoActionYPositions[gSaveContext.options.language] + DO_ACTION_TEX_HEIGHT) << 2,
                            G_TX_RENDERTILE, 0, 0, sBButtonDoActionTextureScale, sBButtonDoActionTextureScale);
        
        b_button_action_return(play);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}