
//{{BLOCK(background)

//======================================================================
//
//	background, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 768 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 49152 + 1536 = 51200
//
//	Time-stamp: 2022-01-26, 15:11:48
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 49152
extern const unsigned int backgroundTiles[12288];

#define backgroundMapLen 1536
extern const unsigned short backgroundMap[768];

#define backgroundPalLen 512
extern const unsigned short backgroundPal[256];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)
