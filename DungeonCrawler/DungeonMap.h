/*
 * DungeonMap.h
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#ifndef DUNGEONMAP_H_
#define DUNGEONMAP_H_

typedef struct{
	unsigned int x;
	unsigned int y;
} pos;

class DungeonMap{
private:
	Tile*** m_map = 0;
public:
};



#endif /* DUNGEONMAP_H_ */
