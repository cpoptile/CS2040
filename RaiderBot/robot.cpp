/*
 * robot.cpp
 *
 *      Author: [TODO]
 */

#include "robot.h"
#include "cell.h"
#include "map.h"
#include <iostream>
#include <cstring>

using namespace std;

Robot:: Robot(Map *map, int startx, int starty){
    mapMap = map;
    xPosition = startx;
    yPosition = starty;
    gold = 0;    
}
  // display robot status in the form of "Robot at 6, 7 (1 gold)" to cout
void Robot::displayStatus(){
    cout << "Robot at "<< xPosition << ", " << yPosition<< " (" << gold << " gold)";
    
}

  // move robot in specified direction (e/w/s/n), returning true
  //   if was able to move in that direction
  // Warning: this method can get long - be sure to write private messages
  //   to break it up
bool Robot:: move(char direction){
    if (direction == 'n') {
        yPosition -= 1;
        if (!checkPosition()){
            yPosition += 1;
            return false;
        }
        mapMap -> cellAt(xPosition, yPosition) -> enter();

    } else if (direction == 'e') {
        xPosition += 1;
        if (!checkPosition()){
            xPosition -= 1;
            return false;
        }        
        mapMap -> cellAt(xPosition, yPosition) -> enter();

    } else if (direction == 's') {
        yPosition += 1;
        if (!checkPosition()){
            yPosition -= 1;
            return false;
        }        
        mapMap -> cellAt(xPosition, yPosition) -> enter();

    } else if (direction == 'w') {
        xPosition -= 1;
        if (!checkPosition()){
            xPosition += 1;
            return false;
        }

    }
    return true;
    
}

// move robot in a series of directions, returning true if was
// able to complete the list of directions
bool Robot::move(std::string commands){
    int length = commands.length();
    char directions[length+1];
    strcpy(directions, commands.c_str());
    for (int i = 0; i < length; i++){
        if (!(this -> move(directions[i]))){
            return false;
        }
    }
    
    return true;
}

bool Robot:: checkPosition(){
    MapCell *potentialCell = mapMap -> cellAt(xPosition, yPosition);
    if (potentialCell -> occupied()){
        if (potentialCell -> hasMountain() || potentialCell -> isWall()){
            cout << "mountain" << endl;
            return false;
        } else if (potentialCell -> hasGold()){
            gold += 1;
            potentialCell -> removeGold();
        }
    }
    return true;
}



