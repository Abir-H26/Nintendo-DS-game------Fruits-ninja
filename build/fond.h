
//{{BLOCK(fond)

//======================================================================
//
//	fond, 256x192@8, 
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

#ifndef GRIT_FOND_H
#define GRIT_FOND_H

#define fondTilesLen 49216
extern const unsigned int fondTiles[12304];

#define fondMapLen 1536
extern const unsigned short fondMap[768];

#define fondPalLen 512
extern const unsigned short fondPal[256];

#endif // GRIT_FOND_H

//}}BLOCK(fond)
