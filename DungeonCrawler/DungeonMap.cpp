/*
 * DungeonMap.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#include "DungeonMap.h"

DungeonMap::DungeonMap(const unsigned int height, const unsigned int width) {
	m_maxHeight = height;
	m_maxWidth = width;

	m_map = new Tile**[height];
	for (unsigned int i = 0; i < height; i++) {
		m_map[i] = new Tile*[width];
		for (unsigned int j = 0; j < width; j++) {
			m_map[i][j] = new Tile(Tile::Floor, nullptr);
		}
	}
}

DungeonMap::DungeonMap(const unsigned int height, const unsigned int width,
		const vector<string>& data) {
	m_maxHeight = height;
	m_maxWidth = width;

	m_map = new Tile**[height];
	for (unsigned int i = 0; i < height; i++) {
		m_map[i] = new Tile*[width];
		for (unsigned int j = 0; j < width; j++) {
			//if(data.at(hier stelle?) == '.'){
			//m_map[i][j] = new Tile(Tile::Floor, nullptr);
			//}
			//else{
			//m_map[i][j] = new Tile(Tile::Wall, nullptr);
			//}
		}
	}
}


void DungeonMap::place(Position pos, Character* c){

}
    Position DungeonMap::findTile(Tile* t){

    }
    Tile* DungeonMap::findTile(Position pos){

    }
    Position DungeonMap::findCharacter(Character* c){

    }
    void DungeonMap::print(){

    }
