/*
 * BoardGames.cpp
 *
 *  Created on: 3 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#include "Reversi.h"

Reversi::Reversi() {
	p1=new HumanPlayer(true);
	p2=new HumanPlayer(false);
	board=new Board();
	turn=true;
	show=new ConsoleShow();
}

void Reversi::startGame(){
	while(!gameEnd()){
	show->showBoard(board);
	doTurn();
	turn=!turn;
	}
	endGame();
}

void Reversi::endGame(){
	show->showBoard(board);
	int m=board->amountX();
	int n=board->amountO();
	bool win=(m>=n);
	show->showWinner(win);
}

void Reversi::doTurn(){
	vector<point>  posMov=getValidMoves(turn);
	show->showPossibleMoves(&posMov,turn);
	if(posMov.empty())return;
	point playerChoice=((turn?p1:p2)->getPlayerChoice(&posMov));
	makeMove(playerChoice);
	show->showMove(&playerChoice,turn);
}

vector<vector<point> >  Reversi::getTilesToFlip(point cell,const bool turn){
	vector<vector<point> > res;
	vector<point> tmp;
		int xstart=cell.x;
		int ystart=cell.y;
		state otile=turn?white:black;//present the other player's tile
		state ctile=turn?black:white;
		const point p[8]={point(-1,1),point(0,1),point(1,1),point(1,0),point(1,-1),point(0,-1),point(-1,-1),point(-1,0)};
		for(int i=0;i<8;i++){
			xstart=cell.x;
			ystart=cell.y;

			int xd=p[i].x;
			int yd=p[i].y;
			xstart+=xd;
			ystart+=yd;
			if(!isValidLoc(point(xstart,ystart)))
							continue;
			if(	board->getCell(point(xstart,ystart))!=otile)
				continue;
			xstart+=xd;
			ystart+=yd;
			if(!isValidLoc(point(xstart,ystart)))
									continue;
			while(board->getCell(point(xstart,ystart))==otile){
				xstart+=xd;
				ystart+=yd;
				if(!isValidLoc(point(xstart,ystart)))
					break;
			}
			if(!isValidLoc(point(xstart,ystart)))
							continue;
			if(board->getCell(point(xstart,ystart))!=ctile)
				continue;
			xstart-=xd;
			ystart-=yd;
			while(!(point(xstart,ystart)==cell)){
			tmp.push_back(point(xstart,ystart));
			xstart-=xd;
			ystart-=yd;
			}
			tmp.push_back(cell);
			res.push_back(tmp);
		}
		return res;



}

void Reversi::makeMove(point pChoice){
	vector<vector<point> > tilesToFlip=((getTilesToFlip(pChoice,turn)));
	for(int i=0;i<tilesToFlip.size();i++){
		vector<point> tiles=(tilesToFlip[i]);
		for(int j=0;j<tiles.size();j++){
			point tile=(tiles[j]);
			board->makeMove(&tile,turn);
		}
	}
}

bool Reversi::gameEnd(){
	bool res=boardFull();
	if(!res){
		if((getValidMoves(true)).empty() && getValidMoves(false).empty())
			res=true;
	}
	return res;
}

bool Reversi::boardFull(){
	return board->isFull();
}

bool Reversi::isValidLoc(point  location){
	return location.x>=0 && location.x<board->getSize() && location.y>=0 && location.y<board->getSize();
}

bool Reversi::isLocFree(point * location){
	return board->getCell(*location)==empty;
}

bool Reversi::isValidMove(point *location,const bool turn){
	if(!isValidLoc(*location) || !isLocFree(location)){
		return 0;
	}
	int xstart=location->x;
	int ystart=location->y;
	state otile=turn?white:black;//present the other player's tile
	state ctile=turn?black:white;
	const point p[8]={point(-1,1),point(0,1),point(1,1),point(1,0),point(1,-1),point(0,-1),point(-1,-1),point(-1,0)};
	for(int i=0;i<8;i++){
		xstart=location->x;
		ystart=location->y;
		int xd=p[i].x;
		int yd=p[i].y;
		xstart+=xd;
		ystart+=yd;
		if(!isValidLoc(point(xstart,ystart)))
			continue;
		if(board->getCell(point(xstart,ystart))!=otile)
								continue;
				xstart+=xd;
				ystart+=yd;
				if(!isValidLoc(point(xstart,ystart)))
						continue;
				while(board->getCell(point(xstart,ystart))==otile){
					xstart+=xd;
					ystart+=yd;
					if(!isValidLoc(point(xstart,ystart)))
						break;
				}
				if(!isValidLoc(point(xstart,ystart)))
								continue;
				if(board->getCell(point(xstart,ystart))!=ctile)
					continue;
		return true;
	}
	return false;
}

vector<point>  Reversi::getValidMoves(const bool turn){
	vector<point>  res;
	for(int i=0;i<board->getSize();i++){
		for(int j=0;j<board->getSize();j++){
				point loc(i,j);
				if(isValidMove(&loc,turn)){
				res.push_back(loc);
				}
		}
	}
	return res;
}

Reversi::~Reversi() {
	delete board;
	delete p1;
	delete p2;
	delete show;
}

