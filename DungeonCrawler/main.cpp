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
        "Door 5 5 Lever 8 5",
        "Character Hans @ 5 5 ConsoleController 7 1",
        "Character Peter % 2 3 StationaryController 1 5",
        "Item Greatsword 3 5"};
    GameEngine ge(10, 10, data, links, 200);
    ge.run();
    return 0;

}
