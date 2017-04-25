/*
 * DungeonMap.h
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */


#ifndef DUNGEONMAP_H_
#define DUNGEONMAP_H_

#include <vector>
#include <string>
#include "Tile.h"

typedef struct{
	unsigned int height;
	unsigned int width;
} pos;

class DungeonMap{
private:
	Tile*** m_map = 0;
public:
	const unsigned int maxHeight;
	const unsigned int maxWidth;
	DungeonMap(int height, int width);
	DungeonMap(int height, int width, const vector<string>& data);
};



#endif /* DUNGEONMAP_H_ */
