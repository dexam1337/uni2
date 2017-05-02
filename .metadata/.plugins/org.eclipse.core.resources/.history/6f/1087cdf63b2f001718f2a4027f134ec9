/*
 * GameEngine.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#include "GameEngine.h"

GameEngine::GameEngine(const unsigned int height, const unsigned int width,
		const vector<string>& data) {
	m_map = DungeonMap(height, width, data);
	characters.push_back(new Character('o')); //Wegen pointer
	round = 0;
}

void GameEngine::run() {
	while (!finished())
		turn();
}

void GameEngine::turn() {
	for (unsigned int i = 0; i < characters.size(); i++) {
		Position pos;
		try {
			pos = m_map.findCharacter(characters.at(i));
		} catch (const invalid_argument& ie) {
			cerr << "Error in turn: " << ie.what() << '\n';
		}
		Tile* oldTile = m_map.findTile(pos);
		//hier switchcase für Bewegungsrichtung;
		Position newPos = pos;
		Tile* newTile;
		switch (characters.at(i)->move()) {
		case 1:
			newPos.height++;
			newPos.width--;
			newTile = m_map.findTile(newPos);
			oldTile->onLeave(newTile);
			break;
		case 2:
			newPos.height++;
			newTile = m_map.findTile(newPos);
			oldTile->onLeave(newTile);
			break;
		case 3:
			newPos.height++;
			newPos.width++;
			newTile = m_map.findTile(newPos);
			oldTile->onLeave(newTile);
			break;
		case 4:
			newPos.width--;
			newTile = m_map.findTile(newPos);
			oldTile->onLeave(newTile);
			break;
		case 5:
			newTile = m_map.findTile(newPos);
			oldTile->onLeave(newTile);
			break;
		case 6:
			newPos.width++;
			newTile = m_map.findTile(newPos);
			oldTile->onLeave(newTile);
			break;
		case 7:
			newPos.height--;
			newPos.width--;
			newTile = m_map.findTile(newPos);
			oldTile->onLeave(newTile);
			break;
		case 8:
			newPos.height--;
			newTile = m_map.findTile(newPos);
			oldTile->onLeave(newTile);
			break;
		case 9:
			newPos.height--;
			newPos.width++;
			newTile = m_map.findTile(newPos);
			oldTile->onLeave(newTile);
			break;
		default:
			cout << "Fehler in switchcase in turn()";
			break;
		}
	}
}

bool GameEngine::finished() {
	round++;
	cout << round << endl;
	if (round <= 10)
		return false;
	else
		return true;
}

GameEngine::~GameEngine() {
	//delete[] characters;
	for (unsigned int i = characters.size(); i > 0; i++)
		delete characters.at(i);
	m_map.~DungeonMap();
}
