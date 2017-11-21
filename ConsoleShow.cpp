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

void ConsoleShow::showWinner(bool isBlack_turn){
	cout<<(isBlack_turn?"x":"O")<<" is the winner"<<endl;
}

void ConsoleShow::printBadLocMess(){
	cout<<"please enter row,col in range"<<endl;
}

void ConsoleShow::printBadLocMess2(){
	cout<<"please choose row,col from the list"<<endl;
}

void ConsoleShow::showPossibleMoves(const vector<point>* moves,bool isBlack_turn){
	cout<<(isBlack_turn?"x":"o")<<": It's your move.";
	cout<<endl;
	if(!moves->empty()){
	cout<<"Your possible moves are:";
	for(int i=0;i<(moves)->size();i++){
		point m=(*moves)[i];
		cout<<" ("<<m.Row+1<<","<<m.Col+1<<")";
	}
	cout<<endl;
	cout<<"please enter your move row,col"<<endl;
	}
	else{
		cout<<"No possible moves. play passes back to the other player. press any key to continue.."<<endl;

	}
}

pair<int,char>* ConsoleShow::getGameOptions(){
	int res=0;
	char ans="";
	while(true){
	cout<<"please enter the board's size you want"<<endl;
	cin>>res;
	if(cin.fail()){
			cout<<"please enter only one positive number greater than 2 and press enter"<<endl;
			cin.ignore();
			cin.clear();
			continue;
		}
	cout<<"please choose your opponent type: h for human and b for bot"<<endl;
	cin>>ans;
	if(cin.fail()){
			cout<<"please enter only one character either 'h' or 'b'"<<endl;
			cin.ignore();
			cin.clear();
			continue;
	}
	if(res<2){
		cout<<"please enter only one positive number greater than 2 and press enter"<<endl;
		continue;
	}
	if(ans!='b' && ans!='h'){
		cout<<"please enter only one positive number greater than 2 and press enter"<<endl;
		continue;
	}
	}
	pair<int,char> final=new pair<int,string>(res,ans);
	return &final;
}

void ConsoleShow::showMove(const point * m,const bool isBlack_turn){
	cout<<(isBlack_turn?"x":"o")<<" played: ";
	cout<<"("<<m->Row+1<<","<<m->Col+1<<")";
	cout<<"\n"<<endl;
}

ConsoleShow::~ConsoleShow() {
	// TODO Auto-generated destructor stub
}

