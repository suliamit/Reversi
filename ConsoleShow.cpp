/*
 * ConsoleShow.cpp
 *
 *  Created on: 11 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#include "ConsoleShow.h"

ConsoleShow::ConsoleShow() {
}

void ConsoleShow::showBoard(Board * b){
	b->print();
}

void ConsoleShow::showWinner(bool turn){
	cout<<(turn?"x":"O")<<" is the winner"<<endl;
}

void ConsoleShow::printBadLocMess(){
	cout<<"please enter row,col in range"<<endl;
}

void ConsoleShow::printBadLocMess2(){
	cout<<"please choose row,col from the list"<<endl;
}

void ConsoleShow::showPossibleMoves(const vector<point>* moves,bool turn){
	cout<<(turn?"x":"o")<<": It's your move.";
	cout<<endl;
	if(!moves->empty()){
	cout<<"Your possible moves are:";
	for(int i=0;i<(moves)->size();i++){
		point m=(*moves)[i];
		cout<<" ("<<m.x+1<<","<<m.y+1<<")";
	}
	cout<<endl;
	cout<<"please enter your move row,col"<<endl;
	}
	else{
		cout<<"No possible moves. play passes back to the other player. press any key to continue.."<<endl;

	}
}

void ConsoleShow::showMove(const point * m,const bool turn){
	cout<<(turn?"x":"o")<<" played: ";
	cout<<"("<<m->x+1<<","<<m->y+1<<")";
	cout<<"\n"<<endl;
}

ConsoleShow::~ConsoleShow() {
	// TODO Auto-generated destructor stub
}

