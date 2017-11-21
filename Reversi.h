/*
 * BoardGames.h
 *
 *  Created on: 3 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#ifndef REVERSI_H_
#define REVERSI_H_
#include<iostream>
#include "Board.h"
#include "ConsoleShow.h"
#include<vector>
#include "HumanPlayer.h"

using namespace std;

class Reversi {//manger of the game functionality
public:
	Reversi();
	void initial();
	bool isValidMove(point *,const bool);//check if a given point is a valid move for a given player(choose by the value of turn)
	vector<point>  getValidMoves(const bool);//return a vector of all valid points for a given player(choose by the value of turn)
	vector<vector<point> >  getTilesToFlip(point ,const bool);//return a vector of all the points that needs to flip for a given point and turn
	void startGame();//starting the game
	void doTurn();//do turn
	void endGame();//ending the game
	void makeMove(point);//change the the cell that being present by the given point
	bool gameEnd();//check if game ends: board is full or no moves for each player
	virtual ~Reversi();
private:
	bool isValidLoc(point );//check if location is valid(in the board's range)
	bool isLocFree(point *);//check if the cell in board is free
	bool boardFull();//check if board is full
	Player * p1;
	Player * p2;
	Board * board;
	bool isBlack_turn;
	Show * show;
};

#endif /* REVERSI_H_ */
