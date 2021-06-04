//
// bag.cpp: represents the rogue's bag of items
//
// Author: Claudia Poptile
//
// Assignment: Lab 6, 2021
//

#include "bag.h"

#include <iostream>
#include <string>

using namespace std;

Bag::Bag():Collection(10){
}

/**
 * @brief print out the current items in the bag
 */
void Bag::printItems() const {
    cout << "\nYour bag contains the following items:" << endl;
    for(int i = 0; i < MAXITEMS; i++) {
        if(items[i]->getName() != "") {
            cout << items[i]->getName() << " - " << items[i]->getType() << endl;
        }
    }
}

/**
 * @brief print out the treasure left in the bag
 */
void Bag::printTreasure() const{
    cout << "\nYour bag contains the following treasure:" << endl;
    for(int i = 0; i < MAXITEMS; i++) {
        if(items[i]->getType() == "treasure") {
            cout << items[i]->getName() << endl;
        }
    }
    cout << endl;
}

/**
 * @brief gets the name of the teleporter
 * @return name of teleporter
 */
string Bag::getTeleporterName() const {
    string teleporterName = "";
    for(int i = 0; i < MAXITEMS; i++) {
        if(items[i]->getType() == "teleporter") {
            teleporterName = items[i]->getName();
            break;
        }
    }
    return teleporterName;
}

/**
 * @brief checks if bag contains a key
 * @return true if key is in the bag
 */
bool Bag::hasKey() const {
    for(int i = 0; i < MAXITEMS; i++) {
        if(items[i]->getType() == "key") {
            return true;
        }
    }
    return false;
}

