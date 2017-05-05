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
//#include "Floor.h"
#include "Tile.h"
#include <stdexcept>
#include <iostream>
using namespace std;

typedef struct {
    unsigned int height;
    unsigned int width;
} Position;

class DungeonMap {
private:
    Tile*** m_map;
    DungeonMap(DungeonMap& map); //Nicht implementierter KopierKonstruktor
    unsigned int m_maxHeight;
    unsigned int m_maxWidth;

public:
    DungeonMap();
    DungeonMap(const unsigned int height, const unsigned int width);
    DungeonMap(const unsigned int height, const unsigned int width,
            const vector<string>& data);
    ~DungeonMap();

    void place(Position pos, Character* c);
    Position findTile(Tile* t);
    Tile* findTile(Position pos);
    Position findCharacter(Character* c);
    void print();
};

#endif /* DUNGEONMAP_H_ */
