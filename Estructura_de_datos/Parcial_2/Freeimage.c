#include "FreeImage.h"

int main(int argc, char* argv[])
{
	FIBITMAP *hDIB24bpp = FreeImage_Load(FIF_BMP, "test.bmp", 0);
	if (hDIB24bpp)
	{
		// color-quantize 24bpp (results in a 8bpp bitmap to set transparency)
		FIBITMAP *hDIB8bpp = FreeImage_ColorQuantize(hDIB24bpp, FIQ_WUQUANT);
		// get palette and find bright green
		RGBQUAD *Palette = FreeImage_GetPalette(hDIB8bpp);
		BYTE
		Transparency[256];
		for(unsigned i = 0; i < 256; i++)
		{
			Transparency[i] = 0xFF;
			if (Palette[i].rgbGreen >= 0xFE && Palette[i].rgbBlue == 0x00 && Palette[i].rgbRed== 0x00)
			{
				Transparency[i] = 0x00;
			}
		}
		// set the tranparency table
		FreeImage_SetTransparencyTable(hDIB8bpp, Transparency, 256);
		// save 8bpp image as transparent PNG
		FreeImage_Save(FIF_PNG, hDIB8bpp, "test.png", 0);
		FreeImage_Unload(hDIB24bpp);
		FreeImage_Unload(hDIB8bpp);
	}
	return 0;
}
