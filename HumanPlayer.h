/*
 * humanPlayer.h
 *
 *  Created on: 12 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include "Player.h"
#include"ConsoleShow.h"

class HumanPlayer: public Player {//responsible of the human player functionality
public:
	HumanPlayer();
	HumanPlayer(bool);
	virtual point getPlayerChoice(vector<point>*);//return the point chosen by the player from a given list of points
	virtual ~HumanPlayer();
private:
	Show *show;
	bool isBlack;
};

#endif /* HUMANPLAYER_H_ */
