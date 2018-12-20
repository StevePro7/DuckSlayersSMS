#include "main.h"

unsigned int BG_TILE_WIDTH = 50;		// 400px wide / 8px tiles
unsigned int X_TILE_MAX = 32;
unsigned int Y_TILE_MAX = 24;

unsigned int scroll = 0;
unsigned int scrollDivided8 = 0;
unsigned int scrollRight = 0;
unsigned int scrollRightDivided8 = 0;
unsigned int xtile = 0;
unsigned int ytile = 0;


void loadAssets(void)
{
	SMS_loadPSGaidencompressedTiles(hockey__tiles__psgcompr, 0);

	for (ytile = 0; ytile < Y_TILE_MAX; ytile++)
	{
		SMS_loadTileMap(0, ytile, (void *)&hockey__tilemap__bin[BG_TILE_WIDTH*ytile * 2], X_TILE_MAX * 2);  // 32 tiles * 2 bytes each 
	}
	
	SMS_loadBGPalette((void *)hockey__palette__bin);
}

void main(void)
{
	unsigned int ks;
	const unsigned char delta = 2;

	SMS_VDPturnOnFeature(VDPFEATURE_HIDEFIRSTCOL);
	loadAssets();
	SMS_displayOn();

	for (;;)
	{
		SMS_waitForVBlank();
		ks = SMS_getKeysStatus();

		if ((ks & PORT_A_KEY_RIGHT) && ((scrollRightDivided8 < (BG_TILE_WIDTH - X_TILE_MAX)) /*|| (scroll == 0)*/))
		{
			scroll -= delta;
			scrollRight += delta;
			//scroll--;
			//scrollRight++;
			scrollRightDivided8 = scrollRight / 8;
			SMS_setBGScrollX(scroll);

			// This works but does not update the top row
			if ((scrollRight % 8) == delta)
			{
				// This works except the top row which doesn't seem to scroll.
				for (ytile = 1; ytile < Y_TILE_MAX; ytile++)
				{
					SMS_loadTileMap(X_TILE_MAX + scrollRightDivided8, ytile - 1, (void *)&hockey__tilemap__bin[((BG_TILE_WIDTH*ytile) + (X_TILE_MAX + scrollRightDivided8)) * 2], 2);  // 1 tile * 2 bytes 
				}
			}
		}
		else if ((ks & PORT_A_KEY_LEFT) && (scrollRight > 0))
		{
			scroll += delta;
			scrollRight -= delta;
			scrollRightDivided8 = scrollRight / 8;
			SMS_setBGScrollX(scroll);

			if ((scrollRight % 8) == 0)
			{
				// This works except the top row which doesn't seem to scroll.
				for (ytile = 1; ytile < Y_TILE_MAX; ytile++)
				{
					SMS_loadTileMap(X_TILE_MAX + scrollRightDivided8, ytile - 1, (void *)&hockey__tilemap__bin[((BG_TILE_WIDTH*ytile) + scrollRightDivided8) * 2], 2);  // 1 tile * 2 bytes 
				}
			}
		}
	}
}

#ifdef _CONSOLE
#else
	SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
	SMS_EMBED_SDSC_HEADER(1, 0, 2017, 3, 17, "StevePro Studios", "Candy Kid Demo", "DESC");
#endif

