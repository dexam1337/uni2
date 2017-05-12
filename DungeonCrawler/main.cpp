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
                              "#..D.....#", 
                              "#........#", 
                              "#........#",
                              "#........#", 
                              "#.....S..#", 
                              "##########", };

                        vector<string> links {"4386S"};
	GameEngine ge(10, 10, data, links);
	ge.run();
	return 0;

}
