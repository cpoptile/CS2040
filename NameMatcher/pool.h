//
// pool.h: declares the class Pool
//
// Author: Claudia Poptile
//
// Assignment: Lab 4, 2021
//

// do not change the next two lines - we will explain later
#ifndef _pool_h
#define _pool_h

#include <iostream>
#include <string>

using namespace std;

class Pool {
public:
  Pool();
  // add name to pool of people to match
  void add(string name);
  // read names until reach end of file, END, or MAXNAMES items
  void readNames();
  // check if pool is empty
  bool empty();
  // TODO: add methods to print matches
  void printMatches(string x);
  void printMatches(Pool *otherPool);

private:
  static constexpr int MAXNAMES = 20;
  string names[MAXNAMES] = {""};
  int index;
  void findNameMatches(int i, string x);
};

// do not touch the next line
#endif