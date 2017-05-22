/*
 * GameEngine.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */
#include "GameEngine.h"
#include "StationaryController.h"
//#include <iostream>
#include <sstream>
#include <fstream>

/*
GameEngine::GameEngine(const unsigned int height, const unsigned int width,
        const vector<string>& data) :
m_map(height, width, data) {

    cout << "Wie viele Runden?" << endl;
    cin >> m_limit;
    //	m_map = DungeonMap(height, width, data);
    //characters.push_back(new Character('o', 10, 10)); //Wegen pointer
    //Position pos;
    //pos.height = 7;
    //pos.width = 2;
    //m_map.place(pos, characters.at(0));
    m_round = 0;
 //<<Data, data, DATA!>> he cried impatiently.
}

GameEngine::GameEngine(const unsigned int height, const unsigned int width,
        const vector<string>& data, int limit) :
m_map(height, width, data) {

    m_limit = limit;
    //	m_map = DungeonMap(height, width, data);
    //characters.push_back(new Character('o', 10, 10)); //Wegen pointer
    //Position pos;
    //pos.height = 7;
    //pos.width = 2;
    //m_map.place(pos, characters.at(0));
    m_round = 0;

}*/

GameEngine::GameEngine(const unsigned int height, const unsigned int width,
        const vector<string>& data, const vector<string>& relations) :
m_map(height, width, data) {
    m_leave = false;
    m_limit = 2147483647;
    //cout << "Wie viele Runden?" << endl;
    //cin >> m_limit;
    //	m_map = DungeonMap(height, width, data);
    //characters.push_back(new Character('o', 10, 10)); //Wegen pointer
    //Position pos;
    //pos.height = 7;
    //pos.width = 2;
    //m_map.place(pos, characters.at(0));
    m_round = 0;
    linkObjects(relations);
}

GameEngine::GameEngine(const unsigned int height, const unsigned int width,
        const vector<string>& data, const vector<string>& relations, int limit) :
m_map(height, width, data) {
    m_leave = false;
    m_limit = limit;
    //	m_map = DungeonMap(height, width, data);
    //characters.push_back(new Character('o', 10, 10)); //Wegen pointer
    //Position pos;
    //pos.height = 7;
    //pos.width = 2;
    //m_map.place(pos, characters.at(0));
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
            //Test:
            //characters.at(i)->showInfo();
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
                m_leave = true;
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
    cout << endl;
    //cout << m_round << endl;
    m_map.print();
    if (m_leave == true)
        return true;
    else if (m_round <= m_limit)
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



    for (int i = 0; i < relations.size(); i++) {
        string target;
        istringstream sstream(relations.at(i));
        //sstream << (relations.at(i).c_str()); //relations.at(i).c_str()
        sstream >> target;
        if (target == "Door")//Hier alle möglichen Befehlsclassifier einfügen
            doorConnector(sstream);
        else if (target == "Character")
            placeCharacter(sstream);
        else if (target == "Item")
            placeItem(sstream);
        else
            throw std::runtime_error("Unknown target in relations");



    }

}

void GameEngine::doorConnector(istringstream& sstream) {
    string target;
    Passive* passiveTile;
    Active* activeTile;
    Position passiveObject;

    sstream >> (passiveObject.height);
    sstream >> passiveObject.width;

    passiveTile = dynamic_cast<Passive*> (m_map.findTile(passiveObject));
    if (passiveTile == nullptr)
        throw std::runtime_error("passive Tile not found");


    while (!sstream.eof()) {
        Position act;
        sstream >> target;
        sstream >> act.height;
        sstream >> act.width;

        activeTile = dynamic_cast<Active*> (m_map.findTile(act));
        if (activeTile != nullptr) {
            activeTile->setLinked(passiveTile);
        } else {
            throw std::runtime_error("Active Tile not found to be linked");
        }


        sstream.ignore(1);

    }
}

void GameEngine::placeCharacter(istringstream& stream) {
    string name;
    char symbol;
    int strength;
    int stamina;
    Position pos;
    string target;
    stream >> name >> symbol >> strength >> stamina >> target >> pos.height >> pos.width;
    Controller* controller;
    if (target == "ConsoleController")
        controller = new ConsoleController(nullptr);
    if (target == "StationaryController")
        controller = new StationaryController(nullptr);
    characters.push_back(new Character(name, symbol, strength, stamina, controller));
    m_map.place(pos, characters.back());
}

void GameEngine::placeItem(istringstream& stream) {
    string target;
    Position pos;
    Item* item;
    stream >> target >> pos.height >> pos.width;
    Floor* boden;
    boden = dynamic_cast<Floor*> (m_map.findTile(pos));
    if (boden == nullptr)
        throw std::runtime_error("Can't place Item here");

    if (target == "Greatsword") //hier die fälle für alle möglichen Items einfügen. Ich bin dafür zu faul. Liebe Grüße Vergangenheits-Seb
        item = new Greatsword;
    else
        throw std::runtime_error("Unknow item");

    boden->setItem(item);
}

void GameEngine::showPlayerInfo(){
    for(int i = 0; i < characters.size(); i++)
        characters.at(i)->showInfo();
    cout << endl;
}

void GameEngine::showPlayerInfo(int n){
    characters.at(n)->showInfo();
    cout << endl;
}