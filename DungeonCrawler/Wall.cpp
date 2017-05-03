/*
 * Wall.cpp
 *
 *  Created on: 03.05.2017
 *      Author: sebastian
 */

#include "Wall.h"

Wall::Wall() :
		Tile()
{
	// TODO Auto-generated constructor stub

}

Wall::Wall(Character* character) :
		Tile(character)
{

}

Wall::~Wall()
{
	// TODO Auto-generated destructor stub
}

char print()
{
	return "#";

}

void onLeave(Tile* toTile)
{
	//Can't place on Wall in first place
}
void onEnter(Character* c, Tile* fromTile)
{
	fromTile->onEnter(c, this);
}