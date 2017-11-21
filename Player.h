/*
 * Player.h
 *
 *  Created on: 3 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "DataStructures.h"
#include<limits.h>
#include"Show.h"
#include <string.h>
#include<iostream>


using namespace std;

class Player {//an interface that responsible for the players ,AI or humans, functionality
public:
	Player(){ };
	virtual point getPlayerChoice(vector<point> *)=0;////return the point chosen by the player from a given list of points
	virtual ~Player(){};
};

#endif /* PLAYER_H_ */
