/*
 * show.h
 *
 *  Created on: 12 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#ifndef SHOW_H_
#define SHOW_H_
#include"Board.h"
#include "DataStructures.h"
#include<vector>

class Show {//an interface that in charge of all prints during the game;
public:
	Show(){ };
	virtual void showBoard(Board *)=0;//printing the parameter board
	virtual void showPossibleMoves(const vector<point> *,const bool)=0;//printing the given possible moves. turn present the current player
	virtual void showWinner(bool)=0;//printing who the winner is. the winner is being present by the boolean parameter
	virtual void printBadLocMess()=0;//printing a bad location message when player choose invalid location
	virtual void printBadLocMess2()=0;//printing a bad location message when player choose invalid move
	virtual void showMove(const point*,const bool turn)=0;//printing the last move happen
	virtual ~Show(){ };
};

#endif /* SHOW_H_ */
