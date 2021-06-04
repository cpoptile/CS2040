#include "gameController.h"
#include <iostream>
#include <string>
#include "gameController.h"
#include "key.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief controller
 * @param maze maze to be played on
 * @return GameController object
 */
GameController::GameController(Maze* maze):maze(maze){
}

/**
 * @brief prints the current status of the player
 */
void GameController::printStatus() const {
    cout << "\nYou are in one of the maze rooms. A sign on the wall says, ";
    int currentRoom = maze->getRogue()->getRoom();
    cout << "'Welcome to room " << currentRoom << "'." << endl;
    cout << "Looking around you see the following items:" << endl;
    maze->getRoom(currentRoom).printItems();
    cout << "The room has doors in the following directions:" << endl;
    maze->getRoom(currentRoom).printDoors();
}

/**
 * @brief prompts for turn and handles
 * @return true if turn performed
 */
bool GameController::doSomething() {
    bool gameOver = false;
    cout << "\nWhat would you like to do?" << endl;
    string turn;
    cin >> turn;
    // input should be case insensitive
    transform(turn.begin(), turn.end(), turn.begin(), ::tolower);
    if(turn == "turn") {
        move();
    } else if(turn == "take") {
        takeItem();
    } else if(turn == "drop") {
        dropItem();
    } else if(turn == "teleport") {
        teleport();
    } else if(turn == "help") {
        help();
    } else if(turn == "showbag") {
        maze->getRogue()->getBag()->printItems();
    } else if(turn == "unlock") {
        gameOver = unlock();
        if(gameOver) { maze->getRogue()->getBag()->printTreasure(); }
    } else if(turn == "exit") {
        std::cout << "\nOpe you lost" << std::endl;
        gameOver = true;
    } else {
        std::cout << "\nI don't know how to " << turn << "." << std::endl;
    }
    return gameOver;
}

/**
 * @brief handle turnment of player into other rooms
 */
void GameController::move() {
    int currentRoom = maze->getRogue()->getRoom();
    string direction;
    cin >> direction;
    //turns are case insensitive
    transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
    if(direction == "north") {
        if(maze->getRoom(currentRoom).getNorth() != -1) {
            maze->moveRogue("north");
        } else {
            cout << "\nYou can't turn in that direction!" << endl;
        }
    } else if(direction == "east") {
        if(maze->getRoom(currentRoom).getEast() != -1) {
            maze->moveRogue("east");
        } else {
            cout << "\nYou can't turn in that direction!" << endl;
        }
    } else if(direction == "south") {
        if(maze->getRoom(currentRoom).getSouth() != -1) {
            maze->moveRogue("south");
        } else {
            cout << "nYou can't turn in that direction!" << endl;
        }
    } else if(direction == "west") {
        if(maze->getRoom(currentRoom).getWest() != -1) {
            maze->moveRogue("west");
        } else {
            cout << "\nYou can't turn in that direction!" << endl;
        }
    } else {
        cout << "\nThat is not a valid direction!" << endl;
    }
}

/**
 * @brief picks up an item
 */
void GameController::takeItem() {
    string name;
    cin >> name;
    string lowercase = name;
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    if(maze->getRoom(maze->getRogue()->getRoom()).contains(lowercase)) {
        if(maze->getRogue()->getBag()->isFull()) {
            cout << "\nYour bag is already full!" << endl;
        } else {
            Item* item = maze->getRoom(maze->getRogue()->getRoom()).removeItem(lowercase);
            if(item->getType() != "exit") {
                maze->getRogue()->getBag()->addItem(item);
                cout << "\n" << name << " picked up and added to your bag." << std::endl;
            } else {
                maze->getRoom(maze->getRogue()->getRoom()).addItem(item);
                cout << "\nWhy would you try picking up an exit??? huh???" << std::endl;
            }
        }
    } else {
        cout << "\nYou dont see a " << name << " to take!" << std::endl;
    }
}

/**
 * @brief return an item from the bag
 */
void GameController::dropItem() {
    string name;
    cin >> name;
    string lowercase = name;
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    if(maze->getRogue()->getBag()->contains(lowercase)) {
        if(maze->getRoom(maze->getRogue()->getRoom()).isFull()) {
            cout << "\nThis room cannot store any more items!" << endl;
        } else {
            Item* item = maze->getRogue()->getBag()->removeItem(lowercase);
            maze->getRoom(maze->getRogue()->getRoom()).addItem(item);
            cout << "\n" << name << " dropped." << endl;
        }
    }
}

/**
 * @brief teleports the player to another room
 */
void GameController::teleport() {
    int roomNumber;
    cin >> roomNumber;
    string teleporterName = maze->getRogue()->getBag()->getTeleporterName();
    //item names case insensitive
    transform(teleporterName.begin(), teleporterName.end(), teleporterName.begin(), ::tolower);
    if(teleporterName != "") {
        maze->getRogue()->move(roomNumber);
        //return teleporter once used
        maze->getRogue()->getBag()->removeItem(teleporterName);
        cout << "\nYou teleported to room " << roomNumber << endl;
    } else {
        cout << "\nYou cannot teleport without a teleporter" << endl;
    }
}

/**
 * @brief help menu
 */
void GameController::help() const {
    cout << "\nCommands:" 
    << "\nturn <direction> - turn the player in the given direction"
    << "\ntake <item> - pick up an item and put it into your bag" 
    << "\ndrop <item> - drop an item from your bag into the room" 
    << "\nshowbag - print the contents of your bag"
    << "\nteleport <room> - teleport to a given room (if you have a teleporter)"
    << "\nhelp - prints out a list of commands and a short description of each"
    << "\nunlock - unlocks the exit to the maze (if you have the key and are in the room with the exit)"
    << "\nexit - exits the game" << std::endl;
}

/**
 * @brief check whether the exit can be unlocked
 * @return true if player has key and is in exit room
 */
bool GameController::unlock() {
    bool hasExit = maze->getRoom(maze->getRogue()->getRoom()).hasExit();
    bool hasKey = maze->getRogue()->getBag()->hasKey();
    if(hasExit && hasKey) {
        cout << "\nCongratulations! You escaped the maze!" << endl;
        return true;
    } else if(!hasExit && hasKey) {
        cout << "\nYou are not in the room with the exit!" << endl;
    } else if(hasExit && !hasKey) {
        cout << "\nYou do not have the key to open the exit!" << endl;
    } else {
        cout << "\nYou are not in the room with the exit and you do not have the key!" << endl;
    }
    return false;
}


