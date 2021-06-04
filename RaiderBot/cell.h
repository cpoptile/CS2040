/*
 * cell.h
 *
 *      Author: Claudia Poptile
 */

#ifndef CELL_H_
#define CELL_H_

// Tracks the contents of a particular cell on the map.
// Is there gold at this location, is it occupied by a robot,
// is there a mountain there? Each cell needs to track
// where it is on the grid (x, y) and the type of
// object at that location. The provided methods are suggestions;
// feel free to add/remove as needed.
class MapCell {
  int xLocation, yLocation;
  char token;
  char oldToken;
  bool hasRobot;
public:
  MapCell(int x, int y, char symbol);
  MapCell();
  void initialize(int x, int y, char symbol);
  // true if mountain at this location
  bool hasMountain();
  // true if gold at this location
  bool hasGold();
  bool isWall();
  // remove the gold at this location
  void removeGold();
  // is this location occupied by something that the robot
  //   cannot move over?
  bool occupied();
  // return the character to display for this location
  char display();
  // robot enters location
  void enter();
  // robot leaves location
  void vacate();
  
};

#endif /* CELL_H_ */