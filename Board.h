/*
 * Board.h
 *
 *  Created on: 21 באוק׳ 2017
 *      Author: Amit Suliman 322920992
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
#include "DataStructures.h"
using namespace std;

class Board //responsible of the board game functionality
{
public:
	Board();//
	Board(const int s);
	int getSize();//return the size of the board
	int amountX();//return amount of 'x' tiles in the current board
	int amountO();//return amount of 'o' tiles in the current board
	state getCell(point);//return the cell in the index that being present by point
	void print();// print the current board
	bool isFull(); // check if the board is Full
	void makeMove(point * location,bool);//sets the player's choice in the board.
	~Board();
	private:
	int size;
	state ** board;
};




#endif /* BOARD_H_ */
