/*
 * main.cpp
 *
 *  Created on: 21 באוק׳ 2017
 *      Author: Amit Suliman 322920992
 */

#include "Reversi.h"

int main(){
	Reversi *game=new Reversi();
	game->startGame();
	delete game;
	return 0;
}

