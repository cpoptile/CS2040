#ifndef ROGUE_H
#define ROGUE_H

#include "bag.h"
#include "room.h"

class Rogue
{
private:
    int currentRoom;
    Bag* bag;
public:
    //probably illegal but these are all in-line
    Rogue(int room) {currentRoom = room; bag = new Bag();};
    ~Rogue() {delete bag;} ;
    void move(const int room) {this->currentRoom = room;} ;
    int getRoom() const {return currentRoom;};
    Bag* getBag() const {return bag;};

};

#endif // ROGUE_H
