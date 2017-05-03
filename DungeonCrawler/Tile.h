/*
 * Title.h
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#ifndef TILE_H_
#define TILE_H_

#include "Character.h"

class Tile {

public:
	Tile(Character* character);
	Tile();
	Character* getCharacter();
	bool hasCharacter();
	void setCharacter(Character* character);
	virtual void onLeave(Tile* toTile) ;
	virtual void onEnter(Character* c, Tile* fromTile);
	virtual char print();

private:
	Character* m_character = nullptr;
};

#endif /* TILE_H_ */
