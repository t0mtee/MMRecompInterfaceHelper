#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

extern TexturePtr gAmmoDigit0Tex[];

RECOMP_DECLARE_EVENT(ammo_hook_init(PlayState* play, u8 item, u16* ammo))
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

RECOMP_PATCH void Interface_DrawAmmoCount(PlayState* play, s16 button, s16 alpha) {
    mAmmoForceMaxColour = false;

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