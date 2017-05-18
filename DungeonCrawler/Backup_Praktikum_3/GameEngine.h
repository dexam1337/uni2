/*
 * GameEngine.h
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_
#include "DungeonMap.h"

class GameEngine
{
public:
    GameEngine(const unsigned int height, const unsigned int width,
               const vector<string>& data);
    GameEngine(const unsigned int height, const unsigned int width,
               const vector<string>& data, const vector<string>& relations);
    void run();
    void turn();
    bool finished();
    ~GameEngine();
private:
    int m_limit;
    int m_round;
    DungeonMap m_map;
    vector<Character *> characters;
    void linkObjects(const vector<string>& relations);
    
};

#endif /* GAMEENGINE_H_ */