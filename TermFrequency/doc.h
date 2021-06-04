#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>
#include <utility>
#include "word.h"

class Document
{
private:
    std::vector<Word>* words = new std::vector<Word>();
    std::vector<std::pair<std::string, int>> sortVector;
    int wordCount = 0;
public:
    Document();
    void loadDocument (std::ifstream* wordDoc);
    void normalize(std::vector<std::string>* stopWords);
    void termFrequency();
    void removeDuplicates();
    void sortWords();
    std::string removePunct(std::string word);
    void print(const std::string outFile);
    int getWordCount();
//    bool operator() (const Word& left, const Word& right) const {
//            if (left.getFrequency() != right.getFrequency() {
//                return left.frequency > right.frequency;
//            } else {
//                return left.word < right.word;
//            }
//        }
};


#endif // DOCUMENT_H
