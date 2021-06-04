#include "maze.h"
#include "room.h"
#include "rogue.h"
#include "item.h"
#include "key.h"
#include "teleporter.h"
#include "treasure.h"
#include "exit.h"

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @brief constructor, reads in game file
 * @param reader file stream
 * @return Maze obejct
 */
Maze::Maze(ifstream* reader) {
    *reader >> this -> numRooms;
    this -> rooms = new Room[numRooms];
    for(int i = 0; i < numRooms; i++) {
        rooms[i].setNumber(i);
    }
    int room;
    *reader >> room;
    if(room > numRooms-1 || room < 0) {
        throw std::invalid_argument("Invalid starting player location");
    }
    this -> rogue = new Rogue(room);
    setRooms(reader);
    setItems(reader);
}


/**
 * @brief moves the rogue 
 * @param direction direction in which rogue is to be moved
 */
void Maze::moveRogue(const string direction) {
    if(direction == "north") {
        if(rooms[rogue->getRoom()].getNorth() != -1) {
            rogue->move(rooms[rogue->getRoom()].getNorth());
        }
    } else if(direction == "south") {
        if(rooms[rogue->getRoom()].getSouth() != -1) {
            rogue->move(rooms[rogue->getRoom()].getSouth());
        }
    } else if(direction == "east") {
        if(rooms[rogue->getRoom()].getEast() != -1) {
            rogue->move(rooms[rogue->getRoom()].getEast());
        }
    } else if(direction == "west") {
        if(rooms[rogue->getRoom()].getWest() != -1) {
            rogue->move(rooms[rogue->getRoom()].getWest());
        }
    }
}

/**
 * @brief connects each room
 * @param reader file stream
 */
void Maze::setRooms(ifstream* reader) {
    //each line in format <start> <endRoom> <side/direction>
    string start;
    int endRoom;
    string direction;
    *reader >> start;
    while(start != "*") {
        *reader >> endRoom;
        *reader >> direction;
        if(direction == "north") {
            rooms[stoi(start)].setNorth(endRoom);
        } else if(direction == "south") {
            rooms[stoi(start)].setSouth(endRoom);
        } else if(direction == "east") {
            rooms[stoi(start)].setEast(endRoom);
        } else {
            rooms[stoi(start)].setWest(endRoom);
        }
        *reader >> start;
    }
}

/**
 * @brief reads in items from file
 * @param reader file stream
 */
void Maze::setItems(ifstream* reader) {
    // each line in format of <room#> <itemType> <itemName>
    int roomIndex;
    string type;
    string name;
    *reader >> roomIndex;
    while(roomIndex != -1) {
        *reader >> type;
        *reader >> name;
        if(type == "key") {
            Item* key = new Key(name);
            rooms[roomIndex].addItem(key);
        } else if(type == "treasure") {
            Item* treasure = new Treasure(name);
            rooms[roomIndex].addItem(treasure);
        } else if(type == "teleporter") {
            Item* teleporter = new Teleporter(name);
            rooms[roomIndex].addItem(teleporter);
        } else {
            Item* exit = new Exit(name);
            rooms[roomIndex].addItem(exit);
        }
//        if (isdigit(*reader>>roomIndex)){
//            *reader >> roomIndex;
//
//        } else{
//            break;
//        }
        *reader >> roomIndex;
    }
}


/**
 * @brief returns room
 * @param name name of room
 * @return room
 */
Room& Maze::getRoom(int name) const {
    return rooms[name];
}

/**
 * @brief destructor
 * @return ?
 */
Maze::~Maze() {
    for(int i = 0; i < numRooms; i++) {
        rooms[i].~Room();
    }
    delete rooms;
    delete rogue;
}