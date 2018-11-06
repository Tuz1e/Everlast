#ifndef MATHFUNC_H
#define MATHFUNC_H

int GetAspectRatioHeight(int aWidth, int aWidthRatio, int aHeightRatio)
{
	return ((aWidth / aWidthRatio) * aHeightRatio);
}

int GetAspectRatioWidth(int aHeight, int aWidthRatio, int aHeightRatio) 
{
	return ((aHeight / aHeightRatio)*aWidthRatio);
}

#endif MATHFUNC_H