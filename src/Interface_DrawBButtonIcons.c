#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

extern s16 sBButtonDoActionTextureScale;
extern f32 sBButtonDoActionTextureScales[];
extern s16 sBButtonDoActionXPositions[];
extern s16 sBButtonDoActionYPositions[];
extern void Interface_DrawItemIconTexture(PlayState* play, TexturePtr texture, s16 button);
extern void Interface_DrawAmmoCount(PlayState* play, s16 button, s16 alpha);

// Set to false every frame at the end of Interface_DrawItemButtons
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

RECOMP_PATCH void Interface_DrawBButtonIcons(PlayState* play) {
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    Player* player = GET_PLAYER(play);

    OPEN_DISPS(play->state.gfxCtx);

    gDPPipeSync(OVERLAY_DISP++);
    gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 255, 255, 255, interfaceCtx->bAlpha);
    gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    u8 bButtonItem = BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B);

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
                ((interfaceCtx->bButtonPlayerDoActionActive && ((bButtonItem < ITEM_SWORD_KOKIRI) ||
                (bButtonItem > ITEM_SWORD_GILDED)) && bButtonItem != ITEM_NONE) &&
                (bButtonItem != ITEM_DEKU_NUT)))) {
        if (mBButtonEnabled[2] && ((player->transformation == PLAYER_FORM_FIERCE_DEITY) || (player->transformation == PLAYER_FORM_HUMAN))) {
            if (mBButtonEnabled[3] && bButtonItem != ITEM_NONE) {
                mBButtonDrawn = true;
                
                b_button_minigame_init(play, &bButtonItem);

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
                
                b_button_minigame_return(play, &bButtonItem);
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