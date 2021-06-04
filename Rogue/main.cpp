//
// main.cpp: runs the program and reads in the file
//
// Author: Claudia Poptile
//
// Assignment: Lab 4, 2021
//
#include <iostream>
#include <fstream>
#include <string>
#include "maze.h"
#include "gameController.h"

using namespace std;

int main() {
    //prompt for config file
    cout << "Welcome to Rogue" << "\n" << endl;
    cout << "Please enter the path to your configuration file:" << endl;
    string filename;
    cin >> filename;
    ifstream fileIn;
    fileIn.open(filename);
    
    //check for valid config file
    if(!fileIn.good()) {
        cout << "Cannot load file." << endl;
        return 0;
    }
    
    //create Maze to handle reading file
    Maze maze = Maze(&fileIn);
                    
    //create game controller to handle actions
    GameController controller = GameController(&maze);
                    
    //prompt for next move as long as game is not over
    bool gameOver = false;
    while(!gameOver) {
        controller.printStatus();
        gameOver = controller.doSomething();
    }
    
    //delete maze once game is exited
    maze.~Maze();
    
    return 0;
}


