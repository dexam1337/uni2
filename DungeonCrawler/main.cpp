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
        "#...#D#..#",
        "#####D####",
        "#S..#D#..#",
        "#........#",
        "#S..S..S.#",
        "##########",};

    vector<string> links{
        "4 5 D 8 1 S 8 4 S ",
        "5 5 D 8 1 S 8 7 S ",
        "6 5 D 8 4 S 8 7 S 6 1 S ",
        /*Test wenn auf ungültiger Cast angegeben"84S 81S "*/};
    GameEngine ge(10, 10, data, links);
    ge.run();
    return 0;

}
