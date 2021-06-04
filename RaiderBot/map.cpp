/*
 * map.cpp
 *
 *      Author: [TODO]
 */

#include "map.h"
#include "cell.h"
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

Map:: Map(){
}

// read the map from cin
void Map:: load(){
    string line;
    int rows = 0;
    //skip first wall
    getline(cin,line);
    getline(cin,line);
    
    while (rows < HEIGHT){
        int length = line.length();
        char characters[length-1];
        strcpy(characters, line.c_str());
        for (int i = 0; i < WIDTH; i++){
            char symbol = characters[i+1];
//            MapCell cell = MapCell(i, rows, symbol);
//            MapCell *c = new MapCell();
//            c -> initialize(i, rows, symbol); 
            MapCell *c = new MapCell(i, rows, symbol);
//            cells[rows][i] = &cell;
            cells[i][rows] = c;
//            cout << "x is " << i << "y is " << rows << "symbol is " << symbol<< endl;        
        }
        getline(cin, line);
        rows++;
    }

}

// write the full map to cout
void Map::write(){
    cout << "+--------------------+" << endl;
    int height = 0;
    while (height < HEIGHT){
        cout << "|";
        string line = "";
        for (int col = 0; col < WIDTH; col++){
            char token = cells[col][height] -> display();
//            cout << "UHHH " << token << endl;
            line += token;
        }
        height++;
        cout << line << "|" << endl;
    }
    cout << "+--------------------+" << endl;
}

MapCell* Map::cellAt(int x, int y){
    return cells[x][y];
    
}


Map::~Map() {
  for(int row = 0; row < HEIGHT; ++row) {
       for(int col = 0; col < WIDTH; ++col) {
          delete cells[row][col];
  }
}
}
