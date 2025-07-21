#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

TexturePtr mItemIconTextureOverride = NULL;
int mItemIconTextureWidth = 32;
int mItemIconTextureHeight = 32;

s16 mItemIconPositionsX[] = {
    167 << 2, // EQUIP_SLOT_B
    227 << 2, // EQUIP_SLOT_C_LEFT
    249 << 2, // EQUIP_SLOT_C_DOWN
    271 << 2, // EQUIP_SLOT_C_RIGHT
};
s16 mItemIconPositionsY[] = {
    17 << 2, // EQUIP_SLOT_B
    18 << 2, // EQUIP_SLOT_C_LEFT
    34 << 2, // EQUIP_SLOT_C_DOWN
    18 << 2, // EQUIP_SLOT_C_RIGHT
};
s16 mItemIconRectSizesX[] = {
    30 << 2, // EQUIP_SLOT_B
    24 << 2, // EQUIP_SLOT_C_LEFT
    24 << 2, // EQUIP_SLOT_C_DOWN
    24 << 2, // EQUIP_SLOT_C_RIGHT
};
s16 mItemIconRectSizesY[] = {
    30 << 2, // EQUIP_SLOT_B
    24 << 2, // EQUIP_SLOT_C_LEFT
    24 << 2, // EQUIP_SLOT_C_DOWN
    24 << 2, // EQUIP_SLOT_C_RIGHT
};
s16 mItemIconTextureDimensions[] = {
    30, // EQUIP_SLOT_B
    24, // EQUIP_SLOT_C_LEFT
    24, // EQUIP_SLOT_C_DOWN
    24, // EQUIP_SLOT_C_RIGHT
};
s16 mItemIconTextureScales[] = {
    (s16)(1.074219f * (1 << 10)), // EQUIP_SLOT_B
    (s16)(1.328125f * (1 << 10)), // EQUIP_SLOT_C_LEFT
    (s16)(1.328125f * (1 << 10)), // EQUIP_SLOT_C_DOWN
    (s16)(1.328125f * (1 << 10)), // EQUIP_SLOT_C_RIGHT
};

RECOMP_HOOK("Interface_DrawItemIconTexture") void Interface_DrawItemIconTexture_Init(PlayState* play, TexturePtr texture, s16 button) {
    if (recomp_get_config_u32("attack_item_scale") == true) {
        // Make Attack button item icons similar size relative to button.
        mItemIconRectSizesX[0] = 27 << 2;
        mItemIconRectSizesY[0] = 27 << 2;
        mItemIconTextureScales[0] = 1240;
    } else {
        mItemIconRectSizesX[0] = 30 << 2;
        mItemIconRectSizesY[0] = 30 << 2;
        mItemIconTextureScales[0] = (s16)(1.074219f * (1 << 10));
    }
}

RECOMP_PATCH void Interface_DrawItemIconTexture(PlayState* play, TexturePtr texture, s16 button) {
    if (mItemIconTextureOverride != NULL) {
        texture = mItemIconTextureOverride;
    }

    OPEN_DISPS(play->state.gfxCtx);

    gDPLoadTextureBlock(OVERLAY_DISP++, texture, G_IM_FMT_RGBA, G_IM_SIZ_32b, mItemIconTextureWidth, mItemIconTextureHeight,
                        0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    
    gSPTextureRectangle(OVERLAY_DISP++, mItemIconPositionsX[button], mItemIconPositionsY[button],
                        mItemIconPositionsX[button] + mItemIconRectSizesX[button],
                        mItemIconPositionsY[button] + mItemIconRectSizesY[button], G_TX_RENDERTILE, 0, 0,
                        mItemIconTextureScales[button], mItemIconTextureScales[button]);

    CLOSE_DISPS(play->state.gfxCtx);
}