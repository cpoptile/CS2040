/*
 * cell.cpp
 *
 *      Author: [TODO]
 */

#include "cell.h"

 
MapCell::MapCell(int x, int y, char symbol){
    xLocation = x;
    yLocation =y;
    token = symbol;
}

void MapCell::initialize(int x, int y, char symbol){
    xLocation = x;
    yLocation =y;
    token = symbol;
}

MapCell::MapCell(){
    
}

bool MapCell:: hasMountain(){
    return token == '#';
}

bool MapCell:: hasGold(){
    return token == '*';
}

bool MapCell:: isWall(){
    return token == '|' || token == '-';
}
 

void MapCell:: removeGold(){
    token = ' ';
}

bool MapCell::occupied(){
    return token == '#' || token == '-' || token == '|' || token == '+';
}

char MapCell::display(){
    return token;
}

void MapCell::enter(){
    oldToken = token;
    token = 'R';
}

void MapCell:: vacate(){
    token = oldToken;
}

