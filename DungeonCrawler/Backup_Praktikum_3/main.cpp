/*
 * main.cpp
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
        "45D 81S 84S ",
        "55D 81S 87S ",
        "65D 84S 87S ",
        "65D 61S ",
        /*Test wenn auf ungültiger Cast angegeben"84S 81S "*/};
    GameEngine ge(10, 10, data, links);
    ge.run();
    return 0;

}
