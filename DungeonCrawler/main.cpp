/*
2 * main.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */
#include <fstream>

#include "GameEngine.h"

void loadFromFile(string filename, GameEngine& ge);
bool menue(GameEngine& ge);

int main(int argc, char *argv[]) {

    vector<string> data;
    vector<string> links;
    GameEngine ge(0, 0, data, links);

    loadFromFile(argv[1], ge);

    while (menue(ge)) {

    }
    return 0;

}

void loadFromFile(string filename, GameEngine& ge) {
    ifstream save;
    save.open(filename);
    if (save.good() == false)
        throw std::runtime_error("couldn't open file");
    int hoehe, breite;
    save >> hoehe >> breite;
    vector<string> data;
    vector<string> links;
    string line;
    for (int i = 0; i <= hoehe; i++) {
        getline(save, line);
        data.push_back(line);
    }
    data.erase(data.begin());
    do {
        getline(save, line);
        links.push_back(line);

    } while (save.good());
    
    links.pop_back();

    save.close();
    ge = GameEngine(hoehe, breite, data, links); //objekt wird beim verlassen der schleife zerstört.
}

bool menue(GameEngine& ge) {
    int eingabe = -1;
    int player = 0;
    string pfad;
    cout << "1. weiter \n2. infos aller spieler \n3. infos des nten spielers \n4. laden \n0.beenden" << endl;
    cin >> eingabe;
    switch (eingabe) {
        case 1:
            ge.run();
            break;
        case 2:
            ge.showPlayerInfo();
            break;
        case 3:
            cout << "Welcher Spieler?" << endl;
            cin >> player;
            ge.showPlayerInfo(player);
            break;
        case 4:
            cout << "Spielpfad?" << endl;
            cin >> pfad;
            loadFromFile(pfad, ge);
            break;
        case 0:
            cout << "ende" << endl;
            return false;
            break;
        default:
            break;
    }
    return true;
}