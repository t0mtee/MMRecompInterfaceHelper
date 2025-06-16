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
extern Gfx* Gfx_DrawRect_DropShadow(Gfx* gfx, s16 rectLeft, s16 rectTop, s16 rectWidth, s16 rectHeight, u16 dsdx, u16 dtdy,
                             s16 r, s16 g, s16 b, s16 a);

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
s16 mButtonScalesX[4] = {
    (s32)(1.1230469f * (1 << 10)) >> 1, // EQUIP_SLOT_B
    (s32)(1.2109375f * (1 << 10)) >> 1, // EQUIP_SLOT_C_LEFT
    (s32)(1.2109375f * (1 << 10)) >> 1, // EQUIP_SLOT_C_DOWN
    (s32)(1.2109375f * (1 << 10)) >> 1  // EQUIP_SLOT_C_RIGHT
};
s16 mButtonScalesY[4] = {
    (s32)(1.1230469f * (1 << 10)) >> 1, // EQUIP_SLOT_B
    (s32)(1.2109375f * (1 << 10)) >> 1, // EQUIP_SLOT_C_LEFT
    (s32)(1.2109375f * (1 << 10)) >> 1, // EQUIP_SLOT_C_DOWN
    (s32)(1.2109375f * (1 << 10)) >> 1  // EQUIP_SLOT_C_RIGHT
};
s16 mButtonColours[4][3] = {
    {100, 255, 120},                    // EQUIP_SLOT_B
    {255, 240, 0},                      // EQUIP_SLOT_C_LEFT
    {255, 240, 0},                      // EQUIP_SLOT_C_DOWN
    {255, 240, 0}                       // EQUIP_SLOT_C_RIGHT
};

bool mStartForceEnabled = false;

bool mStartButtonEnabled = true;
s16 mStartButtonPositionX = 136;
s16 mStartButtonPositionY = 17;
u16 mStartButtonScaleX = (s32)(1.4277344f * (1 << 10));
u16 mStartButtonScaleY = (s32)(1.4277344f * (1 << 10));
s16 mStartButtonColour[3] = {255, 130, 60};

bool mStartLabelEnabled = true;
int mStartLabelColour[3] = {255, 255, 255};
int mStartLabelPositionX = 126 << 2;
int mStartLabelPositionY = 21 << 2;
int mStartLabelScaleX = (s32)(1.16211f * (1 << 10));
int mStartLabelScaleY = (s32)(1.16211f * (1 << 10));

bool mCUpForceEnabled = false;

bool mCUpEnabled = true;
s16 mCUpPositionX = 254;
s16 mCUpPositionY = 16;
u16 mCUpScaleX = 2 << 10;
u16 mCUpScaleY = 2 << 10;
s16 mCUpColours[3] = {255, 240, 0};

bool mCUpLabelEnabled = true;
int mCUpLabelColours[3] = {255, 255, 255};
int mCUpLabelPositionX = 247 << 2;
int mCUpLabelPositionY = 18 << 2;
int mCUpLabelScaleX = 1 << 10;
int mCUpLabelScaleY = 1 << 10;

bool mCGlyphsEnabled[3] = {
    true,                               // EQUIP_SLOT_C_LEFT
    true,                               // EQUIP_SLOT_C_DOWN
    true                                // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphsPositionsX[3] = {
    227,                                // EQUIP_SLOT_C_LEFT
    249,                                // EQUIP_SLOT_C_DOWN
    271                                 // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphsPositionsY[3] = {
    18,                                 // EQUIP_SLOT_C_LEFT
    34,                                 // EQUIP_SLOT_C_DOWN
    18                                  // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphsScalesX[3] = {
    (s32)(1.2109375f * (1 << 10)) >> 1, // EQUIP_SLOT_C_LEFT
    (s32)(1.2109375f * (1 << 10)) >> 1, // EQUIP_SLOT_C_DOWN
    (s32)(1.2109375f * (1 << 10)) >> 1  // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphsScalesY[3] = {
    (s32)(1.2109375f * (1 << 10)) >> 1, // EQUIP_SLOT_C_LEFT
    (s32)(1.2109375f * (1 << 10)) >> 1, // EQUIP_SLOT_C_DOWN
    (s32)(1.2109375f * (1 << 10)) >> 1  // EQUIP_SLOT_C_RIGHT
};
s16 mCGlyphsColours[3][3] = {
    {255, 240, 0},                      // EQUIP_SLOT_C_LEFT
    {255, 240, 0},                      // EQUIP_SLOT_C_DOWN
    {255, 240, 0}                       // EQUIP_SLOT_C_RIGHT
};

RECOMP_DECLARE_EVENT(b_button_hook_init(PlayState* play))
RECOMP_DECLARE_EVENT(b_button_hook_return(PlayState* play))
RECOMP_DECLARE_EVENT(button_hook_init(PlayState* play, EquipSlot button))
RECOMP_DECLARE_EVENT(button_hook_return(PlayState* play, EquipSlot button))
RECOMP_DECLARE_EVENT(start_hook_init(PlayState* play))
RECOMP_DECLARE_EVENT(start_hook_return(PlayState* play))
RECOMP_DECLARE_EVENT(c_up_hook_init(PlayState* play, s16* alpha))
RECOMP_DECLARE_EVENT(c_up_hook_return(PlayState* play, s16* alpha))
RECOMP_DECLARE_EVENT(c_glyph_hook_init(PlayState* play, s16* alpha))
RECOMP_DECLARE_EVENT(c_glyph_hook_return(PlayState* play, s16* alpha))

#pragma endregion

RECOMP_PATCH void Interface_DrawItemButtons(PlayState* play) {
    static TexturePtr sCUpLabelTextures[LANGUAGE_MAX] = {
        gTatlCUpENGTex, // LANGUAGE_JPN
        gTatlCUpENGTex, // LANGUAGE_ENG
        gTatlCUpGERTex, // LANGUAGE_GER
        gTatlCUpFRATex, // LANGUAGE_FRE
        gTatlCUpESPTex, // LANGUAGE_SPA
    };
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    PauseContext* pauseCtx = &play->pauseCtx;
    s16 temp; // Used as both an alpha value and a button index

    OPEN_DISPS(play->state.gfxCtx);

    gDPPipeSync(OVERLAY_DISP++);
    gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    // B, C-Left, C-Down, C-Right Button Color & Texture
    for (temp = EQUIP_SLOT_B; temp <= EQUIP_SLOT_C_RIGHT; temp++) {
        if (mButtonsEnabled[temp]) {
            button_hook_init(play, temp);

            OVERLAY_DISP = Gfx_DrawTexRectIA8_DropShadow(
                OVERLAY_DISP, mButtonTextures[temp], 32, 32,
                mButtonPositionsX[temp], mButtonPositionsY[temp],
                27, 27, mButtonScalesX[temp] * 2, mButtonScalesY[temp] * 2,
                mButtonColours[temp][0], mButtonColours[temp][1], mButtonColours[temp][2],
                interfaceCtx->cLeftAlpha);

            button_hook_return(play, temp);
        }
    }

    if (mStartForceEnabled || (!IS_PAUSE_STATE_GAMEOVER(pauseCtx) && (IS_PAUSED(pauseCtx)))) {
        start_hook_init(play);

        if (mStartButtonEnabled) {
            OVERLAY_DISP =
                Gfx_DrawRect_DropShadow(OVERLAY_DISP, mStartButtonPositionX, mStartButtonPositionY, 22, 22,
                                        mStartButtonScaleX, mStartButtonScaleY,
                                        mStartButtonColour[0], mStartButtonColour[1], mStartButtonColour[2], interfaceCtx->startAlpha);
        }
        
        // Start Button Texture, Color & Label
        if (mStartLabelEnabled) {
            gDPPipeSync(OVERLAY_DISP++);
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0,
                mStartLabelColour[0], mStartLabelColour[1], mStartLabelColour[2], interfaceCtx->startAlpha);
            // TODO Allo colour changing here
            gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, 0);
            gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
            gDPLoadTextureBlock_4b(OVERLAY_DISP++, interfaceCtx->doActionSegment + DO_ACTION_OFFSET_START, G_IM_FMT_IA,
                                    DO_ACTION_TEX_WIDTH, DO_ACTION_TEX_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(OVERLAY_DISP++, mStartLabelPositionX, mStartLabelPositionY,
                mStartLabelPositionX + (55 << 2), mStartLabelPositionY + (18 << 2), G_TX_RENDERTILE, 0, 0,
                mStartLabelScaleX, mStartLabelScaleY);
        }

        start_hook_return(play);
    }

    if (mCUpForceEnabled || (interfaceCtx->tatlCalling && !IS_PAUSED(pauseCtx) && (play->csCtx.state == CS_STATE_IDLE) &&
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

            c_up_hook_init(play, &temp);

            if (mCUpEnabled) {
                OVERLAY_DISP = Gfx_DrawRect_DropShadow(OVERLAY_DISP, mCUpPositionX, mCUpPositionY, 16, 16, mCUpScaleX, mCUpScaleY,
                    mCUpColours[0], mCUpColours[1], mCUpColours[2], temp);
            }

            // C-Up Label (Tatl Text)
            if (mCUpLabelEnabled) {
                gDPPipeSync(OVERLAY_DISP++);
                gDPSetPrimColor(OVERLAY_DISP++, 0, 0, mCUpLabelColours[0], mCUpLabelColours[1], mCUpLabelColours[2], temp);
                // TODO Allo colour changing here
                gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, 0);
                gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
                gDPLoadTextureBlock_4b(OVERLAY_DISP++, sCUpLabelTextures[gSaveContext.options.language], G_IM_FMT_IA, 32,
                                    12, 0, G_TX_NOMIRROR | G_TX_WRAP | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_WRAP | G_TX_CLAMP, G_TX_NOMASK,
                                    G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(OVERLAY_DISP++, mCUpLabelPositionX, mCUpLabelPositionY,
                    mCUpLabelPositionX + (32 << 2), mCUpLabelPositionY  + (12 << 2), G_TX_RENDERTILE,
                    0, 0, mCUpLabelScaleX, mCUpLabelScaleY);
            }

            c_up_hook_return(play, &temp);
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
                mCGlyphsColours[glyphTemp][0], mCGlyphsColours[glyphTemp][1],mCGlyphsColours[glyphTemp][2],
                alpha);
            OVERLAY_DISP =
                Gfx_DrawTexRectIA8(OVERLAY_DISP, ((u8*)gButtonBackgroundTex + ((32 * 32) * (temp + 1))), 32, 32,
                                   mCGlyphsPositionsX[glyphTemp], mCGlyphsPositionsY[glyphTemp], 27, 27,
                                   mCGlyphsScalesX[glyphTemp] * 2, mCGlyphsScalesY[glyphTemp] * 2);
            
            c_glyph_hook_return(play, &alpha);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}

#pragma region Interface_DrawAmmoCount_Declares

extern TexturePtr gAmmoDigit0Tex[];

s16 mAmmoPositionsX[4] = {
    162,                                // EQUIP_SLOT_B
    228,                                // EQUIP_SLOT_C_LEFT
    250,                                // EQUIP_SLOT_C_DOWN
    272                                 // EQUIP_SLOT_C_RIGHT
};
s16 mAmmoPositionsY[4] = {
    35,                                 // EQUIP_SLOT_B
    35,                                 // EQUIP_SLOT_C_LEFT
    51,                                 // EQUIP_SLOT_C_DOWN
    35                                  // EQUIP_SLOT_C_RIGHT
};
int mAmmoFullColours[3] = {120, 255, 0};
int mAmmoColours[3] = {100, 100, 100};
u16 mAmmoUpperScaleX = 1 << 10;
u16 mAmmoUpperScaleY = 1 << 10;
u16 mAmmoLowerScaleX = 1 << 10;
u16 mAmmoLowerScaleY = 1 << 10;

RECOMP_DECLARE_EVENT(ammo_hook_init(PlayState* play, u8 item, u16* ammo))
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
        // @interface_helper Fixed
        // TODO allow colour to be changed
        gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, 255);

        if ((button == EQUIP_SLOT_B) && (gSaveContext.minigameStatus == MINIGAME_STATUS_ACTIVE)) {
            ammo = play->interfaceCtx.minigameAmmo;
        } else if ((button == EQUIP_SLOT_B) && (play->bButtonAmmoPlusOne > 1)) {
            ammo = play->bButtonAmmoPlusOne - 1;
        } else if (((i == ITEM_BOW) && (AMMO(i) == CUR_CAPACITY(UPG_QUIVER))) ||
                ((i == ITEM_BOMB) && (AMMO(i) == CUR_CAPACITY(UPG_BOMB_BAG))) ||
                ((i == ITEM_DEKU_STICK) && (AMMO(i) == CUR_CAPACITY(UPG_DEKU_STICKS))) ||
                ((i == ITEM_DEKU_NUT) && (AMMO(i) == CUR_CAPACITY(UPG_DEKU_NUTS))) ||
                ((i == ITEM_BOMBCHU) && (AMMO(i) == CUR_CAPACITY(UPG_BOMB_BAG))) ||
                ((i == ITEM_POWDER_KEG) && (ammo == 1)) || ((i == ITEM_PICTOGRAPH_BOX) && (ammo == 1)) ||
                ((i == ITEM_MAGIC_BEANS) && (ammo == 20))) {
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0, mAmmoFullColours[0], mAmmoFullColours[1], mAmmoFullColours[2], alpha);
        }

        ammo_hook_init(play, i, &ammo);

        if ((u32)ammo == 0) {
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0, mAmmoColours[0], mAmmoColours[1], mAmmoColours[2], alpha);
        }

        for (i = 0; ammo >= 10; i++) {
            ammo -= 10;
        }

        // Draw upper digit (tens)
        if ((u32)i != 0) {
            OVERLAY_DISP =
                Gfx_DrawTexRectIA8(OVERLAY_DISP, (u8*)gAmmoDigit0Tex + i * AMMO_DIGIT_TEX_SIZE, AMMO_DIGIT_TEX_WIDTH,
                                   AMMO_DIGIT_TEX_HEIGHT, mAmmoPositionsX[button], mAmmoPositionsY[button],
                                   AMMO_DIGIT_TEX_WIDTH, AMMO_DIGIT_TEX_HEIGHT, mAmmoUpperScaleX, mAmmoUpperScaleY);
        }

        // Draw lower digit (ones)
        OVERLAY_DISP =
            Gfx_DrawTexRectIA8(OVERLAY_DISP, (u8*)gAmmoDigit0Tex + ammo * AMMO_DIGIT_TEX_SIZE, AMMO_DIGIT_TEX_WIDTH,
                               AMMO_DIGIT_TEX_HEIGHT, mAmmoPositionsX[button] + 6, mAmmoPositionsY[button],
                               AMMO_DIGIT_TEX_WIDTH, AMMO_DIGIT_TEX_HEIGHT, mAmmoLowerScaleX, mAmmoLowerScaleY);

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
int mBButtonItemColour[3] = {255, 255, 255};
int mBButtonEnvColour[4] = {0, 0, 0, 255};
bool mBButtonForceEnable[9] = {false, false, false, false, false, false, false, false, false};
int mBButtonDoActionColour[3] = {255, 255, 255};

RECOMP_DECLARE_EVENT(b_button_deku_init(PlayState* play))

#pragma endregion

RECOMP_PATCH void Interface_DrawBButtonIcons(PlayState* play) {
    mBButtonDrawn = false;

    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    Player* player = GET_PLAYER(play);

    OPEN_DISPS(play->state.gfxCtx);

    gDPPipeSync(OVERLAY_DISP++);
    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, mBButtonItemColour[0], mBButtonItemColour[1], mBButtonItemColour[2], interfaceCtx->bAlpha);
    gDPSetEnvColor(OVERLAY_DISP++, mBButtonEnvColour[0], mBButtonEnvColour[1], mBButtonEnvColour[2], mBButtonEnvColour[4]);
    gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    // @interface_helper When Deku floating
    if (mBButtonForceEnable[0] || (!interfaceCtx->bButtonInterfaceDoActionActive && (player->stateFlags3 & PLAYER_STATE3_1000000))) {
        if (mBButtonForceEnable[1] || (gSaveContext.buttonStatus[EQUIP_SLOT_B] != BTN_DISABLED)) {
            b_button_deku_init(play);
            mBButtonDrawn = true;

            Interface_DrawItemIconTexture(play, interfaceCtx->iconItemSegment, EQUIP_SLOT_B);
            gDPPipeSync(OVERLAY_DISP++);
            gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

            Interface_DrawAmmoCount(play, EQUIP_SLOT_B, interfaceCtx->bAlpha);
        }
    // @interface_helper When item equipped to B button
    } else if (mBButtonForceEnable[2] || ((!interfaceCtx->bButtonPlayerDoActionActive && !interfaceCtx->bButtonInterfaceDoActionActive) ||
               ((interfaceCtx->bButtonPlayerDoActionActive &&
                 ((BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B) < ITEM_SWORD_KOKIRI) ||
                  (BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B) > ITEM_SWORD_GILDED)) &&
                 BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B) != ITEM_NONE) &&
                (BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B) != ITEM_DEKU_NUT)))) {
        // @interface_helper When Human or Fierce Deity
        if (mBButtonForceEnable[3] || ((player->transformation == PLAYER_FORM_FIERCE_DEITY) || (player->transformation == PLAYER_FORM_HUMAN))) {
            // @interface_helper When item is equipped
            if (mBButtonForceEnable[4] || (BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B) != ITEM_NONE)) {
                mBButtonDrawn = true;

                Interface_DrawItemIconTexture(play, interfaceCtx->iconItemSegment, EQUIP_SLOT_B);
                if (mBButtonForceEnable[5] || ((player->stateFlags1 & PLAYER_STATE1_800000) || CHECK_WEEKEVENTREG(WEEKEVENTREG_08_01) ||
                    (play->bButtonAmmoPlusOne >= 2))) {
                    gDPPipeSync(OVERLAY_DISP++);
                    gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE,
                                      0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

                    if (mBButtonForceEnable[6] || ((play->sceneId != SCENE_SYATEKI_MIZU) && (play->sceneId != SCENE_SYATEKI_MORI) &&
                        (play->sceneId != SCENE_BOWLING) &&
                        ((gSaveContext.minigameStatus != MINIGAME_STATUS_ACTIVE) ||
                         (gSaveContext.save.entrance != ENTRANCE(ROMANI_RANCH, 0))) &&
                        ((gSaveContext.minigameStatus != MINIGAME_STATUS_ACTIVE) || !CHECK_EVENTINF(EVENTINF_35)) &&
                        (!CHECK_WEEKEVENTREG(WEEKEVENTREG_31_80) || (play->bButtonAmmoPlusOne != 100)))) {
                        Interface_DrawAmmoCount(play, EQUIP_SLOT_B, interfaceCtx->bAlpha);
                    }
                }
            }
        }
    } else if (mBButtonForceEnable[7] || (interfaceCtx->bButtonInterfaceDoActionActive)) {
        mBButtonDrawn = true;

        gDPPipeSync(OVERLAY_DISP++);
        gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(OVERLAY_DISP++, 0, 0,
            mBButtonDoActionColour[0],mBButtonDoActionColour[1], mBButtonDoActionColour[2], interfaceCtx->bAlpha);
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
    } else if (mBButtonForceEnable[8] || (interfaceCtx->bButtonPlayerDoAction != DO_ACTION_NONE)) {
        mBButtonDrawn = true;

        gDPPipeSync(OVERLAY_DISP++);
        gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(OVERLAY_DISP++, 0, 0,
            mBButtonDoActionColour[0],mBButtonDoActionColour[1], mBButtonDoActionColour[2], interfaceCtx->bAlpha);
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
    }

    gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, 255);

    CLOSE_DISPS(play->state.gfxCtx);
}
