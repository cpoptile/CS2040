#ifndef WORD_H
#define WORD_H

#include <string> 

class Word
{
private:
    std::string word;
    double frequency;
public:
    Word(std::string w);
    std::string getWord();
    double getFrequency();
    void setFrequency(int frequency);
    bool operator == (const Word& rhs) const;
    bool operator > (const Word& rhs) const;
    bool operator < (const Word& rhs) const;
//    bool operator () (const Word& left, const Word& right) {
//        if (left.getFrequency() != right.getFrequency() {
//            return left.frequency > right.frequency;
//        } else {
//            return left.word < right.word;
//        }
//    }

};

#endif // WORD_H
