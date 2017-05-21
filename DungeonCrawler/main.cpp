/*
2 * main.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */
#include "GameEngine.h"

int main() {

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
        "Item Greatsword 3 5"}; //Was? Was genau?, Wohin?
    GameEngine ge(10, 10, data, links, 200);
    ge.run();
    return 0;

}
