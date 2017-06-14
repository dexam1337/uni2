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
#include "Glass.h"
//#include "Tile.h"
#include "Wall.h"
#include "Floor.h"
#include "Switch.h"
#include "Door.h"
#include "Lever.h"
#include "Trap.h"
#include <stdexcept>
#include <set>
#include <map>
#include "Position.h"
#include <limits>
#include <algorithm>
#include <math.h>
#include <memory>
#include <map>
#include <stdint.h>



class DungeonMap {
private:
    Tile*** m_map;
    DungeonMap(DungeonMap& map); //Nicht implementierter KopierKonstruktor
    unsigned int m_maxHeight;
    unsigned int m_maxWidth;

public:
    DungeonMap(const unsigned int height, const unsigned int width,
            const vector<string>& data);
    ~DungeonMap();
    void place(Position pos, Character* c);
    Position findTile(Tile* t);
    Tile* findTile(Position pos);
    Position findCharacter(Character* c);
    void print(Position center);
    bool hasLineOfSight(Position from, Position to);
    friend ostream& operator<<(ostream& outputstream, const DungeonMap& map);
    void saveItems(ostream& outputstream);
    const vector<Position> getPathTo(const Position from, const Position to);
};

#endif /* DUNGEONMAP_H_ */
