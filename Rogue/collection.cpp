//
// collection.cpp: abstract class that represents a collection of items
//
// Author: Claudia Poptile
//
// Assignment: Lab 6, 2021
//
#include "collection.h"
#include "item.h"
#include "key.h"
#include "teleporter.h"
#include "treasure.h"
#include "exit.h"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


/**
 * @brief constructor
 * @param MAXITEMS max number of items in collection
 * @return Collection object
 */
Collection::Collection(int MAXITEMS)
{
    MAXITEMS = MAXITEMS;
    numItems = 0;
    this -> items = new Item*[MAXITEMS];
    for(int i = 0; i < MAXITEMS; i++) {
        items[i] = new Item();
    }
}

/**
 * @brief check if colleciton is full, max is 10 items
 * @return true if full
 */
bool Collection::isFull() const {
    return numItems == MAXITEMS;
}

/**
 * @brief checks whether an item is in the collection
 * @param itemName name of item being checked
 * @return true if item is contained
 */
bool Collection::contains(string itemName) const {
    for(int i = 0; i < MAXITEMS; i++) {
        string name = items[i]->getName();
        //make string lowercase
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(name == itemName) {
            return true;
        }
    }
    return false;
}

/**
 * @brief add method to collection
 * @return true if successfully added
 */
bool Collection::addItem(Item* const item) {
    for(int i = 0; i < MAXITEMS; i++) {
        if(items[i]->getName() == "") {
            delete items[i];
            items[i] = item;
            numItems++;
            return true;
        }
    }
    return false;
}

/**
 * @brief remove an item from the collection
 * @param itemName name of the item
 * @return the item removed
 */
Item* Collection::removeItem(const string itemName) {
    Item* removed;
    for(int i = 0; i < MAXITEMS; i++) {
        string name = items[i]->getName();
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(name == itemName) {
            if(items[i]->getType() == "key") {
                removed = new Key(*items[i]);
            } else if(items[i]->getType() == "exit") {
                removed = new Exit(*items[i]);
            } else if(items[i]->getType() == "teleporter") {
                removed = new Teleporter(*items[i]);
            } else if(items[i]->getType() == "treasure") {
                removed = new Treasure(*items[i]);
            } else {
                removed = new Item(*items[i]);
            }
            delete items[i];
            //blank item to hold its place
            items[i] = new Item();
            numItems--;
            break;
        }
    }
    return removed;
}

/**
 * @brief destructor
 * @return no clue
 */
Collection::~Collection()
{
    for(int i = 0; i < MAXITEMS; i++) {
        //delete each item
        delete items[i];
    }
    //delete the array
    delete [] items;
}

