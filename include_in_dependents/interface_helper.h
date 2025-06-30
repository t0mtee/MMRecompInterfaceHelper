#ifndef INTERFACE_HELPER

#define INTERFACE_HELPER

#include "modding.h"
#include "global.h"

#define INIT_PARAMETERS bool (**dButtonsEnabled)[4], TexturePtr (**dButtonTextures)[][4], s16 (**dButtonTexturesWidth)[4], s16 (**dButtonTexturesHeight)[4], s16 (**dButtonPositionsX)[4], s16 (**dButtonPositionsY)[4], s16 (**dButtonRectSizesX)[4], s16 (**dButtonRectSizesY)[4], s16 (**dButtonScalesX)[4], s16 (**dButtonScalesY)[4], s16 (**dButtonColours)[4][3], bool** dStartForceEnabled, bool** dStartButtonEnabled, TexturePtr (**dStartButtonTexture)[], s16** dStartButtonTextureWidth, s16** dStartButtonTextureHeight, s16** dStartButtonPositionX, s16** dStartButtonPositionY, s16** dStartButtonRectSizeX, s16** dStartButtonRectSizeY, u16** dStartButtonScaleX, u16** dStartButtonScaleY, s16 (**dStartButtonColour)[3], bool** dStartLabelEnabled, int (**dStartLabelPrimColour)[3], int (**dStartLabelEnvColour)[4], TexturePtr (**dStartLabelTexture)[], int** dStartLabelTextureWidth, int** dStartLabelTextureHeight, int** dStartLabelPositionX, int** dStartLabelPositionY, int** dStartLabelRectSizeX, int** dStartLabelRectSizeY, int** dStartLabelScaleX, int** dStartLabelScaleY, bool** dCUpButtonForceEnabled, bool** dCUpButtonEnabled, TexturePtr (**dCUpButtonTexture)[], int** dCUpButtonTextureWidth, int** dCUpButtonTextureHeight, s16** dCUpButtonPositionX, s16** dCUpButtonPositionY, s16** dCUpButtonRectSizeX, s16** dCUpButtonRectSizeY, u16** dCUpButtonScaleX, u16** dCUpButtonScaleY, s16 (**dCUpButtonColours)[3], bool** dCUpLabelEnabled, int (**dCUpLabelPrimColour)[3], int (**dCUpLabelEnvColour)[4], TexturePtr (**dCUpLabelTextures)[][LANGUAGE_MAX], int (**dCUpLabelTextureWidths)[LANGUAGE_MAX], int (**dCUpLabelTextureHeights)[LANGUAGE_MAX], int** dCUpLabelPositionX, int** dCUpLabelPositionY, int** dCUpLabelRectSizeX, int** dCUpLabelRectSizeY, int** dCUpLabelScaleX, int** dCUpLabelScaleY, bool (**dCGlyphsEnabled)[3], TexturePtr (**dCGlyphTextures)[][3], s16 (**dCGlyphTextureWidths)[3], s16 (**dCGlyphTextureHeights)[3], s16 (**dCGlyphPositionsX)[3], s16 (**dCGlyphPositionsY)[3], s16 (**dCGlyphRectSizesX)[3], s16 (**dCGlyphRectSizesY)[3], s16 (**dCGlyphScalesX)[3], s16 (**dCGlyphScalesY)[3], s16 (**dCGlyphColours)[3][3], int (**dAmmoPrimColour)[3], int (**dAmmoEnvColour)[4], bool** dAmmoForceMaxColour, int (**dAmmoFullColour)[3], int (**dAmmoEmptyColour)[3], TexturePtr (**dAmmoTextureTens)[], s16** dAmmoTextureWidthTens, s16** dAmmoTextureHeightTens, s16 (**dAmmoPositionsTensX)[4], s16 (**dAmmoPositionsTensY)[4], s16 (**dAmmoRectSizeTensX)[4], s16 (**dAmmoRectSizeTensY)[4], u16** dAmmoUpperScaleTensX, u16** dAmmoUpperScaleTensY, u16** dAmmoLowerScaleTensX, u16** dAmmoLowerScaleTensY, TexturePtr (**dAmmoTextureOnes)[], s16** dAmmoTextureWidthOnes, s16** dAmmoTextureHeightOnes, s16 (**dAmmoPositionsOnesX)[4], s16 (**dAmmoPositionsOnesY)[4], s16 (**dAmmoRectSizeOnesX)[4], s16 (**dAmmoRectSizeOnesY)[4], u16** dAmmoUpperScaleOnesX, u16** dAmmoUpperScaleOnesY, u16** dAmmoLowerScaleOnesX, u16** dAmmoLowerScaleOnesY, bool** dBButtonDrawn, bool (**dBButtonEnabled)[8]
#define INIT_ARGUMENTS &iButtonsEnabled, &iButtonTextures, &iButtonTexturesWidth, &iButtonTexturesHeight, &iButtonPositionsX, &iButtonPositionsY, &iButtonRectSizesX, &iButtonRectSizesY, &iButtonScalesX, &iButtonScalesY, &iButtonColours, &iStartForceEnabled, &iStartButtonEnabled, &iStartButtonTexture, &iStartButtonTextureWidth, &iStartButtonTextureHeight, &iStartButtonPositionX, &iStartButtonPositionY, &iStartButtonRectSizeX, &iStartButtonRectSizeY, &iStartButtonScaleX, &iStartButtonScaleY, &iStartButtonColour, &iStartLabelEnabled, &iStartLabelPrimColour, &iStartLabelEnvColour, &iStartLabelTexture, &iStartLabelTextureWidth, &iStartLabelTextureHeight, &iStartLabelPositionX, &iStartLabelPositionY, &iStartLabelRectSizeX, &iStartLabelRectSizeY, &iStartLabelScaleX, &iStartLabelScaleY, &iCUpButtonForceEnabled, &iCUpButtonEnabled, &iCUpButtonTexture, &iCUpButtonTextureWidth, &iCUpButtonTextureHeight, &iCUpButtonPositionX, &iCUpButtonPositionY, &iCUpButtonRectSizeX, &iCUpButtonRectSizeY, &iCUpButtonScaleX, &iCUpButtonScaleY, &iCUpButtonColours, &iCUpLabelEnabled, &iCUpLabelPrimColour, &iCUpLabelEnvColour, &iCUpLabelTextures, &iCUpLabelTextureWidths, &iCUpLabelTextureHeights, &iCUpLabelPositionX, &iCUpLabelPositionY, &iCUpLabelRectSizeX, &iCUpLabelRectSizeY, &iCUpLabelScaleX, &iCUpLabelScaleY, &iCGlyphsEnabled, &iCGlyphTextures, &iCGlyphTextureWidths, &iCGlyphTextureHeights, &iCGlyphPositionsX, &iCGlyphPositionsY, &iCGlyphRectSizesX, &iCGlyphRectSizesY, &iCGlyphScalesX, &iCGlyphScalesY, &iCGlyphColours, &iAmmoPrimColour, &iAmmoEnvColour, &iAmmoForceMaxColour, &iAmmoFullColour, &iAmmoEmptyColour, &iAmmoTextureTens, &iAmmoTextureWidthTens, &iAmmoTextureHeightTens, &iAmmoPositionsTensX, &iAmmoPositionsTensY, &iAmmoRectSizeTensX, &iAmmoRectSizeTensY, &iAmmoUpperScaleTensX, &iAmmoUpperScaleTensY, &iAmmoLowerScaleTensX, &iAmmoLowerScaleTensY, &iAmmoTextureOnes, &iAmmoTextureWidthOnes, &iAmmoTextureHeightOnes, &iAmmoPositionsOnesX, &iAmmoPositionsOnesY, &iAmmoRectSizeOnesX, &iAmmoRectSizeOnesY, &iAmmoUpperScaleOnesX, &iAmmoUpperScaleOnesY, &iAmmoLowerScaleOnesX, &iAmmoLowerScaleOnesY, &iBButtonDrawn, &iBButtonEnabled

#define IH_INIT bool (*iButtonsEnabled)[4]; \
                TexturePtr (*iButtonTextures)[][4]; \
                s16 (*iButtonTexturesWidth)[4]; \
                s16 (*iButtonTexturesHeight)[4]; \
                s16 (*iButtonPositionsX)[4]; \
                s16 (*iButtonPositionsY)[4]; \
                s16 (*iButtonRectSizesX)[4]; \
                s16 (*iButtonRectSizesY)[4]; \
                s16 (*iButtonScalesX)[4]; \
                s16 (*iButtonScalesY)[4]; \
                s16 (*iButtonColours)[4][3]; \
                bool* iStartForceEnabled; \
                bool* iStartButtonEnabled; \
                TexturePtr (*iStartButtonTexture)[]; \
                s16* iStartButtonTextureWidth; \
                s16* iStartButtonTextureHeight; \
                s16* iStartButtonPositionX; \
                s16* iStartButtonPositionY; \
                s16* iStartButtonRectSizeX; \
                s16* iStartButtonRectSizeY; \
                u16* iStartButtonScaleX; \
                u16* iStartButtonScaleY; \
                s16 (*iStartButtonColour)[3]; \
                bool* iStartLabelEnabled; \
                int (*iStartLabelPrimColour)[3]; \
                int (*iStartLabelEnvColour)[4]; \
                TexturePtr (*iStartLabelTexture)[]; \
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
                TexturePtr (*iCUpButtonTexture)[]; \
                int* iCUpButtonTextureWidth; \
                int* iCUpButtonTextureHeight; \
                s16* iCUpButtonPositionX; \
                s16* iCUpButtonPositionY; \
                s16* iCUpButtonRectSizeX; \
                s16* iCUpButtonRectSizeY; \
                u16* iCUpButtonScaleX; \
                u16* iCUpButtonScaleY; \
                s16 (*iCUpButtonColours)[3]; \
                bool* iCUpLabelEnabled; \
                int (*iCUpLabelPrimColour)[3]; \
                int (*iCUpLabelEnvColour)[4]; \
                TexturePtr (*iCUpLabelTextures)[][LANGUAGE_MAX]; \
                int (*iCUpLabelTextureWidths)[LANGUAGE_MAX]; \
                int (*iCUpLabelTextureHeights)[LANGUAGE_MAX]; \
                int* iCUpLabelPositionX; \
                int* iCUpLabelPositionY; \
                int* iCUpLabelRectSizeX; \
                int* iCUpLabelRectSizeY; \
                int* iCUpLabelScaleX; \
                int* iCUpLabelScaleY; \
                bool (*iCGlyphsEnabled)[3]; \
                TexturePtr (*iCGlyphTextures)[][3]; \
                s16 (*iCGlyphTextureWidths)[3]; \
                s16 (*iCGlyphTextureHeights)[3]; \
                s16 (*iCGlyphPositionsX)[3]; \
                s16 (*iCGlyphPositionsY)[3]; \
                s16 (*iCGlyphRectSizesX)[3]; \
                s16 (*iCGlyphRectSizesY)[3]; \
                s16 (*iCGlyphScalesX)[3]; \
                s16 (*iCGlyphScalesY)[3]; \
                s16 (*iCGlyphColours)[3][3]; \
                int (*iAmmoPrimColour)[3]; \
                int (*iAmmoEnvColour)[4]; \
                bool* iAmmoForceMaxColour; \
                int (*iAmmoFullColour)[3]; \
                int (*iAmmoEmptyColour)[3]; \
                TexturePtr (*iAmmoTextureTens)[]; \
                s16* iAmmoTextureWidthTens; \
                s16* iAmmoTextureHeightTens; \
                s16 (*iAmmoPositionsTensX)[4]; \
                s16 (*iAmmoPositionsTensY)[4]; \
                s16 (*iAmmoRectSizeTensX)[4]; \
                s16 (*iAmmoRectSizeTensY)[4]; \
                u16* iAmmoUpperScaleTensX; \
                u16* iAmmoUpperScaleTensY; \
                u16* iAmmoLowerScaleTensX; \
                u16* iAmmoLowerScaleTensY; \
                TexturePtr (*iAmmoTextureOnes)[]; \
                s16* iAmmoTextureWidthOnes; \
                s16* iAmmoTextureHeightOnes; \
                s16 (*iAmmoPositionsOnesX)[4]; \
                s16 (*iAmmoPositionsOnesY)[4]; \
                s16 (*iAmmoRectSizeOnesX)[4]; \
                s16 (*iAmmoRectSizeOnesY)[4]; \
                u16* iAmmoUpperScaleOnesX; \
                u16* iAmmoUpperScaleOnesY; \
                u16* iAmmoLowerScaleOnesX; \
                u16* iAmmoLowerScaleOnesY; \
                bool* iBButtonDrawn; \
                bool (*iBButtonEnabled)[8]; \
                RECOMP_IMPORT("mm_recomp_interface_helper", void InterfaceHelper_Init(INIT_PARAMETERS)) \
                RECOMP_CALLBACK("*", recomp_after_play_init) void after_play_init() { InterfaceHelper_Init(INIT_ARGUMENTS); } \


#endif // INTERFACE_HELPER