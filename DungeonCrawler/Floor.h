/*
 * Floor.h
 *
 *  Created on: 03.05.2017
 *      Author: sebastian
 */

#ifndef FLOOR_H_
#define FLOOR_H_

#include "Tile.h"

class Floor: public Tile
{
public:
	Floor();
	Floor(Character* character);
	virtual ~Floor();
	void onLeave(Tile* toTile) override;
	void onEnter(Character* c, Tile* fromTile) override;
	char print() override;
private:

};

#endif /* FLOOR_H_ */
