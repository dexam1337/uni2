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
        "##..#D#..#",
        "#...#D#..#",
        "#####D####",
        "#...#D#..#",
        "#........#",
        "#S.S.S.S.#",
        "##########",};

    vector<string> links{
        "3 5 D 8 1 S 8 5 S 8 7 S",
        "4 5 D 8 1 S 8 3 S",
        "5 5 D 8 3 S 8 5 S",
        "6 5 D 8 5 S",
        /*Test wenn auf ungültiger Cast angegeben"84S 81S "*/};
    GameEngine ge(10, 10, data, links, 200);
    ge.run();
    return 0;

}
