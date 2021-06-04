#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "maze.h"

class GameController
{
private:
    void moveRogue();
    void takeItem();
    void dropItem();
    Maze* maze;
    void move();
    void help() const;
    bool unlock();
    void teleport();

    
public:
    GameController();
    void getInput();
    GameController(Maze* maze);
    void printStatus() const;
    bool doSomething();
};

#endif // GAMECONTROLLER_H
