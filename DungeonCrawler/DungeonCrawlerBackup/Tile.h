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
	/*enum Typ {
		Floor, Wall
	};*/
	Tile(/*Typ typ, */Character* character);
        virtual ~Tile();
	//Typ getTyp();
	Character* getCharacter();
	bool hasCharacter();
	void setCharacter(Character* character);
	virtual void onLeave(Tile* toTile) = 0;
	virtual void onEnter(Character* c, Tile* fromTile) = 0;
	virtual char print();

private:
	//Typ m_typ;
	Character* m_character = nullptr;
};

#endif /* TILE_H_ */
