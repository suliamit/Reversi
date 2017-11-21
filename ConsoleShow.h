/*
 * ConsoleShow.h
 *
 *  Created on: 11 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#ifndef CONSOLESHOW_H_
#define CONSOLESHOW_H_
#include<vector>
#include "Show.h"

class ConsoleShow:public Show {//responsible for all the printing through console in the game.
public:
	ConsoleShow();//c'tor for the class
	virtual void showBoard(Board *);//printing the parameter board
	virtual void showPossibleMoves(const vector<point> *,const bool );//printing the given possible moves. turn present the current player
	virtual void showWinner(bool);//printing who the winner is. the winner is being present by the boolean parameter
	virtual void printBadLocMess();//printing a bad location message when player choose invalid location
	virtual void printBadLocMess2();//printing a bad location message when player choose invalid move
	virtual pair<int,char>* getGameOptions();//printing the game options and return what the player chose
	virtual void showMove(const point *,const bool );//printing the last move happen
	virtual ~ConsoleShow();

};

#endif /* CONSOLESHOW_H_ */
