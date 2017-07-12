#include <iostream>      //importing build-in libraries
#include <string>
#include <time.h>
#include <cstdlib>
//#include <stdio.h>

using namespace std;

#ifndef PLAY_GAME_H   //Endif statment
#define PLAY_GAME_H


class play_game{         //created class named play_game
public:				     //didn't really needed private class, so just made all public
						 //didn't need to creat constructor and hence didn't needed distructor either
	
	int menu_options;
	int level_selected;
	
	void welcomNote();   //all the functions within class play_game
	void Instruction();
	bool level_easy();
	bool level_med();
	bool level_high();
	void menu_option();
	void cout_options();
}; 


#endif