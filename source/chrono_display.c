#include "chrono_display.h"
#include "numbers_score.h"

void printDigit(u16* map, int number, int x, int y)
{
	int i,j;

	if(number >= 0 && number < 10)
		for(i = 0; i<1;i++)
			for(j = 0; j<1; j++)
				if(number >= 0){
					map[(i + y)*32+j+x] = numbers_scoreMap[2*number];
					map[(i + y +1)*32+j+x] = numbers_scoreMap[2*number+1];
				}else{
					map[(i + y)*32+j+x] = 32;
				}
}

void updateChronoDisp(u16* map,int min, int sec, int msec)
{
	int x = 0, y = 0;
	int number;
	int tile, i, j;

	//Clear the map
	for(tile = 0; tile <1024; tile++)
		map[tile] = 32;

	/*****SECONDS******/
	number = sec;
	if(sec > 60) sec = number = -1;
	//First digit
	x = 25; y = 20;
	if(sec>=0) number = sec / 10;
	printDigit(map, number, x,y);
	//Second digit
	x = 26; y = 20;
	if(sec>=0) number = sec % 10;
	printDigit(map, number, x,y);

	/*****POINT MSEC******/
	x = 27; y = 20;
	for(i = 0; i<10;i++)
		for(j = 0; j<1; j++)
			//map[10*32+j+x] = numbers_scoreMap[2*10];//(i*4+j)+32*10;
			map[21*32+j+x] = numbers_scoreMap[2*10 +1];

	/*****M.SECONDS******/
	number = msec;
	if(msec > 999) msec = number = -1;
	//First digit
	x = 28; y = 20;
	if(msec>=0) number = msec / 100;
	printDigit(map, number, x,y);

	//Second digit
	x = 29; y = 20;
	if(msec>=0) number = (msec % 100) / 10;
	printDigit(map, number, x,y);

	//Third digit
	x = 30; y = 20;
	if(msec>=0) number = (msec % 10) % 10;
	printDigit(map, number, x,y);
}




void changeColorDisp(uint16 b, uint16 c)
{
	//The olors are stored in the components 0 and 255 of the palette
	BG_PALETTE[0] = c;
	BG_PALETTE[255] = b;
}

