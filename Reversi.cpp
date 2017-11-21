/*
 * BoardGames.cpp
 *
 *  Created on: 3 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#include "Reversi.h"

Reversi::Reversi() {
initial();
}

void Reversi::initial(){
	show=new ConsoleShow();
	pair<int,char> *option=show->getGameOptions();
	p1=new HumanPlayer(false);
	int size=option->first;
	char type=option->second;
	board=new Board(size);
	if(type=='h')
		p2=new HumanPlayer();
	else
		//p2=new BotPlayer();
	isBlack_turn=true;
}

void Reversi::startGame(){
	while(!gameEnd()){
	show->showBoard(board);
	doTurn();
	isBlack_turn=!isBlack_turn;
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
	vector<point>  posMov=getValidMoves(isBlack_turn);
	show->showPossibleMoves(&posMov,isBlack_turn);
	if(posMov.empty())return;
	point playerChoice=((isBlack_turn?p1:p2)->getPlayerChoice(&posMov));
	makeMove(playerChoice);
	show->showMove(&playerChoice,isBlack_turn);
}

vector<vector<point> >  Reversi::getTilesToFlip(point cell,const bool isBlack_turn){
	vector<vector<point> > res;
	vector<point> tmp;
		int xstart=cell.Row;
		int ystart=cell.Col;
		state otile=isBlack_turn?white:black;//present the other player's tile
		state ctile=isBlack_turn?black:white;
		const point p[8]={point(-1,1),point(0,1),point(1,1),point(1,0),point(1,-1),point(0,-1),point(-1,-1),point(-1,0)};
		for(int i=0;i<8;i++){
			xstart=cell.Row;
			ystart=cell.Col;

			int xd=p[i].Row;
			int yd=p[i].Col;
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
	vector<vector<point> > tilesToFlip=((getTilesToFlip(pChoice,isBlack_turn)));
	for(int i=0;i<tilesToFlip.size();i++){
		vector<point> tiles=(tilesToFlip[i]);
		for(int j=0;j<tiles.size();j++){
			point tile=(tiles[j]);
			board->makeMove(&tile,isBlack_turn);
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
	return location.Row>=0 && location.Row<board->getSize() && location.Col>=0 && location.Col<board->getSize();
}

bool Reversi::isLocFree(point * location){
	return board->getCell(*location)==empty;
}

bool Reversi::isValidMove(point *location,const bool isBlack_turn){
	if(!isValidLoc(*location) || !isLocFree(location)){
		return 0;
	}
	int xstart=location->Row;
	int ystart=location->Col;
	state otile=isBlack_turn?white:black;//present the other player's tile
	state ctile=isBlack_turn?black:white;
	const point p[8]={point(-1,1),point(0,1),point(1,1),point(1,0),point(1,-1),point(0,-1),point(-1,-1),point(-1,0)};
	for(int i=0;i<8;i++){
		xstart=location->Row;
		ystart=location->Col;
		int xd=p[i].Row;
		int yd=p[i].Col;
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

vector<point>  Reversi::getValidMoves(const bool isBlack_turn){
	vector<point>  res;
	for(int i=0;i<board->getSize();i++){
		for(int j=0;j<board->getSize();j++){
				point loc(i,j);
				if(isValidMove(&loc,isBlack_turn)){
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

