/*
 * Mod_menu.h
 *
 *  Created on: Dec 5, 2021
 *      Author: nds
 */
#include "const.h"
#include "Graphic.h"
#include "Controls.h"
#include "Sound.h"
#include "Mode_game.h"


/*--------------------------- variables du Menu ------------------------------*/
int modeSelect;

/*&&&&&&&&&&&&&&&&&&&&&&&&&&& fonctions du Menu &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/

void Mode_menu();	//fonction praincipale
void Init_menu();

/*-------------------------- fonction de controle ----------------------------*/
void Change_mode_select(int action);
int  Mode_validation(int action);
int  Boutton_appuie();

/*-------------------------- fonction d'affichage ----------------------------*/
void Affiche_mode(int mode);








