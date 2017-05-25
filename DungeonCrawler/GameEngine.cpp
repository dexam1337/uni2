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

GameEngine::GameEngine(const unsigned int height, const unsigned int width,
        const vector<string>& data, const vector<string>& relations) {
    m_map = new DungeonMap(height, width, data);
    m_leave = false;
    m_limit = 2147483647; // Die maximale Anzahl an Spielrunden auf einmal ist das maximum eines integers, wobei das eigentlich obsolet ist.  
    m_round = 0;
    linkObjects(relations);
}

void GameEngine::run() {
    m_map->print();
    while (!finished())
        turn();
}

void GameEngine::turn() {


    //Wenn jeder spielbare Charakter sein eigenes Sichtfeld bekommt entfällt das print an dieser Stelle, 

    for (unsigned int i = 0; i < characters.size(); i++) {
        Position pos;
        try {
            pos = m_map->findCharacter(characters.at(i));
            //Test:
            //characters.at(i)->showInfo(); //Bei eigenem Sichtfeld hier jeden Character seine Sichtweise zeichnen lassen
        } catch (const invalid_argument& ie) {
            //cerr << "Error in turn: " << ie.what() << "\nCharacter wird gelöscht!\n" << endl;
            delete characters.at(i);
            characters.erase(characters.begin()+i);
            break;
        }
        Tile* oldTile = m_map->findTile(pos);
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
                return;
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
                return;
            default:
                cout << "Fehler in switchcase in turn()";
                break;
        }

        system("clear");//nicht gut, unix befehl an cli, sicherheitslücke und systemabhängig
        newTile = m_map->findTile(newPos);
        oldTile->onLeave(newTile);
        m_map->print();
    }

}

bool GameEngine::finished() {
    m_round++;
    cout << endl;
    //cout << m_round << endl;
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
    delete m_map;
}

void GameEngine::linkObjects(const vector<string>& relations) {

    for (int i = 0; i < relations.size(); i++) {
        string target = "";
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
    //m_map->print();
    passiveTile = dynamic_cast<Passive*> (m_map->findTile(passiveObject));
    if (passiveTile == nullptr) //Überprüfung ob Angegebene Koordinate wirklich eine Tür ists
        throw std::runtime_error("passive Tile not found");


    while (!sstream.eof()) {
        Position act;
        sstream >> target;
        sstream >> act.height;
        sstream >> act.width;
        //cout << m_map->findTile(act)->print(); WICHTIG zur überprüfung ob man sich eventuell bei der position der Objekte verzählt hat.
        activeTile = dynamic_cast<Active*> (m_map->findTile(act));
        if (activeTile != nullptr) { //Überprüfung ob die aktuelle Position wirklich ein active Tile ist.
            activeTile->setLinked(passiveTile);
        } else {
            cerr << "Ungültiges activeTile." << endl;
        }


        sstream.ignore(1);

    }
}

void GameEngine::placeCharacter(istringstream& stream) {
    string name, target;
    char symbol;
    int strength, stamina;
    Position pos;
    stream >> name >> symbol >> strength >> stamina >> target >> pos.height >> pos.width; //Variablen vom gegeben Stream füllen
    Controller* controller;
    if (target == "ConsoleController") //Hier Controllerunterscheidungen einfügen
        controller = new ConsoleController(nullptr);
    if (target == "StationaryController")
        controller = new StationaryController(nullptr);
    characters.push_back(new Character(name, symbol, strength, stamina, controller)); //Characterpointer von auf Heap abgelegten Character speichern
    m_map->place(pos, characters.back()); //Charakter in der Spielwelt platzieren
}

void GameEngine::placeItem(istringstream& stream) {
    string target;
    Position pos;
    Item* item;
    stream >> target >> pos.height >> pos.width; //Variablen vom gegeben Stream füllen
    Floor* boden;
    //cout << m_map.findTile(pos);
    boden = dynamic_cast<Floor*> (m_map->findTile(pos));
    if (boden == nullptr) //Überprüfung ob an dieser Stelle ein Item platziert werden kann. Eine Falle geht auch!
        throw std::runtime_error("Can't place Item here");

    if (target == "Greatsword") //hier die fälle für alle möglichen Items einfügen. Ich bin dafür zu faul. Liebe Grüße Vergangenheits-Seb
        item = new Greatsword;
    else
        throw std::runtime_error("Unknow item");

    boden->setItem(item);
}

void GameEngine::showPlayerInfo() {
    for (int i = 0; i < characters.size(); i++)
        characters.at(i)->showInfo();
    cout << endl;
}

void GameEngine::showPlayerInfo(int n) {
    if(n > characters.size())
        throw std::out_of_range("Player does not exist");
    characters.at(n)->showInfo();
    cout << endl;
}

void GameEngine::loadFromFile(string filename) { //Ein nachträglich geladenes Spielfeld wirft einen Segmentationfault
    ifstream save;
    save.open(filename);
    if (save.good() == false) {
        cerr << "Datei konnte nicht geöffnet werden!" << endl;
        return;
    }
    int hoehe, breite;
    save >> hoehe >> breite;
    vector<string> data;
    vector<string> links;
    string line;
    for (int i = 0; i < hoehe; i++) {
        getline(save, line);
        if (line != "") //leere Zeilen ignorieren
            data.push_back(line);
        else
            i--; //wenn noch nicht am ende der Karte angekommen, leere zeilen ignorieren
    }
    do {
        getline(save, line);
        if (line != "") //leere Zeilen ignorieren
            links.push_back(line);

    } while (save.good());


    save.close();

    //this(hoehe, breite, data, links);
    delete m_map;
    for (int i = 0; i < characters.size(); i++)
        delete characters.at(i);
    characters.clear();
    m_map = new DungeonMap(hoehe, breite, data);
    m_leave = false;
    m_limit = 2147483647; // Die maximale Anzahl an Spielrunden auf einmal ist das maximum eines integers, wobei das eigentlich obsolet ist.  
    m_round = 0;
    linkObjects(links);
}

void GameEngine::saveToFile(string filename) {

}
