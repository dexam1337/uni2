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
                              "#..D..D..#", 
                              "#........#", 
                              "#........#",
                              "#........#", 
                              "#S.S..S..#", 
                              "##########", };

                        vector<string> links {"43D83S86S",
                                              "46D81S"};
	GameEngine ge(10, 10, data, links);
	ge.run();
	return 0;

}
