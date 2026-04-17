/*
 * Graphic.h
 *
 *  Created on: Dec 5, 2021
 *      Author: nds
 */
#pragma once
#include <nds.h>
#include "const.h"

//image fond
#include "menu_ananas.h"
#include "menu_pasteque.h"
#include "menu_reglage.h"
#include "background.h"
#include "fond.h"
#include "background.h"
#include "texte_ananas.h"
#include "texte_pasteque.h"
#include "texte_pause.h"
#include "temps_fini.h"
#include "gameover.h"

//image Sprite
#include "fond.h"
#include "pomme.h"
#include "banane.h"
#include "ananas.h"
#include "flaque.h"
#include "lame.h"

//image nombre
#include "numbers.h"
#include "numbers_score.h"

u16* pomme_SUB;
u16* banane_SUB;
u16* ananas_SUB;
u16* lame_SUB;
u16* flaque_SUB;

enum BUFFER_TYPE
{
    MAIN,
    SUB,
};

void P_Graphics_setup_menu();
void P_Graphics_setup_game();

//backgraund
void P_Graphics_BG_main_menu();
void P_Map16x16_configureBG2_Sub_Menu(int image);
void P_Map16x16_configureBG2_Sub_Game(int image);

//Sprites
void configureSprites();
void Redessine_fruit(int num, int x, int y, u16* type, int fruit);//fruit = 1 si fruit, 0 si flaque
void Redessine_fruit_cache(int num, int x, int y, u16* type, int fruit );
int  Trouve_palette(u16* type);
void Dessine_lame(int x_lame, int y_lame);

//Chifres
void DisplayScore(int i);
void DisplayFaute(int j);



