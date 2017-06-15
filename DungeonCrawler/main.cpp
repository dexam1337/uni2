/*
2 * main.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */
#include "GameEngine.h"


bool menue(GameEngine& ge);

int main(int argc, char *argv[]) {

    string level = "level1.txt";
    for (int i = 0; i < argc; i++)
        if (argv[i] == "--load")
            level = argv[i + 1];
    int hoehe = 0, breite = 0;
    vector<string> data;
    vector<string> links;
    
    GameEngine ge(hoehe, breite, data, links);
    
    ge.loadFromFile(level);
    
    while (menue(ge)) {

    }
    return 0;

}

bool menue(GameEngine& ge) {
    int eingabe = -1;
    int player = 0;
    string pfad;
    cout << "1. weiter \n2. infos aller spieler \n3. infos des nten spielers \n4. laden \n0.beenden\n" << endl;
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
        case 5:
            cout << "Speicherpfad?" << endl;
            cin >> pfad;
            ge.saveToFile(pfad);
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

