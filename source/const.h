/*
 * const.h
 *
 *  Created on: Dec 5, 2021
 *      Author: nds
 */

//couleurs
#define	RED ARGB16(1,31,0,0)
#define GREEN ARGB16(1,0,31,0)
#define	BLUE ARGB16(1,0,0,31)
#define	YELLOW ARGB16(1,31,31,0)
#define	WHITE ARGB16(1,31,31,31)
#define	BLACK ARGB16(1,0,0,0)

//boutton
#define ACTION_LEFT 1
#define ACTION_RIGHT 2
#define ACTION_A 3

//menu dimantion
#define X_G_ANANAS 5
#define X_D_ANANAS 125
#define Y_H_ANANAS 58
#define Y_B_ANANAS 117

#define X_G_PASTEQUE 134
#define X_D_PASTEQUE 251

#define X_G_REGLAGE 232
#define Y_B_REGLAGE 24

//mode du menu
#define MODE_ANANAS		1
#define MODE_PASTEQUE	2
#define MODE_REGLAGE	3

//image sub du jeu
#define IMAGE_FOND 				1
#define IMAGE_REGLE_PASTEQUE 	2
#define IMAGE_REGLE_ANANAS 		3
#define IMAGE_PAUSE 			4
#define IMAGE_GAME_OVER			5
#define IMAGE_TEMPS_FINI		6




//Sprites
#define SCREEN_WIDTH	256
#define	SCREEN_HEIGHT	192

#define	SPRITE_WIDTH	32
#define	SPRITE_HEIGHT	32

//reglage du jeu
#define	TEMPS_PROCHUN_FRUIT		 30

#define	TEMPS_PROCHUN_FRUIT_INIT 30

#define VITESSE_FRUIT_MAX	3

#define	NB_TYPE_FRUIT		3
#define	NB_DE_FRUIT_MAX		3

#define NB_FLAQUE_MAX 		10
#define DELAY_FLAQUE 		10

#define NB_FAUTE_MAX 		5
