/*
 * GameEngine.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */
#include "GameEngine.h"
//#include <iostream>
#include <sstream>

GameEngine::GameEngine(const unsigned int height, const unsigned int width,
        const vector<string>& data) :
m_map(height, width, data) {

    cout << "Wie viele Runden?" << endl;
    cin >> m_limit;
    //	m_map = DungeonMap(height, width, data);
    characters.push_back(new Character('o')); //Wegen pointer
    Position pos;
    pos.height = 7;
    pos.width = 2;
    m_map.place(pos, characters.at(0));
    m_round = 0;

}

GameEngine::GameEngine(const unsigned int height, const unsigned int width,
        const vector<string>& data, int limit) :
m_map(height, width, data) {

    m_limit = limit;
    //	m_map = DungeonMap(height, width, data);
    characters.push_back(new Character('o')); //Wegen pointer
    Position pos;
    pos.height = 7;
    pos.width = 2;
    m_map.place(pos, characters.at(0));
    m_round = 0;

}

GameEngine::GameEngine(const unsigned int height, const unsigned int width,
        const vector<string>& data, const vector<string>& relations) :
m_map(height, width, data) {

    cout << "Wie viele Runden?" << endl;
    cin >> m_limit;
    //	m_map = DungeonMap(height, width, data);
    characters.push_back(new Character('o')); //Wegen pointer
    Position pos;
    pos.height = 7;
    pos.width = 2;
    m_map.place(pos, characters.at(0));
    m_round = 0;
    linkObjects(relations);
}

GameEngine::GameEngine(const unsigned int height, const unsigned int width,
        const vector<string>& data, const vector<string>& relations, int limit) :
m_map(height, width, data) {

    m_limit = limit;
    //	m_map = DungeonMap(height, width, data);
    characters.push_back(new Character('o')); //Wegen pointer
    Position pos;
    pos.height = 7;
    pos.width = 2;
    m_map.place(pos, characters.at(0));
    m_round = 0;
    linkObjects(relations);
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
        Position newPos = pos;
        Tile* newTile;
        int eingabe = characters.at(i)->move();
        switch (eingabe) {
            case 1:
                newPos.height++;
                newPos.width--;
                break;
            case 2:
                newPos.height++;
                break;
            case 3:
                newPos.height++;
                newPos.width++;
                break;
            case 4:
                newPos.width--;
                break;
            case 5:

                break;
            case 6:
                newPos.width++;
                break;
            case 7:
                newPos.height--;
                newPos.width--;
                break;
            case 8:
                newPos.height--;
                break;
            case 9:
                newPos.height--;
                newPos.width++;

                break;
            case 0:
                m_round = m_limit;
                break;
            default:
                cout << "Fehler in switchcase in turn()";
                break;
        }

        newTile = m_map.findTile(newPos);
        oldTile->onLeave(newTile);
    }

}

bool GameEngine::finished() {
    m_round++;
    cout << m_round << endl;
    m_map.print();
    if (m_round <= m_limit)
        return false;
    else
        return true;
}

GameEngine::~GameEngine() {
    for (int i = 0; i < characters.size(); i++)
        delete characters.at(i);
    characters.erase(characters.begin(), characters.end());
    m_map.~DungeonMap();
}

void GameEngine::linkObjects(const vector<string>& relations) {

    Passive* passiveTile;
    Active* activeTile;
    Position passiveObject;

    for (int i = 0; i < relations.size(); i++) {
        char target;
        istringstream sstream(relations.at(i));
        //sstream << (relations.at(i).c_str()); //relations.at(i).c_str()
        sstream >> (passiveObject.height);
        sstream >> passiveObject.width;
        sstream >> target;
        passiveTile = dynamic_cast<Passive*> (m_map.findTile(passiveObject));
        if (passiveTile == nullptr)
            throw std::runtime_error("passive Tile not found");
        
        while(!sstream.eof()){
            Position act;
            sstream >> act.height;
            sstream >> act.width;
            sstream >> target;
            switch(target){
                case 's':
                case 'S':
                        activeTile = dynamic_cast<Active*> (m_map.findTile(act));
                        if (activeTile != nullptr) {
                            activeTile->setLinked(passiveTile);
                        } else {
                            throw std::runtime_error("Active Tile not found to be linked");
                        }
                        break;

                    default:
                        throw std::runtime_error("Invalid Active Tile Link");
            }   
            sstream.ignore(1);
            
        }

    }

}