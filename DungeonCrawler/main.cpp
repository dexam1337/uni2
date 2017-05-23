/*
2 * main.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */
#include <fstream>

#include "GameEngine.h"


bool menue(GameEngine& ge);

int main(int argc, char *argv[]) {

    vector<string> data; //<<Data, data, data!>>he cried impatiently.
    vector<string> links;

    string level = "level1.txt";
    for (int i = 0; i < argc; i++)
        if (argv[i] == "--load")
            level = argv[i + 1];


    ifstream save;
    save.open(level);
    if (save.good() == false)
        throw std::runtime_error("couldn't open file");
    int hoehe, breite;
    save >> hoehe >> breite;
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

    GameEngine ge(hoehe, breite, data, links);

    while (menue(ge)) {

    }
    return 0;

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
            ge.loadFromFile(pfad);
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

