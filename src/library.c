#include "modding.h"
#include "global.h"

extern bool mButtonsEnabled[4];

RECOMP_EXPORT void mButtonsEnabled_Register(bool (**pointer)[4])
{
  *pointer = &mButtonsEnabled;
}

extern TexturePtr mButtonTextures[4];

RECOMP_EXPORT void mButtonTextures_Register(TexturePtr (**pointer)[4])
{
  *pointer = &mButtonTextures;
}

extern s16 mButtonTexturesWidth[4];

RECOMP_EXPORT void mButtonTexturesWidth_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonTexturesWidth;
}

extern s16 mButtonTexturesHeight[4];

RECOMP_EXPORT void mButtonTexturesHeight_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonTexturesHeight;
}

extern s16 mButtonPositionsX[4];

RECOMP_EXPORT void mButtonPositionsX_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonPositionsX;
}

extern s16 mButtonPositionsY[4];

RECOMP_EXPORT void mButtonPositionsY_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonPositionsY;
}

extern s16 mButtonRectSizesX[4];

RECOMP_EXPORT void mButtonRectSizesX_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonRectSizesX;
}

extern s16 mButtonRectSizesY[4];

RECOMP_EXPORT void mButtonRectSizesY_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonRectSizesY;
}

extern s16 mButtonScalesX[4];

RECOMP_EXPORT void mButtonScalesX_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonScalesX;
}

extern s16 mButtonScalesY[4];

RECOMP_EXPORT void mButtonScalesY_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonScalesY;
}

extern s16 mButtonColours[4][3];

RECOMP_EXPORT void mButtonColours_Register(s16 (**pointer)[4][3])
{
  *pointer = &mButtonColours;
}

extern s16 mButtonAlphas[4];

RECOMP_EXPORT void mButtonAlphas_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonAlphas;
}

extern bool mStartForceEnabled;

RECOMP_EXPORT void mStartForceEnabled_Register(bool (**pointer))
{
  *pointer = &mStartForceEnabled;
}

extern bool mStartButtonEnabled;

RECOMP_EXPORT void mStartButtonEnabled_Register(bool (**pointer))
{
  *pointer = &mStartButtonEnabled;
}

extern TexturePtr mStartButtonTexture;

RECOMP_EXPORT void mStartButtonTexture_Register(TexturePtr (**pointer))
{
  *pointer = &mStartButtonTexture;
}

extern s16 mStartButtonTextureWidth;

RECOMP_EXPORT void mStartButtonTextureWidth_Register(s16 (**pointer))
{
  *pointer = &mStartButtonTextureWidth;
}

extern s16 mStartButtonTextureHeight;

RECOMP_EXPORT void mStartButtonTextureHeight_Register(s16 (**pointer))
{
  *pointer = &mStartButtonTextureHeight;
}

extern s16 mStartButtonPositionX;

RECOMP_EXPORT void mStartButtonPositionX_Register(s16 (**pointer))
{
  *pointer = &mStartButtonPositionX;
}

extern s16 mStartButtonPositionY;

RECOMP_EXPORT void mStartButtonPositionY_Register(s16 (**pointer))
{
  *pointer = &mStartButtonPositionY;
}

extern s16 mStartButtonRectSizeX;

RECOMP_EXPORT void mStartButtonRectSizeX_Register(s16 (**pointer))
{
  *pointer = &mStartButtonRectSizeX;
}

extern s16 mStartButtonRectSizeY;

RECOMP_EXPORT void mStartButtonRectSizeY_Register(s16 (**pointer))
{
  *pointer = &mStartButtonRectSizeY;
}

extern u16 mStartButtonScaleX;

RECOMP_EXPORT void mStartButtonScaleX_Register(u16 (**pointer))
{
  *pointer = &mStartButtonScaleX;
}

extern u16 mStartButtonScaleY;

RECOMP_EXPORT void mStartButtonScaleY_Register(u16 (**pointer))
{
  *pointer = &mStartButtonScaleY;
}

extern s16 mStartButtonColour[3];

RECOMP_EXPORT void mStartButtonColour_Register(s16 (**pointer)[3])
{
  *pointer = &mStartButtonColour;
}

extern bool mStartLabelEnabled;

RECOMP_EXPORT void mStartLabelEnabled_Register(bool (**pointer))
{
  *pointer = &mStartLabelEnabled;
}

extern int mStartLabelPrimColour[3];

RECOMP_EXPORT void mStartLabelPrimColour_Register(int (**pointer)[3])
{
  *pointer = &mStartLabelPrimColour;
}

extern int mStartLabelEnvColour[4];

RECOMP_EXPORT void mStartLabelEnvColour_Register(int (**pointer)[4])
{
  *pointer = &mStartLabelEnvColour;
}

extern TexturePtr mStartLabelTexture;

RECOMP_EXPORT void mStartLabelTexture_Register(TexturePtr (**pointer))
{
  *pointer = &mStartLabelTexture;
}

extern int mStartLabelTextureWidth;

RECOMP_EXPORT void mStartLabelTextureWidth_Register(int (**pointer))
{
  *pointer = &mStartLabelTextureWidth;
}

extern int mStartLabelTextureHeight;

RECOMP_EXPORT void mStartLabelTextureHeight_Register(int (**pointer))
{
  *pointer = &mStartLabelTextureHeight;
}

extern int mStartLabelPositionX;

RECOMP_EXPORT void mStartLabelPositionX_Register(int (**pointer))
{
  *pointer = &mStartLabelPositionX;
}

extern int mStartLabelPositionY;

RECOMP_EXPORT void mStartLabelPositionY_Register(int (**pointer))
{
  *pointer = &mStartLabelPositionY;
}

extern int mStartLabelRectSizeX;

RECOMP_EXPORT void mStartLabelRectSizeX_Register(int (**pointer))
{
  *pointer = &mStartLabelRectSizeX;
}

extern int mStartLabelRectSizeY;

RECOMP_EXPORT void mStartLabelRectSizeY_Register(int (**pointer))
{
  *pointer = &mStartLabelRectSizeY;
}

extern int mStartLabelScaleX;

RECOMP_EXPORT void mStartLabelScaleX_Register(int (**pointer))
{
  *pointer = &mStartLabelScaleX;
}

extern int mStartLabelScaleY;

RECOMP_EXPORT void mStartLabelScaleY_Register(int (**pointer))
{
  *pointer = &mStartLabelScaleY;
}

extern bool mCUpButtonForceEnabled;

RECOMP_EXPORT void mCUpButtonForceEnabled_Register(bool (**pointer))
{
  *pointer = &mCUpButtonForceEnabled;
}

extern bool mCUpButtonEnabled;

RECOMP_EXPORT void mCUpButtonEnabled_Register(bool (**pointer))
{
  *pointer = &mCUpButtonEnabled;
}

extern TexturePtr mCUpButtonTexture;

RECOMP_EXPORT void mCUpButtonTexture_Register(TexturePtr (**pointer))
{
  *pointer = &mCUpButtonTexture;
}

extern int mCUpButtonTextureWidth;

RECOMP_EXPORT void mCUpButtonTextureWidth_Register(int (**pointer))
{
  *pointer = &mCUpButtonTextureWidth;
}

extern int mCUpButtonTextureHeight;

RECOMP_EXPORT void mCUpButtonTextureHeight_Register(int (**pointer))
{
  *pointer = &mCUpButtonTextureHeight;
}

extern s16 mCUpButtonPositionX;

RECOMP_EXPORT void mCUpButtonPositionX_Register(s16 (**pointer))
{
  *pointer = &mCUpButtonPositionX;
}

extern s16 mCUpButtonPositionY;

RECOMP_EXPORT void mCUpButtonPositionY_Register(s16 (**pointer))
{
  *pointer = &mCUpButtonPositionY;
}

extern s16 mCUpButtonRectSizeX;

RECOMP_EXPORT void mCUpButtonRectSizeX_Register(s16 (**pointer))
{
  *pointer = &mCUpButtonRectSizeX;
}

extern s16 mCUpButtonRectSizeY;

RECOMP_EXPORT void mCUpButtonRectSizeY_Register(s16 (**pointer))
{
  *pointer = &mCUpButtonRectSizeY;
}

extern u16 mCUpButtonScaleX;

RECOMP_EXPORT void mCUpButtonScaleX_Register(u16 (**pointer))
{
  *pointer = &mCUpButtonScaleX;
}

extern u16 mCUpButtonScaleY;

RECOMP_EXPORT void mCUpButtonScaleY_Register(u16 (**pointer))
{
  *pointer = &mCUpButtonScaleY;
}

extern s16 mCUpButtonColours[3];

RECOMP_EXPORT void mCUpButtonColours_Register(s16 (**pointer)[3])
{
  *pointer = &mCUpButtonColours;
}

extern bool mCUpLabelEnabled;

RECOMP_EXPORT void mCUpLabelEnabled_Register(bool (**pointer))
{
  *pointer = &mCUpLabelEnabled;
}

extern int mCUpLabelPrimColour[3];

RECOMP_EXPORT void mCUpLabelPrimColour_Register(int (**pointer)[3])
{
  *pointer = &mCUpLabelPrimColour;
}

extern int mCUpLabelEnvColour[4];

RECOMP_EXPORT void mCUpLabelEnvColour_Register(int (**pointer)[4])
{
  *pointer = &mCUpLabelEnvColour;
}

extern TexturePtr mCUpLabelTextures[LANGUAGE_MAX];

RECOMP_EXPORT void mCUpLabelTextures_Register(TexturePtr (**pointer)[LANGUAGE_MAX])
{
  *pointer = &mCUpLabelTextures;
}

extern int mCUpLabelTextureWidths[LANGUAGE_MAX];

RECOMP_EXPORT void mCUpLabelTextureWidths_Register(int (**pointer)[LANGUAGE_MAX])
{
  *pointer = &mCUpLabelTextureWidths;
}

extern int mCUpLabelTextureHeights[LANGUAGE_MAX];

RECOMP_EXPORT void mCUpLabelTextureHeights_Register(int (**pointer)[LANGUAGE_MAX])
{
  *pointer = &mCUpLabelTextureHeights;
}

extern int mCUpLabelPositionX;

RECOMP_EXPORT void mCUpLabelPositionX_Register(int (**pointer))
{
  *pointer = &mCUpLabelPositionX;
}

extern int mCUpLabelPositionY;

RECOMP_EXPORT void mCUpLabelPositionY_Register(int (**pointer))
{
  *pointer = &mCUpLabelPositionY;
}

extern int mCUpLabelRectSizeX;

RECOMP_EXPORT void mCUpLabelRectSizeX_Register(int (**pointer))
{
  *pointer = &mCUpLabelRectSizeX;
}

extern int mCUpLabelRectSizeY;

RECOMP_EXPORT void mCUpLabelRectSizeY_Register(int (**pointer))
{
  *pointer = &mCUpLabelRectSizeY;
}

extern int mCUpLabelScaleX;

RECOMP_EXPORT void mCUpLabelScaleX_Register(int (**pointer))
{
  *pointer = &mCUpLabelScaleX;
}

extern int mCUpLabelScaleY;

RECOMP_EXPORT void mCUpLabelScaleY_Register(int (**pointer))
{
  *pointer = &mCUpLabelScaleY;
}

extern bool mCGlyphsEnabled[3];

RECOMP_EXPORT void mCGlyphsEnabled_Register(bool (**pointer)[3])
{
  *pointer = &mCGlyphsEnabled;
}

extern TexturePtr mCGlyphTextures[3];

RECOMP_EXPORT void mCGlyphTextures_Register(TexturePtr (**pointer)[3])
{
  *pointer = &mCGlyphTextures;
}

extern s16 mCGlyphTextureWidths[3];

RECOMP_EXPORT void mCGlyphTextureWidths_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphTextureWidths;
}

extern s16 mCGlyphTextureHeights[3];

RECOMP_EXPORT void mCGlyphTextureHeights_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphTextureHeights;
}

extern s16 mCGlyphPositionsX[3];

RECOMP_EXPORT void mCGlyphPositionsX_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphPositionsX;
}

extern s16 mCGlyphPositionsY[3];

RECOMP_EXPORT void mCGlyphPositionsY_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphPositionsY;
}

extern s16 mCGlyphRectSizesX[3];

RECOMP_EXPORT void mCGlyphRectSizesX_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphRectSizesX;
}

extern s16 mCGlyphRectSizesY[3];

RECOMP_EXPORT void mCGlyphRectSizesY_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphRectSizesY;
}

extern s16 mCGlyphScalesX[3];

RECOMP_EXPORT void mCGlyphScalesX_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphScalesX;
}

extern s16 mCGlyphScalesY[3];

RECOMP_EXPORT void mCGlyphScalesY_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphScalesY;
}

extern s16 mCGlyphColours[3][3];

RECOMP_EXPORT void mCGlyphColours_Register(s16 (**pointer)[3][3])
{
  *pointer = &mCGlyphColours;
}

extern bool mBButtonDrawn;

RECOMP_EXPORT void mBButtonDrawn_Register(bool (**pointer))
{
  *pointer = &mBButtonDrawn;
}

extern bool mBButtonEnabled[8];

RECOMP_EXPORT void mBButtonEnabled_Register(bool (**pointer)[8])
{
  *pointer = &mBButtonEnabled;
}

extern int mAmmoPrimColour[3];

RECOMP_EXPORT void mAmmoPrimColour_Register(int (**pointer)[3])
{
  *pointer = &mAmmoPrimColour;
}

extern int mAmmoEnvColour[4];

RECOMP_EXPORT void mAmmoEnvColour_Register(int (**pointer)[4])
{
  *pointer = &mAmmoEnvColour;
}

extern bool mAmmoForceMaxColour;

RECOMP_EXPORT void mAmmoForceMaxColour_Register(bool (**pointer))
{
  *pointer = &mAmmoForceMaxColour;
}

extern int mAmmoFullColour[3];

RECOMP_EXPORT void mAmmoFullColour_Register(int (**pointer)[3])
{
  *pointer = &mAmmoFullColour;
}

extern int mAmmoEmptyColour[3];

RECOMP_EXPORT void mAmmoEmptyColour_Register(int (**pointer)[3])
{
  *pointer = &mAmmoEmptyColour;
}

extern TexturePtr mAmmoTextureTens;

RECOMP_EXPORT void mAmmoTextureTens_Register(TexturePtr (**pointer))
{
  *pointer = &mAmmoTextureTens;
}

extern s16 mAmmoTextureWidthTens;

RECOMP_EXPORT void mAmmoTextureWidthTens_Register(s16 (**pointer))
{
  *pointer = &mAmmoTextureWidthTens;
}

extern s16 mAmmoTextureHeightTens;

RECOMP_EXPORT void mAmmoTextureHeightTens_Register(s16 (**pointer))
{
  *pointer = &mAmmoTextureHeightTens;
}

extern s16 mAmmoPositionsTensX[4];

RECOMP_EXPORT void mAmmoPositionsTensX_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoPositionsTensX;
}

extern s16 mAmmoPositionsTensY[4];

RECOMP_EXPORT void mAmmoPositionsTensY_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoPositionsTensY;
}

extern s16 mAmmoRectSizeTensX[4];

RECOMP_EXPORT void mAmmoRectSizeTensX_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoRectSizeTensX;
}

extern s16 mAmmoRectSizeTensY[4];

RECOMP_EXPORT void mAmmoRectSizeTensY_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoRectSizeTensY;
}

extern u16 mAmmoUpperScaleTensX;

RECOMP_EXPORT void mAmmoUpperScaleTensX_Register(u16 (**pointer))
{
  *pointer = &mAmmoUpperScaleTensX;
}

extern u16 mAmmoUpperScaleTensY;

RECOMP_EXPORT void mAmmoUpperScaleTensY_Register(u16 (**pointer))
{
  *pointer = &mAmmoUpperScaleTensY;
}

extern u16 mAmmoLowerScaleTensX;

RECOMP_EXPORT void mAmmoLowerScaleTensX_Register(u16 (**pointer))
{
  *pointer = &mAmmoLowerScaleTensX;
}

extern u16 mAmmoLowerScaleTensY;

RECOMP_EXPORT void mAmmoLowerScaleTensY_Register(u16 (**pointer))
{
  *pointer = &mAmmoLowerScaleTensY;
}

extern TexturePtr mAmmoTextureOnes;

RECOMP_EXPORT void mAmmoTextureOnes_Register(TexturePtr (**pointer))
{
  *pointer = &mAmmoTextureOnes;
}

extern s16 mAmmoTextureWidthOnes;

RECOMP_EXPORT void mAmmoTextureWidthOnes_Register(s16 (**pointer))
{
  *pointer = &mAmmoTextureWidthOnes;
}

extern s16 mAmmoTextureHeightOnes;

RECOMP_EXPORT void mAmmoTextureHeightOnes_Register(s16 (**pointer))
{
  *pointer = &mAmmoTextureHeightOnes;
}

extern s16 mAmmoPositionsOnesX[4];

RECOMP_EXPORT void mAmmoPositionsOnesX_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoPositionsOnesX;
}

extern s16 mAmmoPositionsOnesY[4];

RECOMP_EXPORT void mAmmoPositionsOnesY_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoPositionsOnesY;
}

extern s16 mAmmoRectSizeOnesX[4];

RECOMP_EXPORT void mAmmoRectSizeOnesX_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoRectSizeOnesX;
}

extern s16 mAmmoRectSizeOnesY[4];

RECOMP_EXPORT void mAmmoRectSizeOnesY_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoRectSizeOnesY;
}

extern u16 mAmmoUpperScaleOnesX;

RECOMP_EXPORT void mAmmoUpperScaleOnesX_Register(u16 (**pointer))
{
  *pointer = &mAmmoUpperScaleOnesX;
}

extern u16 mAmmoUpperScaleOnesY;

RECOMP_EXPORT void mAmmoUpperScaleOnesY_Register(u16 (**pointer))
{
  *pointer = &mAmmoUpperScaleOnesY;
}

extern u16 mAmmoLowerScaleOnesX;

RECOMP_EXPORT void mAmmoLowerScaleOnesX_Register(u16 (**pointer))
{
  *pointer = &mAmmoLowerScaleOnesX;
}

extern u16 mAmmoLowerScaleOnesY;

RECOMP_EXPORT void mAmmoLowerScaleOnesY_Register(u16 (**pointer))
{
  *pointer = &mAmmoLowerScaleOnesY;
}