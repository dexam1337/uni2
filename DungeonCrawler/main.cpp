/*
2 * main.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */
#include "GameEngine.h"

void loadFromFile(string filename);
bool menue(GameEngine& ge);

int main(int argc,char *argv[]) {

    
    vector<string> data{
        "##########",
        "####.....#",
        "###......#",
        "##.......#",
        "#........#",
        "#####D####",
        "#....T...#",
        "#........#",
        "#....L...#",
        "##########",};

    vector<string> links{
        "Door 5 5 Lever 8 5", //hint: falls mehr passive Tiles als Door existieren, befehlsidentifier durch "Passive" ersetzen und dort dann zwischen den passive Tiles unterschgeiden
        "Character Hans @ 5 5 ConsoleController 7 1", //Syntax: EinheitenTyp Name zeichen Stärke Stamina Controller Xpos Ypos
        "Character Peter % 2 3 StationaryController 1 5",
        "Item Greatsword 3 5"}; //Was? Was genau?, Wohin?*/
    GameEngine ge(10, 10, data, links, 200);
    
    while(menue(ge)){
        
    }
    return 0;

}

void loadFromFile(string filename){
    cout << filename << endl;
}
bool menue(GameEngine& ge){
    int eingabe = -1;
    int player = 0;
    string pfad;
    cout << "1. weiter \n2. infos aller spieler \n3. infos des nten spielers \n4. laden \n0.beenden" << endl;
        cin >> eingabe;
        switch(eingabe){
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
                loadFromFile(pfad);
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