/*
 * main.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */
#include "GameEngine.h"

int main() {

	vector<string> data { "##########", 
                              "####.....#", 
                              "###......#",
                              "##.......#", 
                              "#...#D#..#", 
                              "#####D####", 
                              "#...#D#..#",
                              "#........#", 
                              "#S.S.S.S.#", 
                              "##########", };

                        vector<string> links {"45D81S85S",
                                              "55D81S83S",
                                              "65D85S87S"};
	GameEngine ge(10, 10, data, links);
	ge.run();
	return 0;

}
