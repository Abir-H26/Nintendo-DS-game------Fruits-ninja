/*
 * Controle.c
 *
 *  Created on: Dec 5, 2021
 *      Author: nds
 */
#include "Controls.h"

//si la position a changer doit renvoier la nouvel position si non renvois 0,0
touchPosition Calcule_coord()
{
	touchRead(&pos_new);
	//Identify a valid touched coordinates and print them
	if ((pos_old.py || pos_new.px) && (pos_old.py != pos_new.py) &&
		(pos_old.px != pos_new.px))
	{
		//printf("Les coordonnee sont (%i , %i) \n", touch.py, touch.px );
		pos_old = pos_new;
	}
	else
	{
		pos_new.px = 0;
		pos_new.py = 0;
	}
	return pos_new;
}

//lit les boutton et renvoie le boutton appuier
int HandleInput()
{
	scanKeys();
	u16 keys = keysDown();//boutton qui on été appuié

	int action = -1;

	if (keys & KEY_A)
	{
		action = ACTION_A;
	}
	else if (keys & KEY_LEFT)
	{
		action = ACTION_LEFT;
	}
	else if (keys & KEY_RIGHT)
	{
		action = ACTION_RIGHT;
	}
	return action;
}
