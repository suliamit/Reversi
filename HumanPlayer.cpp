/*
 * humanPlayer.cpp
 *
 *  Created on: 12 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(bool t) {this->isBlack=t;
show=new ConsoleShow();
}


point HumanPlayer::getPlayerChoice(vector<point>* posMov){
	string ans="";
	while(true){
		cin>>ans;
	if(cin.fail()){
		show->printBadLocMess();
		cin.ignore();
		cin.clear();
		continue;
	}
	if(ans.length()!=3){
		show->printBadLocMess();
		cin.ignore();
		cin.clear();
		continue;
	}
	char r=ans[0];
	char c=ans[2];
	if((r<48 || r>57) || (c<48 || c>57) || ans[1]!=','){
				show->printBadLocMess();
				cin.ignore();
				cin.clear();
				continue;
	}
	int row=r-48;
	int col=c-48;
	point p=point(row-1,col-1);
	if(find(posMov->begin(),posMov->end(),p)==posMov->end())
	{
		show->printBadLocMess2();
		continue;
	}
	return p;
	}
}

HumanPlayer::~HumanPlayer(){
	delete show;
}

