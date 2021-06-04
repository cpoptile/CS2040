#include "word.h"
#include <string>

using namespace std;

Word::Word(string w){
    word = w;
    frequency = 1;
}


string Word:: getWord(){
    return word;
}

double Word:: getFrequency(){
    return frequency;
}

void Word:: setFrequency(int freq){
    frequency = freq;
}

bool Word:: operator== (const Word& rhs) const{
    return word == rhs.word;
}

bool Word:: operator> (const Word& rhs) const{
    if (frequency != rhs.frequency){
        return frequency > rhs.frequency;
    } else {
        return word > rhs.word;
    }
//    if (frequency > rhs.frequency){
//        return true;
//    } else if (frequency == rhs.frequency){
//        if (word > rhs.word) {
//            return true;
//        }
//    }
//    return false;
//    
}

bool Word:: operator< (const Word& rhs) const{
    if (frequency != rhs.frequency){
        return frequency < rhs.frequency;
    } else {
        return word < rhs.word;
    }
//    if (frequency < rhs.frequency){
//        return true;
//    } else if (frequency == rhs.frequency){
//        if (word < rhs.word) {
//            return true;
//        }
//    }
//    return false;
    
}

