/*
 * Mod_menu.c
 *
 *  Created on: Dec 5, 2021
 *      Author: nds
 */
#include "Mode_menu.h"

void Mode_menu() //fonction praincipale
{
	Init_menu();

	int validation;
	int action;

	while (1)
	{
		action = HandleInput();			//verifier les boutton appuié
		Change_mode_select(action);		//Changer affichage si il faut
		validation = Mode_validation(action);//si il faut validé un mode

		switch (validation)
		{
		case 1:
			Mode_ananas();//démarré jeu
			//des le jeu fini remettre tout les reglage du menu
			Init_menu();
			break;

		case 2:
			Mode_pasteque();//démarré jeu
			//des le jeu fini remettre tout les reglage du menu
			Init_menu();
			break;

		case 3:
			Affiche_mode(4);// la foction n'a pas été écrite
			break;

		}
		swiWaitForVBlank();
	}
}

void Init_menu()
{
	Audio_PlayMusic();
	P_Graphics_setup_menu();
	P_Graphics_BG_main_menu();

	modeSelect = MODE_ANANAS;
	Affiche_mode(modeSelect);
}

/*-------------------------- fonction de controle ----------------------------*/
/*Si le boutton RRIGHT ou LEFT à été pressé cette fonction change le mode
 * séléctionné ainci que l'affichage
 */
void Change_mode_select(int action)
{
	if (action == ACTION_RIGHT)			// Bouton gauche pressée
	{
		Audio_PlaySound_Menu(SFX_SWISH);

		if (modeSelect < MODE_REGLAGE)
		{
			modeSelect ++;
		}
		else
		{
			modeSelect = MODE_ANANAS;
		}
		Affiche_mode(modeSelect);


	} else if (action == ACTION_LEFT) 	// Bouton droit pressée
	{
		Audio_PlaySound_Menu(SFX_SWISH);

		if (modeSelect > MODE_ANANAS)
		{
			modeSelect --;
		}
		else modeSelect = MODE_REGLAGE;
		Affiche_mode(modeSelect);
	}
}

/* renvoie MODE_ANANAS, MODE_PASTEQUE ou MODE_REGLAGE si le boutton A a été
 * appuié  (alors c'est le mode acctif) ou si on a cliqué sur un boutton
 * du tache screen. si rien a été touché elle renvoie 0 (scrutation)
 */
int Mode_validation(int action)
{
	int modeValid;

	if (action == ACTION_A)
	{
		modeValid = modeSelect;
	}
	else
	{
		modeValid = Boutton_appuie();
	}

	return modeValid;
}

/* renvoie MODE_ANANAS, MODE_PASTEQUE ou MODE_REGLAGE si le boutton a été appuié
 * sur l'écran
 */
int Boutton_appuie()
{
	touchPosition position = Calcule_coord();

	u16 x = position.px;
	u16 y = position.py;
	int mode_appuie = 0;


	if (y > Y_H_ANANAS && y < Y_B_ANANAS)
	{
		if (x > X_G_ANANAS && x < X_D_ANANAS)
		{
			mode_appuie = MODE_ANANAS;
		}
		else if ((x > X_G_PASTEQUE && x < X_D_PASTEQUE))
		{
			mode_appuie = MODE_PASTEQUE;
		}
	}
	else if(x > X_G_REGLAGE && y < Y_B_REGLAGE)
	{
		mode_appuie = MODE_REGLAGE;
	}

	return(mode_appuie);
}

/*-------------------------- fonction d'affichage ----------------------------*/

void Affiche_mode(int mode) // change le dessin en fonction du mode donné
{
	P_Map16x16_configureBG2_Sub_Menu(mode);
}
