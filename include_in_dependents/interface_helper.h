#ifndef INTERFACE_HELPER

#define INTERFACE_HELPER

#include "modding.h"
#include "global.h"

#define INIT_PARAMETERS bool* dButtonsEnabled, TexturePtr* dButtonTextures, s16* dButtonTexturesWidth, s16* dButtonTexturesHeight, s16* dButtonPositionsX, s16* dButtonPositionsY, s16* dButtonRectSizesX, s16* dButtonRectSizesY, s16* dButtonScalesX, s16* dButtonScalesY, s16* dButtonColours, bool* dStartForceEnabled, bool* dStartButtonEnabled, TexturePtr* dStartButtonTexture, s16* dStartButtonTextureWidth, s16* dStartButtonTextureHeight, s16* dStartButtonPositionX, s16* dStartButtonPositionY, s16* dStartButtonRectSizeX, s16* dStartButtonRectSizeY, u16* dStartButtonScaleX, u16* dStartButtonScaleY, s16* dStartButtonColour, bool* dStartLabelEnabled, int* dStartLabelPrimColour, int* dStartLabelEnvColour, TexturePtr* dStartLabelTexture, int* dStartLabelTextureWidth, int* dStartLabelTextureHeight, int* dStartLabelPositionX, int* dStartLabelPositionY, int* dStartLabelRectSizeX, int* dStartLabelRectSizeY, int* dStartLabelScaleX, int* dStartLabelScaleY, bool* dCUpButtonForceEnabled, bool* dCUpButtonEnabled, TexturePtr* dCUpButtonTexture, int* dCUpButtonTextureWidth, int* dCUpButtonTextureHeight, s16* dCUpButtonPositionX, s16* dCUpButtonPositionY, s16* dCUpButtonRectSizeX, s16* dCUpButtonRectSizeY, u16* dCUpButtonScaleX, u16* dCUpButtonScaleY, s16* dCUpButtonColours, bool* dCUpLabelEnabled, int* dCUpLabelPrimColour, int* dCUpLabelEnvColour, TexturePtr* dCUpLabelTextures, int* dCUpLabelTextureWidths, int* dCUpLabelTextureHeights, int* dCUpLabelPositionX, int* dCUpLabelPositionY, int* dCUpLabelRectSizeX, int* dCUpLabelRectSizeY, int* dCUpLabelScaleX, int* dCUpLabelScaleY, bool* dCGlyphsEnabled, TexturePtr* dCGlyphTextures, s16* dCGlyphTextureWidths, s16* dCGlyphTextureHeights, s16* dCGlyphPositionsX, s16* dCGlyphPositionsY, s16* dCGlyphRectSizesX, s16* dCGlyphRectSizesY, s16* dCGlyphScalesX, s16* dCGlyphScalesY, s16* dCGlyphColours, int* dAmmoPrimColour, int* dAmmoEnvColour, bool* dAmmoForceMaxColour, int* dAmmoFullColour, int* dAmmoEmptyColour, TexturePtr* dAmmoTextureTens, s16* dAmmoTextureWidthTens, s16* dAmmoTextureHeightTens, s16* dAmmoPositionsTensX, s16* dAmmoPositionsTensY, s16* dAmmoRectSizeTensX, s16* dAmmoRectSizeTensY, u16* dAmmoUpperScaleTensX, u16* dAmmoUpperScaleTensY, u16* dAmmoLowerScaleTensX, u16* dAmmoLowerScaleTensY, TexturePtr* dAmmoTextureOnes, s16* dAmmoTextureWidthOnes, s16* dAmmoTextureHeightOnes, s16* dAmmoPositionsOnesX, s16* dAmmoPositionsOnesY, s16* dAmmoRectSizeOnesX, s16* dAmmoRectSizeOnesY, u16* dAmmoUpperScaleOnesX, u16* dAmmoUpperScaleOnesY, u16* dAmmoLowerScaleOnesX, u16* dAmmoLowerScaleOnesY, bool* dBButtonDrawn, bool* dBButtonEnabled
#define INIT_ARGUMENTS iButtonsEnabled, iButtonTextures, iButtonTexturesWidth, iButtonTexturesHeight, iButtonPositionsX, iButtonPositionsY, iButtonRectSizesX, iButtonRectSizesY, iButtonScalesX, iButtonScalesY, iButtonColours, iStartForceEnabled, iStartButtonEnabled, iStartButtonTexture, iStartButtonTextureWidth, iStartButtonTextureHeight, iStartButtonPositionX, iStartButtonPositionY, iStartButtonRectSizeX, iStartButtonRectSizeY, iStartButtonScaleX, iStartButtonScaleY, iStartButtonColour, iStartLabelEnabled, iStartLabelPrimColour, iStartLabelEnvColour, iStartLabelTexture, iStartLabelTextureWidth, iStartLabelTextureHeight, iStartLabelPositionX, iStartLabelPositionY, iStartLabelRectSizeX, iStartLabelRectSizeY, iStartLabelScaleX, iStartLabelScaleY, iCUpButtonForceEnabled, iCUpButtonEnabled, iCUpButtonTexture, iCUpButtonTextureWidth, iCUpButtonTextureHeight, iCUpButtonPositionX, iCUpButtonPositionY, iCUpButtonRectSizeX, iCUpButtonRectSizeY, iCUpButtonScaleX, iCUpButtonScaleY, iCUpButtonColours, iCUpLabelEnabled, iCUpLabelPrimColour, iCUpLabelEnvColour, iCUpLabelTextures, iCUpLabelTextureWidths, iCUpLabelTextureHeights, iCUpLabelPositionX, iCUpLabelPositionY, iCUpLabelRectSizeX, iCUpLabelRectSizeY, iCUpLabelScaleX, iCUpLabelScaleY, iCGlyphsEnabled, iCGlyphTextures, iCGlyphTextureWidths, iCGlyphTextureHeights, iCGlyphPositionsX, iCGlyphPositionsY, iCGlyphRectSizesX, iCGlyphRectSizesY, iCGlyphScalesX, iCGlyphScalesY, iCGlyphColours, iAmmoPrimColour, iAmmoEnvColour, iAmmoForceMaxColour, iAmmoFullColour, iAmmoEmptyColour, iAmmoTextureTens, iAmmoTextureWidthTens, iAmmoTextureHeightTens, iAmmoPositionsTensX, iAmmoPositionsTensY, iAmmoRectSizeTensX, iAmmoRectSizeTensY, iAmmoUpperScaleTensX, iAmmoUpperScaleTensY, iAmmoLowerScaleTensX, iAmmoLowerScaleTensY, iAmmoTextureOnes, iAmmoTextureWidthOnes, iAmmoTextureHeightOnes, iAmmoPositionsOnesX, iAmmoPositionsOnesY, iAmmoRectSizeOnesX, iAmmoRectSizeOnesY, iAmmoUpperScaleOnesX, iAmmoUpperScaleOnesY, iAmmoLowerScaleOnesX, iAmmoLowerScaleOnesY, iBButtonDrawn, iBButtonEnabled

#define IH_INIT bool* iButtonsEnabled; \
                TexturePtr* iButtonTextures; \
                s16* iButtonTexturesWidth; \
                s16* iButtonTexturesHeight; \
                s16* iButtonPositionsX; \
                s16* iButtonPositionsY; \
                s16* iButtonRectSizesX; \
                s16* iButtonRectSizesY; \
                s16* iButtonScalesX; \
                s16* iButtonScalesY; \
                s16* iButtonColours; \
                bool* iStartForceEnabled; \
                bool* iStartButtonEnabled; \
                TexturePtr* iStartButtonTexture; \
                s16* iStartButtonTextureWidth; \
                s16* iStartButtonTextureHeight; \
                s16* iStartButtonPositionX; \
                s16* iStartButtonPositionY; \
                s16* iStartButtonRectSizeX; \
                s16* iStartButtonRectSizeY; \
                u16* iStartButtonScaleX; \
                u16* iStartButtonScaleY; \
                s16* iStartButtonColour; \
                bool* iStartLabelEnabled; \
                int* iStartLabelPrimColour; \
                int* iStartLabelEnvColour; \
                TexturePtr* iStartLabelTexture; \
                int* iStartLabelTextureWidth; \
                int* iStartLabelTextureHeight; \
                int* iStartLabelPositionX; \
                int* iStartLabelPositionY; \
                int* iStartLabelRectSizeX; \
                int* iStartLabelRectSizeY; \
                int* iStartLabelScaleX; \
                int* iStartLabelScaleY; \
                bool* iCUpButtonForceEnabled; \
                bool* iCUpButtonEnabled; \
                TexturePtr* iCUpButtonTexture; \
                int* iCUpButtonTextureWidth; \
                int* iCUpButtonTextureHeight; \
                s16* iCUpButtonPositionX; \
                s16* iCUpButtonPositionY; \
                s16* iCUpButtonRectSizeX; \
                s16* iCUpButtonRectSizeY; \
                u16* iCUpButtonScaleX; \
                u16* iCUpButtonScaleY; \
                s16* iCUpButtonColours; \
                bool* iCUpLabelEnabled; \
                int* iCUpLabelPrimColour; \
                int* iCUpLabelEnvColour; \
                TexturePtr* iCUpLabelTextures; \
                int* iCUpLabelTextureWidths; \
                int* iCUpLabelTextureHeights; \
                int* iCUpLabelPositionX; \
                int* iCUpLabelPositionY; \
                int* iCUpLabelRectSizeX; \
                int* iCUpLabelRectSizeY; \
                int* iCUpLabelScaleX; \
                int* iCUpLabelScaleY; \
                bool* iCGlyphsEnabled; \
                TexturePtr* iCGlyphTextures; \
                s16* iCGlyphTextureWidths; \
                s16* iCGlyphTextureHeights; \
                s16* iCGlyphPositionsX; \
                s16* iCGlyphPositionsY; \
                s16* iCGlyphRectSizesX; \
                s16* iCGlyphRectSizesY; \
                s16* iCGlyphScalesX; \
                s16* iCGlyphScalesY; \
                s16* iCGlyphColours; \
                int* iAmmoPrimColour; \
                int* iAmmoEnvColour; \
                bool* iAmmoForceMaxColour; \
                int* iAmmoFullColour; \
                int* iAmmoEmptyColour; \
                TexturePtr* iAmmoTextureTens; \
                s16* iAmmoTextureWidthTens; \
                s16* iAmmoTextureHeightTens; \
                s16* iAmmoPositionsTensX; \
                s16* iAmmoPositionsTensY; \
                s16* iAmmoRectSizeTensX; \
                s16* iAmmoRectSizeTensY; \
                u16* iAmmoUpperScaleTensX; \
                u16* iAmmoUpperScaleTensY; \
                u16* iAmmoLowerScaleTensX; \
                u16* iAmmoLowerScaleTensY; \
                TexturePtr* iAmmoTextureOnes; \
                s16* iAmmoTextureWidthOnes; \
                s16* iAmmoTextureHeightOnes; \
                s16* iAmmoPositionsOnesX; \
                s16* iAmmoPositionsOnesY; \
                s16* iAmmoRectSizeOnesX; \
                s16* iAmmoRectSizeOnesY; \
                u16* iAmmoUpperScaleOnesX; \
                u16* iAmmoUpperScaleOnesY; \
                u16* iAmmoLowerScaleOnesX; \
                u16* iAmmoLowerScaleOnesY; \
                bool* iBButtonDrawn; \
                bool* iBButtonEnabled; \
                RECOMP_IMPORT("mm_recomp_interface_helper", void InterfaceHelper_Init(INIT_PARAMETERS)) \
                RECOMP_CALLBACK("*", recomp_after_play_init) void after_play_init() { InterfaceHelper_Init(INIT_ARGUMENTS); } \


#endif // INTERFACE_HELPER