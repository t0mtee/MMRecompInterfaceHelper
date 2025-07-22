#include "modding.h"
#include "global.h"

extern int mAmmoPrimColour[3];

RECOMP_EXPORT void AmmoPrimColour_Register(int (**pointer)[3])
{
  *pointer = &mAmmoPrimColour;
}

extern int mAmmoEnvColour[4];

RECOMP_EXPORT void AmmoEnvColour_Register(int (**pointer)[4])
{
  *pointer = &mAmmoEnvColour;
}

extern bool mAmmoForceMaxColour;

RECOMP_EXPORT void AmmoForceMaxColour_Register(bool (**pointer))
{
  *pointer = &mAmmoForceMaxColour;
}

extern int mAmmoFullColour[3];

RECOMP_EXPORT void AmmoFullColour_Register(int (**pointer)[3])
{
  *pointer = &mAmmoFullColour;
}

extern int mAmmoEmptyColour[3];

RECOMP_EXPORT void AmmoEmptyColour_Register(int (**pointer)[3])
{
  *pointer = &mAmmoEmptyColour;
}

extern TexturePtr mAmmoTextureTens;

RECOMP_EXPORT void AmmoTextureTens_Register(TexturePtr (**pointer))
{
  *pointer = &mAmmoTextureTens;
}

extern s16 mAmmoTextureWidthTens;

RECOMP_EXPORT void AmmoTextureWidthTens_Register(s16 (**pointer))
{
  *pointer = &mAmmoTextureWidthTens;
}

extern s16 mAmmoTextureHeightTens;

RECOMP_EXPORT void AmmoTextureHeightTens_Register(s16 (**pointer))
{
  *pointer = &mAmmoTextureHeightTens;
}

extern s16 mAmmoPositionsTensX[4];

RECOMP_EXPORT void AmmoPositionsTensX_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoPositionsTensX;
}

extern s16 mAmmoPositionsTensY[4];

RECOMP_EXPORT void AmmoPositionsTensY_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoPositionsTensY;
}

extern s16 mAmmoRectSizeTensX[4];

RECOMP_EXPORT void AmmoRectSizeTensX_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoRectSizeTensX;
}

extern s16 mAmmoRectSizeTensY[4];

RECOMP_EXPORT void AmmoRectSizeTensY_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoRectSizeTensY;
}

extern u16 mAmmoUpperScaleTensX;

RECOMP_EXPORT void AmmoUpperScaleTensX_Register(u16 (**pointer))
{
  *pointer = &mAmmoUpperScaleTensX;
}

extern u16 mAmmoUpperScaleTensY;

RECOMP_EXPORT void AmmoUpperScaleTensY_Register(u16 (**pointer))
{
  *pointer = &mAmmoUpperScaleTensY;
}

extern u16 mAmmoLowerScaleTensX;

RECOMP_EXPORT void AmmoLowerScaleTensX_Register(u16 (**pointer))
{
  *pointer = &mAmmoLowerScaleTensX;
}

extern u16 mAmmoLowerScaleTensY;

RECOMP_EXPORT void AmmoLowerScaleTensY_Register(u16 (**pointer))
{
  *pointer = &mAmmoLowerScaleTensY;
}

extern TexturePtr mAmmoTextureOnes;

RECOMP_EXPORT void AmmoTextureOnes_Register(TexturePtr (**pointer))
{
  *pointer = &mAmmoTextureOnes;
}

extern s16 mAmmoTextureWidthOnes;

RECOMP_EXPORT void AmmoTextureWidthOnes_Register(s16 (**pointer))
{
  *pointer = &mAmmoTextureWidthOnes;
}

extern s16 mAmmoTextureHeightOnes;

RECOMP_EXPORT void AmmoTextureHeightOnes_Register(s16 (**pointer))
{
  *pointer = &mAmmoTextureHeightOnes;
}

extern s16 mAmmoPositionsOnesX[4];

RECOMP_EXPORT void AmmoPositionsOnesX_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoPositionsOnesX;
}

extern s16 mAmmoPositionsOnesY[4];

RECOMP_EXPORT void AmmoPositionsOnesY_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoPositionsOnesY;
}

extern s16 mAmmoRectSizeOnesX[4];

RECOMP_EXPORT void AmmoRectSizeOnesX_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoRectSizeOnesX;
}

extern s16 mAmmoRectSizeOnesY[4];

RECOMP_EXPORT void AmmoRectSizeOnesY_Register(s16 (**pointer)[4])
{
  *pointer = &mAmmoRectSizeOnesY;
}

extern u16 mAmmoUpperScaleOnesX;

RECOMP_EXPORT void AmmoUpperScaleOnesX_Register(u16 (**pointer))
{
  *pointer = &mAmmoUpperScaleOnesX;
}

extern u16 mAmmoUpperScaleOnesY;

RECOMP_EXPORT void AmmoUpperScaleOnesY_Register(u16 (**pointer))
{
  *pointer = &mAmmoUpperScaleOnesY;
}

extern u16 mAmmoLowerScaleOnesX;

RECOMP_EXPORT void AmmoLowerScaleOnesX_Register(u16 (**pointer))
{
  *pointer = &mAmmoLowerScaleOnesX;
}

extern u16 mAmmoLowerScaleOnesY;

RECOMP_EXPORT void AmmoLowerScaleOnesY_Register(u16 (**pointer))
{
  *pointer = &mAmmoLowerScaleOnesY;
}

extern bool mBButtonDrawn;

RECOMP_EXPORT void BButtonDrawn_Register(bool (**pointer))
{
  *pointer = &mBButtonDrawn;
}

extern bool mBButtonEnabled[8];

RECOMP_EXPORT void BButtonEnabled_Register(bool (**pointer)[8])
{
  *pointer = &mBButtonEnabled;
}

extern bool mButtonsEnabled[4];

RECOMP_EXPORT void ButtonsEnabled_Register(bool (**pointer)[4])
{
  *pointer = &mButtonsEnabled;
}

extern TexturePtr mButtonTextures[4];

RECOMP_EXPORT void ButtonTextures_Register(TexturePtr (**pointer)[4])
{
  *pointer = &mButtonTextures;
}

extern s16 mButtonTexturesWidth[4];

RECOMP_EXPORT void ButtonTexturesWidth_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonTexturesWidth;
}

extern s16 mButtonTexturesHeight[4];

RECOMP_EXPORT void ButtonTexturesHeight_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonTexturesHeight;
}

extern s16 mButtonPositionsX[4];

RECOMP_EXPORT void ButtonPositionsX_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonPositionsX;
}

extern s16 mButtonPositionsY[4];

RECOMP_EXPORT void ButtonPositionsY_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonPositionsY;
}

extern s16 mButtonRectSizesX[4];

RECOMP_EXPORT void ButtonRectSizesX_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonRectSizesX;
}

extern s16 mButtonRectSizesY[4];

RECOMP_EXPORT void ButtonRectSizesY_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonRectSizesY;
}

extern s16 mButtonScalesX[4];

RECOMP_EXPORT void ButtonScalesX_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonScalesX;
}

extern s16 mButtonScalesY[4];

RECOMP_EXPORT void ButtonScalesY_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonScalesY;
}

extern s16 mButtonColours[4][3];

RECOMP_EXPORT void ButtonColours_Register(s16 (**pointer)[4][3])
{
  *pointer = &mButtonColours;
}

extern s16 mButtonAlphas[4];

RECOMP_EXPORT void ButtonAlphas_Register(s16 (**pointer)[4])
{
  *pointer = &mButtonAlphas;
}

extern bool mStartForceEnabled;

RECOMP_EXPORT void StartForceEnabled_Register(bool (**pointer))
{
  *pointer = &mStartForceEnabled;
}

extern bool mStartButtonEnabled;

RECOMP_EXPORT void StartButtonEnabled_Register(bool (**pointer))
{
  *pointer = &mStartButtonEnabled;
}

extern TexturePtr mStartButtonTexture;

RECOMP_EXPORT void StartButtonTexture_Register(TexturePtr (**pointer))
{
  *pointer = &mStartButtonTexture;
}

extern s16 mStartButtonTextureWidth;

RECOMP_EXPORT void StartButtonTextureWidth_Register(s16 (**pointer))
{
  *pointer = &mStartButtonTextureWidth;
}

extern s16 mStartButtonTextureHeight;

RECOMP_EXPORT void StartButtonTextureHeight_Register(s16 (**pointer))
{
  *pointer = &mStartButtonTextureHeight;
}

extern s16 mStartButtonPositionX;

RECOMP_EXPORT void StartButtonPositionX_Register(s16 (**pointer))
{
  *pointer = &mStartButtonPositionX;
}

extern s16 mStartButtonPositionY;

RECOMP_EXPORT void StartButtonPositionY_Register(s16 (**pointer))
{
  *pointer = &mStartButtonPositionY;
}

extern s16 mStartButtonRectSizeX;

RECOMP_EXPORT void StartButtonRectSizeX_Register(s16 (**pointer))
{
  *pointer = &mStartButtonRectSizeX;
}

extern s16 mStartButtonRectSizeY;

RECOMP_EXPORT void StartButtonRectSizeY_Register(s16 (**pointer))
{
  *pointer = &mStartButtonRectSizeY;
}

extern u16 mStartButtonScaleX;

RECOMP_EXPORT void StartButtonScaleX_Register(u16 (**pointer))
{
  *pointer = &mStartButtonScaleX;
}

extern u16 mStartButtonScaleY;

RECOMP_EXPORT void StartButtonScaleY_Register(u16 (**pointer))
{
  *pointer = &mStartButtonScaleY;
}

extern s16 mStartButtonColour[3];

RECOMP_EXPORT void StartButtonColour_Register(s16 (**pointer)[3])
{
  *pointer = &mStartButtonColour;
}

extern bool mStartLabelEnabled;

RECOMP_EXPORT void StartLabelEnabled_Register(bool (**pointer))
{
  *pointer = &mStartLabelEnabled;
}

extern int mStartLabelPrimColour[3];

RECOMP_EXPORT void StartLabelPrimColour_Register(int (**pointer)[3])
{
  *pointer = &mStartLabelPrimColour;
}

extern int mStartLabelEnvColour[4];

RECOMP_EXPORT void StartLabelEnvColour_Register(int (**pointer)[4])
{
  *pointer = &mStartLabelEnvColour;
}

extern TexturePtr mStartLabelTexture;

RECOMP_EXPORT void StartLabelTexture_Register(TexturePtr (**pointer))
{
  *pointer = &mStartLabelTexture;
}

extern int mStartLabelTextureWidth;

RECOMP_EXPORT void StartLabelTextureWidth_Register(int (**pointer))
{
  *pointer = &mStartLabelTextureWidth;
}

extern int mStartLabelTextureHeight;

RECOMP_EXPORT void StartLabelTextureHeight_Register(int (**pointer))
{
  *pointer = &mStartLabelTextureHeight;
}

extern int mStartLabelPositionX;

RECOMP_EXPORT void StartLabelPositionX_Register(int (**pointer))
{
  *pointer = &mStartLabelPositionX;
}

extern int mStartLabelPositionY;

RECOMP_EXPORT void StartLabelPositionY_Register(int (**pointer))
{
  *pointer = &mStartLabelPositionY;
}

extern int mStartLabelRectSizeX;

RECOMP_EXPORT void StartLabelRectSizeX_Register(int (**pointer))
{
  *pointer = &mStartLabelRectSizeX;
}

extern int mStartLabelRectSizeY;

RECOMP_EXPORT void StartLabelRectSizeY_Register(int (**pointer))
{
  *pointer = &mStartLabelRectSizeY;
}

extern int mStartLabelScaleX;

RECOMP_EXPORT void StartLabelScaleX_Register(int (**pointer))
{
  *pointer = &mStartLabelScaleX;
}

extern int mStartLabelScaleY;

RECOMP_EXPORT void StartLabelScaleY_Register(int (**pointer))
{
  *pointer = &mStartLabelScaleY;
}

extern bool mCUpButtonForceEnabled;

RECOMP_EXPORT void CUpButtonForceEnabled_Register(bool (**pointer))
{
  *pointer = &mCUpButtonForceEnabled;
}

extern bool mCUpButtonEnabled;

RECOMP_EXPORT void CUpButtonEnabled_Register(bool (**pointer))
{
  *pointer = &mCUpButtonEnabled;
}

extern TexturePtr mCUpButtonTexture;

RECOMP_EXPORT void CUpButtonTexture_Register(TexturePtr (**pointer))
{
  *pointer = &mCUpButtonTexture;
}

extern int mCUpButtonTextureWidth;

RECOMP_EXPORT void CUpButtonTextureWidth_Register(int (**pointer))
{
  *pointer = &mCUpButtonTextureWidth;
}

extern int mCUpButtonTextureHeight;

RECOMP_EXPORT void CUpButtonTextureHeight_Register(int (**pointer))
{
  *pointer = &mCUpButtonTextureHeight;
}

extern s16 mCUpButtonPositionX;

RECOMP_EXPORT void CUpButtonPositionX_Register(s16 (**pointer))
{
  *pointer = &mCUpButtonPositionX;
}

extern s16 mCUpButtonPositionY;

RECOMP_EXPORT void CUpButtonPositionY_Register(s16 (**pointer))
{
  *pointer = &mCUpButtonPositionY;
}

extern s16 mCUpButtonRectSizeX;

RECOMP_EXPORT void CUpButtonRectSizeX_Register(s16 (**pointer))
{
  *pointer = &mCUpButtonRectSizeX;
}

extern s16 mCUpButtonRectSizeY;

RECOMP_EXPORT void CUpButtonRectSizeY_Register(s16 (**pointer))
{
  *pointer = &mCUpButtonRectSizeY;
}

extern u16 mCUpButtonScaleX;

RECOMP_EXPORT void CUpButtonScaleX_Register(u16 (**pointer))
{
  *pointer = &mCUpButtonScaleX;
}

extern u16 mCUpButtonScaleY;

RECOMP_EXPORT void CUpButtonScaleY_Register(u16 (**pointer))
{
  *pointer = &mCUpButtonScaleY;
}

extern s16 mCUpButtonColours[3];

RECOMP_EXPORT void CUpButtonColours_Register(s16 (**pointer)[3])
{
  *pointer = &mCUpButtonColours;
}

extern bool mCUpLabelEnabled;

RECOMP_EXPORT void CUpLabelEnabled_Register(bool (**pointer))
{
  *pointer = &mCUpLabelEnabled;
}

extern int mCUpLabelPrimColour[3];

RECOMP_EXPORT void CUpLabelPrimColour_Register(int (**pointer)[3])
{
  *pointer = &mCUpLabelPrimColour;
}

extern int mCUpLabelEnvColour[4];

RECOMP_EXPORT void CUpLabelEnvColour_Register(int (**pointer)[4])
{
  *pointer = &mCUpLabelEnvColour;
}

extern TexturePtr mCUpLabelTextures[LANGUAGE_MAX];

RECOMP_EXPORT void CUpLabelTextures_Register(TexturePtr (**pointer)[LANGUAGE_MAX])
{
  *pointer = &mCUpLabelTextures;
}

extern int mCUpLabelTextureWidths[LANGUAGE_MAX];

RECOMP_EXPORT void CUpLabelTextureWidths_Register(int (**pointer)[LANGUAGE_MAX])
{
  *pointer = &mCUpLabelTextureWidths;
}

extern int mCUpLabelTextureHeights[LANGUAGE_MAX];

RECOMP_EXPORT void CUpLabelTextureHeights_Register(int (**pointer)[LANGUAGE_MAX])
{
  *pointer = &mCUpLabelTextureHeights;
}

extern int mCUpLabelPositionX;

RECOMP_EXPORT void CUpLabelPositionX_Register(int (**pointer))
{
  *pointer = &mCUpLabelPositionX;
}

extern int mCUpLabelPositionY;

RECOMP_EXPORT void CUpLabelPositionY_Register(int (**pointer))
{
  *pointer = &mCUpLabelPositionY;
}

extern int mCUpLabelRectSizeX;

RECOMP_EXPORT void CUpLabelRectSizeX_Register(int (**pointer))
{
  *pointer = &mCUpLabelRectSizeX;
}

extern int mCUpLabelRectSizeY;

RECOMP_EXPORT void CUpLabelRectSizeY_Register(int (**pointer))
{
  *pointer = &mCUpLabelRectSizeY;
}

extern int mCUpLabelScaleX;

RECOMP_EXPORT void CUpLabelScaleX_Register(int (**pointer))
{
  *pointer = &mCUpLabelScaleX;
}

extern int mCUpLabelScaleY;

RECOMP_EXPORT void CUpLabelScaleY_Register(int (**pointer))
{
  *pointer = &mCUpLabelScaleY;
}

extern bool mCGlyphsEnabled[3];

RECOMP_EXPORT void CGlyphsEnabled_Register(bool (**pointer)[3])
{
  *pointer = &mCGlyphsEnabled;
}

extern TexturePtr mCGlyphTextures[3];

RECOMP_EXPORT void CGlyphTextures_Register(TexturePtr (**pointer)[3])
{
  *pointer = &mCGlyphTextures;
}

extern s16 mCGlyphTextureWidths[3];

RECOMP_EXPORT void CGlyphTextureWidths_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphTextureWidths;
}

extern s16 mCGlyphTextureHeights[3];

RECOMP_EXPORT void CGlyphTextureHeights_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphTextureHeights;
}

extern s16 mCGlyphPositionsX[3];

RECOMP_EXPORT void CGlyphPositionsX_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphPositionsX;
}

extern s16 mCGlyphPositionsY[3];

RECOMP_EXPORT void CGlyphPositionsY_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphPositionsY;
}

extern s16 mCGlyphRectSizesX[3];

RECOMP_EXPORT void CGlyphRectSizesX_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphRectSizesX;
}

extern s16 mCGlyphRectSizesY[3];

RECOMP_EXPORT void CGlyphRectSizesY_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphRectSizesY;
}

extern s16 mCGlyphScalesX[3];

RECOMP_EXPORT void CGlyphScalesX_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphScalesX;
}

extern s16 mCGlyphScalesY[3];

RECOMP_EXPORT void CGlyphScalesY_Register(s16 (**pointer)[3])
{
  *pointer = &mCGlyphScalesY;
}

extern s16 mCGlyphColours[3][3];

RECOMP_EXPORT void CGlyphColours_Register(s16 (**pointer)[3][3])
{
  *pointer = &mCGlyphColours;
}

extern TexturePtr mItemIconTextureOverride;

RECOMP_EXPORT void ItemIconTextureOverride_Register(TexturePtr (**pointer))
{
  *pointer = &mItemIconTextureOverride;
}

extern int mItemIconTextureWidth;

RECOMP_EXPORT void ItemIconTextureWidth_Register(int (**pointer))
{
  *pointer = &mItemIconTextureWidth;
}

extern int mItemIconTextureHeight;

RECOMP_EXPORT void ItemIconTextureHeight_Register(int (**pointer))
{
  *pointer = &mItemIconTextureHeight;
}

extern s16 mItemIconPositionsX[];

RECOMP_EXPORT void ItemIconPositionsX_Register(s16 (**pointer)[])
{
  *pointer = &mItemIconPositionsX;
}

extern s16 mItemIconPositionsY[];

RECOMP_EXPORT void ItemIconPositionsY_Register(s16 (**pointer)[])
{
  *pointer = &mItemIconPositionsY;
}

extern s16 mItemIconRectSizesX[];

RECOMP_EXPORT void ItemIconRectSizesX_Register(s16 (**pointer)[])
{
  *pointer = &mItemIconRectSizesX;
}

extern s16 mItemIconRectSizesY[];

RECOMP_EXPORT void ItemIconRectSizesY_Register(s16 (**pointer)[])
{
  *pointer = &mItemIconRectSizesY;
}

extern s16 mItemIconTextureDimensions[];

RECOMP_EXPORT void ItemIconTextureDimensions_Register(s16 (**pointer)[])
{
  *pointer = &mItemIconTextureDimensions;
}

extern s16 mItemIconTextureScales[];

RECOMP_EXPORT void ItemIconTextureScales_Register(s16 (**pointer)[])
{
  *pointer = &mItemIconTextureScales;
}