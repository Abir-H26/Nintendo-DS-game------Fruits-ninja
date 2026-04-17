/*
 * mode_ananas.h
 *
 *  Created on: Jan 2, 2022
 *      Author: nds
 */

#include <nds.h>
#include <stdio.h>

#include "const.h"
#include "Graphic.h"
#include "Controls.h"
#include "Sound.h"
#include "chrono_display.h"
#include "stdlib.h"
#include "time.h"

/*--------------------------- variables du Menu ------------------------------*/
int gameState;
int mode_jeu;

enum {INIT, PLAY, PAUSE, STOP}; //Game state variable
enum {ANANAS, PASTEQUE, NOP}; //Mode de jeu variable

int score;
int faute;

//Pointer to the graphic buffer where to store the sprite


//paramètre d'apparition du prochin fruit
int nb_fruit; // de 1 ä 4
int prochin_fruit;//nb de pas apres quoi apparetera un nouveau fruit
int prochin_fruit_min ;
int compte_temps;

//paramètre des fruit et flaque
int  x_fruit[NB_DE_FRUIT_MAX], y_fruit[NB_DE_FRUIT_MAX], vitesse[NB_DE_FRUIT_MAX];
u16* type_fruit[NB_DE_FRUIT_MAX];
int  compte_flaque[NB_FLAQUE_MAX];

//paramètre lame
int x_lame, y_lame;

/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& Fonctions &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*---------------------------Fonctions praincipales---------------------------*/
void Mode_ananas();
void Mode_pasteque();

/*-----------------------Fonctions de gestion des fruit-----------------------*/
void Mise_a_jour_fruit();
void Calcule_temps_fruit();
void Dessent_tout_fruit();
void Dessent_fruit(int num_fruit);
void Ajoute_fruit();

/*-----------------------Fonctions de gestion de la lame----------------------*/
void Gere_lame();
void Trouve_pos_lame();
void fruit_coup();
void Gere_disparition_flaque();

/*---------------------------routine d'interuption----------------------------*/

void IRQ_initialize();
void Disable_iterup();
void ISR_countdown_timer();
void ISR_VBlank();

void ISR_Keys();

