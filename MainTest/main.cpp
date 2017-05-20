/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sebastian
 *
 * Created on May 18, 2017, 12:32 PM
 */

#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


/*
 * 
 */

vector<bool> getMorse(char character);

int main(int argc, char** argv) {

    string msg;
    cout << "Enter your text to cat-morse" << endl;
    cin.clear();
    getline(cin, msg);
    for(unsigned int i = 0; i < msg.size(); i++){
        if(msg[i] == ' ')
            cout << ' ';
        else{
            vector<bool> morse = getMorse(msg[i]);
            for(unsigned int j = 0; j < morse.size(); j++){
                if(morse.at(j))
                    cout << "Miau ";
                else
                    cout << "Meow ";
            }
            
        }
        cout << endl;
    }
    
    

    return 0;
}

//returns array of bool meaning 0 for short and true for long 

vector<bool> getMorse(char character) {
    vector<bool> toReturn;
    switch (character) {
        case 'A':
        case 'a':
            toReturn.push_back(false);
            toReturn.push_back(true);
            break;
        case 'B':
        case 'b':
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case 'C':
        case 'c':
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(false);
            break;
        case 'D':
        case 'd':
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case 'E':
        case 'e':
            toReturn.push_back(false);
            break;
        case 'F':
        case 'f':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(false);
            break;
        case 'G':
        case 'g':
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(false);
            break;
        case 'H':
        case 'h':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case 'I':
        case 'i':
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case 'J':
        case 'j':
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            break;
        case 'K':
        case 'k':
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(true);
            break;
        case 'L':
        case 'l':
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case 'M':
        case 'm':
            toReturn.push_back(true);
            toReturn.push_back(true);
            break;
        case 'N':
        case 'n':
            toReturn.push_back(true);
            toReturn.push_back(false);
            break;
        case 'O':
        case 'o':
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            break;
        case 'P':
        case 'p':
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(false);
            break;
        case 'Q':
        case 'q':
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(true);
            break;
        case 'R':
        case 'r':
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(false);
            break;
        case 'S':
        case 's':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case 'T':
        case 't':
            toReturn.push_back(true);
            break;
        case 'U':
        case 'u':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(true);
            break;
        case 'V':
        case 'v':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(true);
            break;
        case 'W':
        case 'w':
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(true);
            break;
        case 'X':
        case 'x':
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(true);
            break;
        case 'Y':
        case 'y':
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(true);
            break;
        case 'Z':
        case 'z':
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case '0':
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            break;
        case '1':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            break;
        case '2':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            break;
        case '3':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(true);
            toReturn.push_back(true);
            break;
        case '4':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(true);
            break;
        case '5':
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case '6':
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case '7':
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case '8':
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(false);
            toReturn.push_back(false);
            break;
        case '9':
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(true);
            toReturn.push_back(false);
            break;

        default:
            break;

    }
    return toReturn;
}