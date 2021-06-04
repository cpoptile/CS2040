//
// pool.cpp: implements class Pool
//
// Author: Claudia Poptile
//
// Assignment: Lab 4, 2021
//

#include "pool.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * Constructor for pool class
 * 
 */
Pool::Pool() {
    index = 0;
}

/*
 * Method adds a name to Pool's array
 * 
 * @param name name to be added
 */
void Pool::add(string name) {
  names[index] = name;
  index++;
}

/*
 * Method reads in names from the file
 *
 */
void Pool::readNames(){
    // read names until reach end of file, END, or MAXNAMES items
    string name;
    string end = "END";
    cin >> name;
    while (name != end && index < MAXNAMES && !cin.eof() && name != "" ){
        this->add(name);
        cin >> name;
    }
    
}
/*
 * Method checks if pool is empty
 * 
 */
bool Pool::empty(){
    return index == 0;
}

/*
 * Method prints the matches for a name
 * 
 * @param x name to be matches
 */
void Pool:: printMatches(string x){
    string y;
    // iterate through each word in names[]
    for (int i = 0; i < index; i++) {
        // proceed if strings are not equal
        if (names[i] != x) {
            this -> findNameMatches(i, x);
        }
    }    
}

/*
 * Method prints the matches between two pools
 * 
 * @param *otherPool the other pool to be compared to
 */
void Pool:: printMatches(Pool *otherPool){
    //iterate through current pool names[]
    for (int i = 0; i < index; i++){
        string name = names[i];
        otherPool -> printMatches(name);
    }
    
}

/*
 * Method finds a name comparing two names
 * 
 * @param i the index of the names array
 * @param x the name being matched
 */ 
void Pool:: findNameMatches(int i, string x){
    string y;
    // iterate through each char in x
    for (size_t j = 0; j < x.length(); j++) {
        // if char not _ and names[] word contains char in x, print match
        if (x[j] != '_' && names[i].find(x[j]) < names[i].length()) {
            // double counting letters
            if (names[i] != y){
                cout << "A perfect match for " + x +": " + names[i]<< endl;
            }
            y = names[i];

        }
    }
}
