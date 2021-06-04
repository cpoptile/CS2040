#ifndef MAZE_H
#define MAZE_H

#include "room.h"
#include "rogue.h"

class Maze
{
private:
    int numRooms;
    Room* rooms;
    Rogue* rogue;
    void setRooms(std::ifstream* fin);
    void setItems(std::ifstream* fin);

public:
    Maze(std::ifstream* fin);
    ~Maze();
    void moveRogue(const std::string direction);
    Rogue* getRogue() const { return rogue; } ;
    Room& getRoom(int name) const;
};

#endif // MAZE_H
