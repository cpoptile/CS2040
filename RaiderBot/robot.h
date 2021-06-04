/*
 * robot.h
 *      Author: [[TODO]]
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <string>


class MapCell;
class Map;

// A robot which lives on a map at a particular x and y coordinate.
class Robot {
public:
  Robot(Map *map, int startx, int starty);
  // display robot status in the form of "Robot at 6, 7 (1 gold)" to cout
  void displayStatus();
  // move robot in specified direction (e/w/s/n), returning true
  //   if was able to move in that direction
  // Warning: this method can get long - be sure to write private messages
  //   to break it up
  bool move(char direction);
  // move robot in a series of directions, returning true if was
  //   able to complete the list of directions
  bool move(std::string commands);
private:
  // TODO: add data to track the robot's location and the map it occupies
  Map *mapMap;
  int xPosition;
  int yPosition;
  int gold;
//  MapCell currentCell;
  bool checkPosition();
};

#endif /* ROBOT_H_ */