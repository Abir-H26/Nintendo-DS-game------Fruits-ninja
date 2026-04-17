#include <nds.h>
#include <stdio.h>

#include "Mode_menu.h"

int main(void)
{
	//configuration  affichage
	P_Graphics_setup_menu();
	P_Graphics_BG_main_menu();

	//configuration audio
	Audio_Init();

	Mode_menu();//boucle infinie

	while(1) {
		swiWaitForVBlank();
	}
}
