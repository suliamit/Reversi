/*
 * DataStructures.h
 *
 *  Created on: 3 בנוב׳ 2017
 *      Author: Amit Suliman 322920992
 */

#ifndef DATASTRUCTURES_H_
#define DATASTRUCTURES_H_
#include<vector>
#include<algorithm>
//collection of data structures that in use during the game
	typedef enum{empty=0,black,white} state;//present the state of cell in board
	typedef struct point{
	public:
			int Row;
			int Col;
			point(int Row,int Col):Row(Row),Col(Col){};
			bool operator==(point q){return Row==q.Row & Col==q.Col;}
		}point;






#endif /* DATASTRUCTURES_H_ */
