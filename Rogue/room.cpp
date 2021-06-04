#include "room.h"
#include "collection.h"

#include <iostream>

using namespace std;

/**
 * @brief constructor
 * @return room object
 */
Room::Room():Collection(5) {
    north = -1;
    east = -1;
    south = -1;
    west = -1;
    number = -1;
    
}

/**
 * @brief print items in current room
 */
void Room::printItems() const {
    for(int i = 0; i < MAXITEMS; i++) {
        if(items[i]->getName() != "") {
            cout << items[i]->getName() << endl;
        }
    }
}

/**
 * @brief print out which directions the player can move in
 */
void Room::printDoors() const {
    if(north != -1) {
        cout << "north" << std::endl;
    }
    if(east != -1) {
        cout << "east" << std::endl;
    }
    if(south != -1) {
        cout << "south" << std::endl;
    }
    if(west != -1) {
        cout << "west" << std::endl;
    }
}

/**
 * @brief checks whether the room has an exit or not
 * @return true if there is an exit
 */
bool Room::hasExit() const {
    for(int i = 0; i < MAXITEMS; i++) {
        if(items[i]->getType() == "exit") {
            return true;
        }
    }
    return false;
}

