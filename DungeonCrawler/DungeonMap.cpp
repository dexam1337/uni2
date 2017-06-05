/*
 * DungeonMap.cpp
 *
 *  Created on: 23.04.2017
 *      Author: sebastian
 */

//#include <memory>

#include "DungeonMap.h"
#include <math.h>

DungeonMap::DungeonMap(const unsigned int height, const unsigned int width,
        const vector<string>& data) {
    m_maxHeight = height;
    m_maxWidth = width;

    m_map = new Tile**[height];
    for (unsigned int i = 0; i < height; i++) {
        m_map[i] = new Tile*[width];
        for (unsigned int j = 0; j < width; j++) {
            // cout << i << " " << j << endl;
            switch (data.at(i).at(j)) {
                case '.':
                    m_map[i][j] = new Floor(nullptr, nullptr);
                    break;
                case '#':
                    m_map[i][j] = new Wall();
                    break;
                case 'X':
                    m_map[i][j] = new Door();
                    break;
                case '/':
                    m_map[i][j] = new Door();
                    dynamic_cast<Door*> (m_map[i][j])->use();
                    break;
                case 'S':
                    m_map[i][j] = new Switch(nullptr);
                    break;
                case 's':
                    m_map[i][j] = new Switch(nullptr);
                    dynamic_cast<Switch*> (m_map[i][j])->use();
                    break;
                case 'L':
                    m_map[i][j] = new Lever(nullptr);
                    break;
                    case 'l':
                    m_map[i][j] = new Lever(nullptr);
                    dynamic_cast<Lever*> (m_map[i][j])->use();
                    break;
                case 't':
                    m_map[i][j] = new Trap(nullptr, -20);
                    break;
                case 'T':
                    m_map[i][j] = new Trap(nullptr, -20);
                    dynamic_cast<Trap*> (m_map[i][j])->setActivated(true);
                    break;
                default:
                    throw std::runtime_error("invalid Tile Type requested");
            }
        }
    }
}

DungeonMap::~DungeonMap() {
    for (unsigned int i = 0; i < m_maxHeight; i++) {
        for (unsigned int j = 0; j < m_maxWidth; j++)
            delete m_map[i][j];
        delete[] m_map[i];
    }
    delete[] m_map;

    m_map = nullptr;
    m_maxHeight = 0;
    m_maxWidth = 0;
}

/*
DungeonMap::DungeonMap(DungeonMap& map) {
    m_maxHeight = map.m_maxHeight;
    m_maxWidth = map.m_maxWidth;
    Position pos;
    m_map = new Tile**[m_maxHeight];
    for (unsigned int i = 0; i < m_maxHeight; i++) {
        pos.height = i;
        m_map[i] = new Tile*[m_maxWidth];
        for (unsigned int j = 0; j < m_maxWidth; j++) {
            pos.width = j;
            m_map[i][j] = map.findTile(pos);
        }
    }
}*/

void DungeonMap::place(Position pos, Character* c) {
    if (pos.height > m_maxHeight || pos.width > m_maxWidth)
        throw out_of_range("Zielposition außerhalb des Spielfelds");
    m_map[pos.height][pos.width]->setCharacter(c);
}

Position DungeonMap::findTile(Tile* t) {
    for (unsigned int i = 0; i < m_maxHeight; i++) {
        for (unsigned int j = 0; j < m_maxWidth; j++) {
            if (m_map[i][j] == t) {
                Position p;
                p.height = i;
                p.width = j;
                return p;
            }
        }
    }
    throw out_of_range("Tile außerhalb des Spielfelds");
}

Tile* DungeonMap::findTile(Position pos) {
    if (pos.height >= m_maxHeight || pos.width >= m_maxWidth)
        throw out_of_range("Gesuchtes Tile außerhalb des Spielfelds");
    return m_map[pos.height][pos.width];
}

Position DungeonMap::findCharacter(Character* c) {
    for (unsigned int i = 0; i < m_maxHeight; i++) {
        for (unsigned int j = 0; j < m_maxWidth; j++) {
            if (m_map[i][j]->getCharacter() == c) {
                Position p;
                p.height = i;
                p.width = j;
                return p;
            }
        }
    }
    throw invalid_argument("Character außerhalb des Spielfelds");
}

void DungeonMap::print(Position center) {
    
    for (unsigned int i = 0; i < m_maxHeight; i++) {
        for (unsigned int j = 0; j < m_maxWidth; j++) {
            Position aktPos;
            aktPos.height=i;
            aktPos.width=j;
            if(hasLineOfSight(center,aktPos)){
                cout << m_map[i][j]->print();
            }else{
                cout<< "#";
            }
        }
        cout << endl;
    }

}


bool DungeonMap::hasLineOfSight(Position from, Position to)
{
    double x = to.width - from.width;  
    double y = to.height - from.height;
    double len = sqrt( (x*x) + (y*y) );

    if(!len)  //eigene Tile
        return true;

    double stepx = x / len;
    double stepy = y / len;

    x = from.width;
    y = from.height;
    for( double i = 0; i < len; i += 1 )
    {
        if( m_map[static_cast<int>(y)][static_cast<int>(x)]->isTransparent() == false)
            return false;

        x += stepx; 
        y += stepy;
    }
    return true;//hat sicht*/
}

ostream& operator<<(ostream& outputstream, const DungeonMap& map){
    
    //Hier wie die karte in den stream Eingefuegt werden soll
    
    return outputstream;
}

istream& operator>>(istream& inputstream, Position& pos){
    char tmp;
    inputstream >> pos.height >> tmp >> pos.width;
    return inputstream;
}