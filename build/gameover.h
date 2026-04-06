
//{{BLOCK(gameover)

//======================================================================
//
//	gameover, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 769 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 49216 + 1536 = 51264
//
//	Time-stamp: 2022-01-26, 15:11:48
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GAMEOVER_H
#define GRIT_GAMEOVER_H

#define gameoverTilesLen 49216
extern const unsigned int gameoverTiles[12304];

#define gameoverMapLen 1536
extern const unsigned short gameoverMap[768];

#define gameoverPalLen 512
extern const unsigned short gameoverPal[256];

#endif // GRIT_GAMEOVER_H

//}}BLOCK(gameover)
