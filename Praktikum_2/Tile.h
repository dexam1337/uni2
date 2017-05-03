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
	virtual void onLeave(Tile* toTile) const = 0;
	virtual void onEnter(Character* c, Tile* fromTile) const = 0;
	virtual char print() const = 0;

private:
	Character* m_character = nullptr;
};

#endif /* TILE_H_ */
