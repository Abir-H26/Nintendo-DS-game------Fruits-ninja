/*
 * Graphic.c
 *
 *  Created on: Dec 5, 2021
 *      Author: nds
 */
#include "Graphic.h"

void P_Graphics_setup_menu()
{
	//MAIN
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG; //Bank for the main engine
	//Configure the main engine in mode 5 (2D) and activate Background 0
	REG_DISPCNT = MODE_5_2D | DISPLAY_BG0_ACTIVE;

	//SUB
	//Enable a proper RAM memory bank for sub engine
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
	//Configure the sub engine in mode 5 (2D) and activate Background 2
	REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG2_ACTIVE;
}

void P_Graphics_setup_game()
{
	//MAIN
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE ;

	BGCTRL[0] = BG_COLOR_256 | BG_MAP_BASE(24) | BG_TILE_BASE(4) | BG_32x32;

	swiCopy(numbers_scoreTiles, BG_TILE_RAM(4), numbers_scoreTilesLen/2);
	swiCopy(numbers_scorePal, BG_PALETTE, numbers_scorePalLen/2);
	swiCopy(numbers_scoreMap, BG_MAP_RAM(24), numbers_scoreMapLen/2);

	//SUB
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG2_ACTIVE ;

		int i = 32*32;
		while(i--)
			BG_MAP_RAM(24)[i] = 0;
}


void P_Graphics_BG_main_menu()
{
	BGCTRL[0] = BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32 | BG_COLOR_256;

	//Copy data to display background paysage
	swiCopy(backgroundMap, BG_MAP_RAM(0), backgroundMapLen/2);
	swiCopy(backgroundTiles, BG_TILE_RAM(1), backgroundTilesLen/2);
	swiCopy(backgroundPal, BG_PALETTE, backgroundPalLen/2);
}

void P_Map16x16_configureBG2_Sub_Menu(int image)// pas posible de passö en parametre unsigned short Pal, unsigned int PalLen,  unsigned short Bitmap, unsigned int BitmapLen)
{

	BGCTRL_SUB[2] = BG_BMP_BASE(0) | ((unsigned short int)BgSize_B8_256x256);

	//Affine Marix Transformation
	REG_BG2PA_SUB = 256;
	REG_BG2PC_SUB = 0;
	REG_BG2PB_SUB = 0;
	REG_BG2PD_SUB = 256;


    switch(image)
    {
    	case 1:	//IMAGE_MENU_MODE_ANANAS
    		swiCopy(menu_ananasPal, BG_PALETTE_SUB, menu_ananasPalLen);
    		swiCopy(menu_ananasBitmap, BG_GFX_SUB, menu_ananasBitmapLen);
    		break;

    	case 2:	//IMAGE_MENU_MODE_PASTEQUE
			swiCopy(menu_pastequePal, BG_PALETTE_SUB, menu_pastequePalLen);
			swiCopy(menu_pastequeBitmap, BG_GFX_SUB, menu_pastequeBitmapLen);
			break;

    	case 3:	//IMAGE_MENU_MODE_REGLAGE
			swiCopy(menu_reglagePal, BG_PALETTE_SUB, menu_reglagePalLen);
			swiCopy(menu_reglageBitmap, BG_GFX_SUB, menu_reglageBitmapLen);
			break;

    }

}

void P_Map16x16_configureBG2_Sub_Game(int image)
{
	BGCTRL_SUB[2] = BG_COLOR_256 | BG_MAP_BASE(24) | BG_TILE_BASE(4) | BG_32x32;

    switch(image)
    {
    	case 1:	//IMAGE_FOND
    		swiCopy(fondTiles, BG_TILE_RAM_SUB(4), fondTilesLen/2);
    		swiCopy(fondPal, BG_PALETTE_SUB, fondPalLen/2);
    		swiCopy(fondMap, BG_MAP_RAM_SUB(24), fondMapLen/2);
    		break;

    	case 2:	//IMAGE_MENU_MODE_PASTEQUE
    		swiCopy(texte_pastequeTiles, BG_TILE_RAM_SUB(4), texte_pastequeTilesLen/2);
			swiCopy(texte_pastequePal, BG_PALETTE_SUB, texte_pastequePalLen/2);
			swiCopy(texte_pastequeMap, BG_MAP_RAM_SUB(24), texte_pastequeMapLen/2);
			break;

    	case 3:	//IMAGE_MENU_MODE_ANANAS
    		swiCopy(texte_ananasTiles, BG_TILE_RAM_SUB(4), texte_ananasTilesLen/2);
			swiCopy(texte_ananasPal, BG_PALETTE_SUB, texte_ananasPalLen/2);
			swiCopy(texte_ananasMap, BG_MAP_RAM_SUB(24), texte_ananasMapLen/2);
			break;

    	case 4:	//IMAGE_MENU_MODE_PAUSE
			swiCopy(texte_pauseTiles, BG_TILE_RAM_SUB(4), texte_pauseTilesLen/2);
			swiCopy(texte_pausePal, BG_PALETTE_SUB, texte_pausePalLen/2);
			swiCopy(texte_pauseMap, BG_MAP_RAM_SUB(24), texte_pauseMapLen/2);
			break;

    	case 5: //IMAGE_GAME_OVER
    		swiCopy(gameoverTiles, BG_TILE_RAM_SUB(4), gameoverTilesLen/2);
			swiCopy(gameoverPal, BG_PALETTE_SUB, gameoverPalLen/2);
			swiCopy(gameoverMap, BG_MAP_RAM_SUB(24), gameoverMapLen/2);
    		break;

    	case 6: //IMAGE_TEMPS_FINI
    		swiCopy(temps_finiTiles, BG_TILE_RAM_SUB(4), temps_finiTilesLen/2);
			swiCopy(temps_finiPal, BG_PALETTE_SUB, temps_finiPalLen/2);
			swiCopy(temps_finiMap, BG_MAP_RAM_SUB(24), temps_finiMapLen/2);
    		break;
    }
}

void configureSprites()
{
	//Set up memory bank to work in sprite mode (offset since we are using VRAM A for backgrounds)
	VRAM_D_CR = VRAM_ENABLE | VRAM_D_SUB_SPRITE;

	//Initialize sprite manager and the engine
	oamInit(&oamSub, SpriteMapping_1D_32, false);

	//Allocate space for the graphic to show in the sprite
	pomme_SUB = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_16Color );
	banane_SUB = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_16Color );
	ananas_SUB = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_16Color );
	flaque_SUB = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_16Color );
	lame_SUB = oamAllocateGfx(&oamSub, SpriteSize_8x8, SpriteColorFormat_16Color );

	dmaCopy(pommePal,SPRITE_PALETTE_SUB,pommePalLen);
	dmaCopy(bananePal,&SPRITE_PALETTE_SUB[pommePalLen/2],bananePalLen);
	dmaCopy(ananasPal,&SPRITE_PALETTE_SUB[(pommePalLen+bananePalLen)/2],ananasPalLen);
	dmaCopy(lamePal,&SPRITE_PALETTE_SUB[(pommePalLen+bananePalLen+ananasPalLen)/2],lamePalLen);
	dmaCopy(flaquePal,&SPRITE_PALETTE_SUB[(pommePalLen+bananePalLen+ananasPalLen+lamePalLen)/2],flaquePalLen);

	dmaCopy(pommeTiles,pomme_SUB,pommeTilesLen);
	dmaCopy(bananeTiles,banane_SUB,bananeTilesLen);
	dmaCopy(ananasTiles,ananas_SUB,ananasTilesLen);
	dmaCopy(lameTiles,lame_SUB,lameTilesLen);
	dmaCopy(flaqueTiles,flaque_SUB,flaqueTilesLen);
}

void Redessine_fruit(int num, int x, int y, u16* type, int fruit)
{
	int palette = Trouve_palette(type);
	if (fruit == 0) type = flaque_SUB;

	oamSet(	&oamSub, 	// oam handler
			num,				// Number of sprite
			x, y,// Coordinates
			0,				// Priority
			palette,				// Palette to use
			SpriteSize_32x32,			// Sprite size
			SpriteColorFormat_16Color,	// Color format
			type,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			false,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
			);
}

void Redessine_fruit_cache(int num, int x, int y, u16* type, int fruit ){
	int palette = Trouve_palette(type);
	if (fruit == 0) type = flaque_SUB;

	oamSet(	&oamSub, 	// oam handler
			num,				// Number of sprite
			x, y,// Coordinates
			0,				// Priority
			palette,				// Palette to use
			SpriteSize_32x32,			// Sprite size
			SpriteColorFormat_16Color,	// Color format
			type,			// Loaded graphic to display
			-1,				// Affine rotation to use (-1 none)
			false,			// Double size if rotating
			true,			// Hide this sprite
			false, false,	// Horizontal or vertical flip
			false			// Mosaic
			);
}

int Trouve_palette(u16* type)
{
	int palette;

	if (type == pomme_SUB) palette = 0;
	else if(type == banane_SUB) palette = 1;
	else if(type == ananas_SUB) palette = 2;
	else if(type == flaque_SUB) palette = 4;

	return palette;
}

void Dessine_lame(int x_lame, int y_lame)
{
	if(x_lame == 0 && y_lame == 0)
	{
		oamSet(	&oamSub, 	// oam handler
					4,				// Number of sprite
					500, 500,// Coordinates
					0,				// Priority
					3,				// Palette to use
					SpriteSize_8x8,			// Sprite size
					SpriteColorFormat_16Color,	// Color format
					lame_SUB,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					false,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
					);
	}
	else
	{
		oamSet(	&oamSub, 	// oam handler
					4,				// Number of sprite
					x_lame-4, y_lame-4,// Coordinates
					0,				// Priority
					3,				// Palette to use
					SpriteSize_8x8,			// Sprite size
					SpriteColorFormat_16Color,	// Color format
					lame_SUB,			// Loaded graphic to display
					-1,				// Affine rotation to use (-1 none)
					false,			// Double size if rotating
					false,			// Hide this sprite
					false, false,	// Horizontal or vertical flip
					false			// Mosaic
					);
	}
}

void DisplayScore(int i)
{
	int n = i;
	int hundred = 0, ten = 0, unit = 0;
	if (n >= 100) hundred = n / 100;
	if ((n % 100) <= 9) {
		ten = 0;
		unit = n % 100;
	} else {
		unit = (n%100)%10;
		ten = (n%100) / 10;
	}

	BG_MAP_RAM(24)[1+20*32] = numbers_scoreMap[2*hundred]; // hundreds
	BG_MAP_RAM(24)[1+21*32] = numbers_scoreMap[2*hundred+1];
	BG_MAP_RAM(24)[2+20*32] = numbers_scoreMap[2*ten];// tens
	BG_MAP_RAM(24)[2+21*32] = numbers_scoreMap[2*ten+1];
	BG_MAP_RAM(24)[3+20*32] = numbers_scoreMap[2*unit];// unit
	BG_MAP_RAM(24)[3+21*32] = numbers_scoreMap[2*unit+1];
}

void DisplayFaute(int j)
{
	BG_MAP_RAM(24)[30+20*32] = numbers_scoreMap[2*j];// unit
	BG_MAP_RAM(24)[30+21*32] = numbers_scoreMap[2*j+1];
}
