/*
 * Board.cpp
 *
 *  Created on: 21 באוק׳ 2017
 *      Author: Amit Suliman 322920992
 */

#include "Board.h"

Board::Board() {
	size=8;
	board=new state*[size];
		for(int i=0;i<size;i++){
			board[i]=new state[size];
			for(int j=0;j<size;j++){
				board[i][j]=empty;
			}
		}

		board[3][3]=white;
		board[4][4]=white;
		board[3][4]=black;
		board[4][3]=black;
}

Board::Board(const int s){
	size=s;
	board=new state*[size];
		for(int i=0;i<size;i++){
			board[i]=new state[size];
			for(int j=0;j<size;j++){
				board[i][j]=empty;
			}
		}

		board[size/2-1][size/2-1]=white;
		board[size/2][size/2]=white;
		board[size/2-1][size/2]=black;
		board[size/2][size/2-1]=black;
}

bool Board::isFull(){
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(board[i][j]==empty)
				return false;
	return true;
}

int Board::amountX(){
	int res=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			if(board[i][j]==black)
				res++;
	}
	return res;
}

state Board::getCell(point p){
	return board[p.x][p.y];
}

int Board::amountO(){
	int res=0;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++)
				if(board[i][j]==white)
					res++;
		}
		return res;
}

void Board::print(){
	cout << "Current board:\n"<< endl;
	for(int i=0;i<=size+1;i++){
		if(i==0)
			cout << " " ;
		else if(i==size+1){
			cout<< "| " << endl;
		for(int i=0;i<2*size+1;i++)
			cout<<"--";
		cout<<endl;
		}
		else
			cout << "| "<<i<<" ";
	}
	for(int i=0;i<size;i++){
			for(int j=-1;j<size;j++){
				if(j==-1)
					cout<< i+1<<"| ";
				else{
					switch(board[i][j]){
					case 0:cout<<" "<<" | ";break;
					case 1:cout<<'x';cout<<" | ";break;
					case 2:cout<<'o';cout<<" | ";break;
					}

				}
			}
			cout<<endl;
			for(int i=0;i<2*size+1;i++)
					cout<<"--";
			cout<<endl;
	}
}

void Board::makeMove(point * location,bool turn){
	if(turn){
		board[location->x][location->y]=black;
	}
	else
		board[location->x][location->y]=white;

}

int Board::getSize(){return size;}

Board::~Board(){
	for(int i=0;i<size;i++){
		delete[] board[i];
	}
	delete[] board;
}
