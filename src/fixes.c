#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

extern u8 gPlayerFormItemRestrictions[PLAYER_FORM_MAX][114];
u8 bBadIndex;

RECOMP_HOOK("Interface_UpdateButtonsPart2") void Interface_UpdateButtonsPart2_Init(PlayState* play) {
    // Fix a vanilla bug. gPlayerFormItemRestrictions has 114 allocated positions, however the 255th position is requested
    // when assessing C-buttons with no items.
    // This leads to unpredictable behaviour, and Deku Link alone will have greyed out empty C-buttons.
    // To fix this without causing any potential problems, save the value at the bugged index, replace it to true, then revert it.
    bBadIndex = gPlayerFormItemRestrictions[PLAYER_FORM_DEKU][255];
    if (recomp_get_config_u32("deku_empty_fix") == true) {
        gPlayerFormItemRestrictions[PLAYER_FORM_DEKU][255] = true;
    }

    // Keep buttons consistent by not disabling the Attack button when its empty.
    // Using FE as it is unused in the rest of the game.
    if (BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B) == ITEM_NONE && recomp_get_config_u32("enable_empty_attack") == true) {
        BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B) = ITEM_FE;
    }
}

RECOMP_HOOK_RETURN("Interface_UpdateButtonsPart2") void Interface_UpdateButtonsPart2_Return() {
    // Revert prior changes.
    gPlayerFormItemRestrictions[PLAYER_FORM_DEKU][255] = bBadIndex;

    if (BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B) == ITEM_FE) {
        BUTTON_ITEM_EQUIP(CUR_FORM, EQUIP_SLOT_B) = ITEM_NONE;
    }
}