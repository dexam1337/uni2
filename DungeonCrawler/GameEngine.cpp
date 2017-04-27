/*
 * GameEngine.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */



#include "GameEngine.h"

GameEngine::GameEngine(const unsigned int height,const unsigned int width, const vector<string>& data){
	m_map = DungeonMap(const unsigned int height,const unsigned int width, const vector<string>& data);
}
