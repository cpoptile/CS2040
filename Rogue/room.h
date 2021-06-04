#ifndef ROOM_H
#define ROOM_H

#include "collection.h"
 
class Room : public Collection
{
private:
    int number;
    int north;
    int south;
    int east;
    int west;
public:
    Room();
    ~Room() { };
    //in-line functions
    void setNumber(const int number) { this -> number = number; } ;
    int getNumber() const { return number; } ;
    void setNorth(const int roomNumber) { this -> north = roomNumber; } ;
    int getNorth() const { return north; } ;
    void setEast(const int roomNumber) { this -> east = roomNumber; } ;
    int getEast() const { return east; } ;
    void setSouth(const int roomNumber) { this -> south = roomNumber; } ;
    int getSouth() const { return south; } ;
    void setWest(const int roomNumber) {this -> west = roomNumber; } ;
    int getWest() const { return west; } ;
    void printItems() const override;
    void printDoors() const;
    bool hasExit() const;
};
 
#endif // ROOM_H
