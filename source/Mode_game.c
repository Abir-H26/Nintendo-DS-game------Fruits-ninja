/*
 * mode_ananas.c
 *
 *  Created on: Jan 2, 2022
 *      Author: nds
 */
#include "Mode_game.h"

/*---------------------------Fonctions praincipales---------------------------*/
void Mode_ananas()
{
	mode_jeu = ANANAS;

	mmStop();
	//changer l'affichage
	P_Graphics_setup_game();
	P_Map16x16_configureBG2_Sub_Game(IMAGE_REGLE_ANANAS);

	configureSprites(); // initalisation des Sprites;
	IRQ_initialize();	//initalisation interuption;

	//initalisation temps et score
	sec		= 60;
	msec 	= 0;
	score 	= 0;

	//enlevé tout les fruit
	nb_fruit   = 0;
	y_fruit[0] = 0;
	y_fruit[1] = 0;
	y_fruit[2] = 0;

	//determiner temps jusqu'a l'apparition du premier fruit
	srand(time(NULL));
	prochin_fruit = 10;
	prochin_fruit_min = TEMPS_PROCHUN_FRUIT_INIT;
	compte_temps = 0;

	int i;

    while(gameState != STOP)
    {
    	DisplayScore(score);
    	if(gameState == PLAY) Mise_a_jour_fruit();//dessandre les fruit
    	Gere_lame();
    	Gere_disparition_flaque();

    	//dessiner ou effacé les fruit
    	for(i=0; i<NB_DE_FRUIT_MAX; i++)
    	{
    		if(gameState == PLAY)
    		{
    			if(y_fruit[i])
    				Redessine_fruit(i, x_fruit[i], y_fruit[i], type_fruit[i],1);
    		}
    		else if (gameState == PAUSE)
    		{
    			Redessine_fruit_cache(i, x_fruit[i], 0, type_fruit[i], 1);
    		}
    	}
    	swiWaitForVBlank();
    	oamUpdate(&oamSub);
    }
    Disable_iterup();
}

void Mode_pasteque()
{
	mode_jeu = PASTEQUE;

	mmStop();
	//changer l'affichage
	P_Graphics_setup_game();
	P_Map16x16_configureBG2_Sub_Game(IMAGE_REGLE_PASTEQUE);
	configureSprites();

	IRQ_initialize();
	//initalisation score et nb de Faute
	score = 0;
	faute = 0;

	//enlevé tout les fruit
	nb_fruit   = 0;
	y_fruit[0] = 0;
	y_fruit[1] = 0;
	y_fruit[2] = 0;

	//determiner temps jusqu'a l'apparition du premier fruit
	srand(time(NULL));
	prochin_fruit = 10;
	prochin_fruit_min = TEMPS_PROCHUN_FRUIT_INIT;
	compte_temps = 0;

	int i;

    while(gameState != STOP)
    {
    	DisplayScore(score);

    	if (faute>=NB_FAUTE_MAX)
    	{
    		gameState = PAUSE;
    	}
    	if(gameState == PLAY) Mise_a_jour_fruit();
    	Gere_lame();
    	Gere_disparition_flaque();

    	for(i=0; i<NB_DE_FRUIT_MAX; i++)
    	{
			if(gameState == PLAY){
				if(y_fruit[i])
					Redessine_fruit(i, x_fruit[i], y_fruit[i], type_fruit[i],1);
			}
			else if (gameState == PAUSE)
			{
				Redessine_fruit_cache(i, x_fruit[i], 0, type_fruit[i], 1);
			}
		}
    	swiWaitForVBlank();
    	oamUpdate(&oamSub);

    }
    Disable_iterup();
}
/*-----------------------Fonctions de gestion des fruit-----------------------*/
/* Gère tout le déplacement des fruit ainci que l'apparition des nouveau fruit
 */
void Mise_a_jour_fruit()
{
	compte_temps++;
	Dessent_tout_fruit();

	//ajouté un nouveau Fruit
	if(compte_temps > prochin_fruit && nb_fruit < NB_DE_FRUIT_MAX)
	{
		Ajoute_fruit();
		nb_fruit ++;
		Calcule_temps_fruit();
	}
}

/* Calcule un temps aléatoire entre prochin_fruit_min et TEMPS_PROCHUN_FRUIT
 */
void Calcule_temps_fruit()
{
	compte_temps = 0;//remetre le temps à 0

	//définir temps pour prochin fruit
	prochin_fruit = (rand()%TEMPS_PROCHUN_FRUIT) * 5 + prochin_fruit_min;
	prochin_fruit_min -= 2;
}
/* déplace tout les fruit un par un
 */
void Dessent_tout_fruit(){
	int i;//,j;
	//int old_nb_fruit = nb_fruit;

	for(i=0; i<NB_DE_FRUIT_MAX; i++){
		Dessent_fruit(i);
	}
}
/* déplace un fruit visible vers le bas et l'efface les fruit qui sont tout
 * en bas tout en gérant le calcule des "fautes". cette fonction arrête le jeu
 * dés que les faute sont trop nombreuse
 */
void Dessent_fruit(int num_fruit)
{

	if (y_fruit[num_fruit] >= (SCREEN_HEIGHT + SPRITE_HEIGHT))//fruit tout en bas
	{
		if (mode_jeu == PASTEQUE)
		{
			faute++;
			Audio_PlaySound_Menu(SFX_RESULT);
			if (faute>=NB_FAUTE_MAX)
			{
				gameState = PAUSE;
				Audio_PlaySound_Menu(SFX_FANFARE_X);
				P_Map16x16_configureBG2_Sub_Game(IMAGE_GAME_OVER);
			}
		}
		y_fruit[num_fruit] = 0;
		nb_fruit--;
	}
	else if (y_fruit[num_fruit])//si le fruit existe
	{
		y_fruit[num_fruit] += vitesse[num_fruit];
	}
}

/* cette foction donne les caractéristique initale d'un fruit, plus presisement
 * la position, sa vitesse et le type de fruit.
 * elle détermine aussi l'intervale du temps jusqu'au prochin fruit
 */
void Ajoute_fruit(){
	int num_fruit;
	int i;
	for (i=0; i<NB_DE_FRUIT_MAX; i++){
		if (y_fruit[i] == 0){
			num_fruit = i;
			i = NB_DE_FRUIT_MAX;
		}
	}

	y_fruit[num_fruit] = 1;
	x_fruit[num_fruit] = rand()%(SCREEN_WIDTH-SPRITE_WIDTH);
	vitesse[num_fruit] = rand()%(VITESSE_FRUIT_MAX)+1;
	int type = rand()%NB_TYPE_FRUIT;

	switch (type){
	case 0: type_fruit[num_fruit] = pomme_SUB;
		break;
	case 1: type_fruit[num_fruit] = banane_SUB;
		break;
	case 2: type_fruit[num_fruit] = ananas_SUB;
		break;
	case 3:
		break;
	case 4:
		break;
	}
	Audio_PlaySound_Menu(SFX_CLUNK);
}

/*-----------------------Fonctions de gestion de la lame----------------------*/
/*Trouve la position de la lame et la dessine ä cette endroie
 */
void Gere_lame(){
	Trouve_pos_lame();
	Dessine_lame(x_lame, y_lame);
	if(gameState == PLAY)fruit_coup();
}

/*Trouve la position de la lame
 */
void Trouve_pos_lame(){
	touchPosition lame;
	touchRead(&lame);
	x_lame = lame.px;
	y_lame = lame.py;
}

/*Dötermine si il y a un fruit coupé et si oui gère sa disparition, l'apparition
 * d'une flaque à sa place et l'augmentation du score
 */
void fruit_coup(){
	int i,j;
	int num = 1000;
	if (x_lame || y_lame)
	for (i=0; i<NB_DE_FRUIT_MAX; i++){
		if (x_fruit[i] <= x_lame && x_fruit[i] + SPRITE_WIDTH >= x_lame &&
			y_fruit[i] <= y_lame && y_fruit[i] + SPRITE_HEIGHT >= y_lame &&
			y_fruit[i] != 0){
			for(j=0; j<NB_FLAQUE_MAX && num == 1000; j++){
				if(compte_flaque[j] == 0){
					compte_flaque[j] = 1;
					num = j;
				}
			}

			Redessine_fruit(5+num, x_fruit[i], y_fruit[i], flaque_SUB, 0);

			y_fruit[i]=0;
			Redessine_fruit(i, x_fruit[i], -SPRITE_HEIGHT, type_fruit[i], 1);
			nb_fruit--;
			Audio_PlaySound_Menu(SFX_SWISH);
			score += vitesse[i];

		}
	}
}

/*Calcule le temps depuis l'apparition de la flaque et la fait disparütre apres
 * un temps donné
 */
void Gere_disparition_flaque(){
	int i;
	for (i = 0; i < NB_FLAQUE_MAX; i++){
		if (compte_flaque[i]) compte_flaque[i]++;

			if (compte_flaque[i] >= DELAY_FLAQUE){
				compte_flaque[i] = 0;
				Redessine_fruit(5+i, 0, -SPRITE_HEIGHT , flaque_SUB, 1);
			}
	}
}

/*---------------------------routine d'interuption----------------------------*/
void IRQ_initialize()
{
	// Configure timer 0 to trigger an interrupt every 1 ms
	TIMER0_CR = TIMER_ENABLE|TIMER_DIV_1024|TIMER_IRQ_REQ;
	TIMER0_DATA = TIMER_FREQ_1024(1000);


	//Countdown's set up
	if(mode_jeu == ANANAS)irqSet(IRQ_TIMER0, &ISR_countdown_timer);

	// Main screen refreshing:
	irqSet(IRQ_VBLANK, &ISR_VBlank);
	irqEnable(IRQ_VBLANK);

	/*Configure the keys to throw an interrupt with the keys LEFT,RIGHT,DOWN,UP*/
	REG_KEYCNT = KEY_LEFT | KEY_RIGHT | KEY_DOWN | KEY_UP | 1<<14;
	gameState = PAUSE;
	irqSet(IRQ_KEYS, &ISR_Keys);
	irqEnable(IRQ_KEYS);

}

void Disable_iterup()
{
	irqDisable(IRQ_TIMER0);
	irqDisable(IRQ_KEYS);
	mode_jeu = NOP;
	//irqDisable(IRQ_VBLANK);
}

/*
 * ISR_countdown_timer:
 * Interrupt Service Routine of the timer.
 * After each 1 ms, it decrements the countdown timer.
 */
void ISR_countdown_timer()
{
	if (msec || sec )// if the countdown timer did not reach 00:00.000
	{
		if (!msec && sec)
		{
			msec = 999; // Reset to the max of the ms range
			if (!sec)
			{
				sec = 59; // Reset to the max of the sec range
			}
			else
				sec -= 1; // Decrement 1 seconds
		}
		else
			msec -= 1; // Decrement 1 ms
	}
	else // Countdown finished!!!
	{
		changeColorDisp(RED, WHITE);
		gameState = PAUSE;
		Audio_PlaySound_Menu(SFX_FANFARE_X);
		P_Map16x16_configureBG2_Sub_Game(IMAGE_TEMPS_FINI);
		irqDisable(IRQ_TIMER0);
	}
}

/*
 * ISR_VBlank:
 * Interrupt Service Routine of the screens, to refresh them properly.
 */
void ISR_VBlank()
{
	if(mode_jeu != NOP)DisplayScore(score);
	//ISR_Keys();	//a comanter pour nintendo
	if(mode_jeu == ANANAS)updateChronoDisp(BG_MAP_RAM(24), min, sec, msec); // update chrono's screen
	if(mode_jeu == PASTEQUE) DisplayFaute(faute);
}


//Keys interrupt handler
void ISR_Keys()
{

	u16 keys = ~(REG_KEYINPUT);

	if(keys & KEY_LEFT && gameState == PAUSE)
	{
		gameState = STOP;
		if(mode_jeu == ANANAS)irqDisable(IRQ_TIMER0);
		P_Graphics_setup_menu();
	}
	if(keys & KEY_UP) //KEY A = Pause mode
	{
		gameState = PAUSE;
		P_Map16x16_configureBG2_Sub_Game(IMAGE_PAUSE);

		if( mode_jeu == ANANAS) irqDisable(IRQ_TIMER0);
	}
	if((keys & KEY_DOWN) && (gameState == PAUSE)) //KEY DOWN = Game continues
	{
		gameState = PLAY;
		if(mode_jeu == ANANAS)irqEnable(IRQ_TIMER0);
		P_Map16x16_configureBG2_Sub_Game(IMAGE_FOND);
	}
	if((keys & KEY_RIGHT) && (gameState == PAUSE))//KEY RIGHT = Restart
	{
		if(mode_jeu == ANANAS)irqDisable(IRQ_TIMER0);
		y_fruit[0] = 0;
		y_fruit[1] = 0;
		y_fruit[2] = 0;
		if(mode_jeu == ANANAS){
			sec = 60;
			msec = 0;
			min = 0;
		}
		score = 0;
		if(mode_jeu == PASTEQUE) faute = 0;

		nb_fruit = 0;
		prochin_fruit = 10;
		prochin_fruit_min = TEMPS_PROCHUN_FRUIT_INIT;
		compte_temps = 0;
	}
}
