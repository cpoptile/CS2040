#include "doc.h"
#include <string>
#include "word.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;


/**
 * @brief constructor with no purpose
 * @return document
 */
Document::Document(){
    
}

/**
 * @brief read in a text file and store each word
 * as a Word in a vector
 * @param inFile filename to be read from
 */
void Document::loadDocument(ifstream* wordDoc){
    std::string wordString = "";
    *wordDoc >> wordString;
    //while filereader has next word
    while (*wordDoc){
        string worddd = "";
        // remove punctuation
        worddd = removePunct(wordString);
        // make lowercase
        transform(worddd.begin(), worddd.end(), worddd.begin(), ::tolower);
        //create word object
        Word validWord = Word(worddd);
        //add to vector
        words -> push_back(validWord);
        wordCount++;
        //move on to next word
        *wordDoc >> wordString;
    }
    
}

/**
 * @brief removes punctuation from a word
 * @param word word string to be analyzed
 * @return word string punctuation removed
 */
string Document::removePunct(string word){
    for(int i = 0, len = word.size(); i < len; i++) {
        if(ispunct(word[i])) {
            word.erase(i--, 1);
            len = word.size();
        }
    }
    return word;
}


/**
 * @brief Method removes stop words from words vector
 * @param stopWords vector of stopwords to be erased
 */
void Document:: normalize(vector<string>* stopWords){
    vector<Word>::iterator it;
    vector<string>::iterator stopIt;
    
    //clean up stopWords
    for (stopIt = stopWords->begin(); stopIt != stopWords->end(); stopIt++){
        string stopWord = *stopIt;
        transform(stopWord.begin(), stopWord.end(), stopWord.begin(), ::tolower);
        stopWord = removePunct(stopWord);
    }
    
    for (int i = words -> size()-1;i>= 0; i--){
        Word wordWord = words -> at(i);
        string wordString = wordWord.getWord();
        if (std::find(stopWords->begin(), stopWords->end(), wordString) != stopWords->end()){
            words->erase(words -> begin() + i);
            wordCount--;
        }
    }
    
    //loop through each word in words
//    for (it = words->begin(); it != words->end();){
//        Word wordWord = *it;
//        string wordString = wordWord.getWord();
//        // if word is found in stopwords, erase from words
////        if (std::find(stopWords->begin(), stopWords->end(), wordString) != stopWords->end()){
////            words->erase(it);
////            wordCount--;
////            cout << "ERASED " << wordString << endl;
////        }
//        for (stopIt = stopWords->begin(); stopIt != stopWords->end(); stopIt++){
//            string stopWord = *stopIt;
//            Word stopp = Word(stopWord);
////            it = remove(words -> begin(), words -> end(), stopp);
//
//            if (stopWord == wordString){
//                words -> erase(it);
//                wordCount--;
//                cout << "ERASED " << stopWord << endl;
//            } else {
//                it++;
//            }
//        }
//    }

    
    removeDuplicates();

}


void Document:: termFrequency(){
}


void Document::removeDuplicates(){
    vector<Word>::iterator it;
    set<Word> wordSet;
    vector<Word>* copyW = new std::vector<Word>();

    sort(words->begin(), words->end());
    
    int count = 1;
    for (it = words->begin(); it < words->end(); ++it){
            Word yeah = *it;
            if (!wordSet.count(yeah)){
                count = 1;
                wordSet.insert(yeah);
                if ((it+1) != words->end() && !wordSet.count(*(it+1))){
                    copyW->push_back(yeah);
                } else if ((it+1) == words -> end()){
                    copyW-> push_back(yeah);

                }
            } else {
                count++;
                yeah.setFrequency(count);
                wordSet.insert(yeah);
                if ((it+1) != words->end() && !wordSet.count(*(it+1))){
                    copyW->push_back(yeah);
                } else if (it == words -> end()){
                    copyW-> push_back(yeah);
                }
            }
    }
    
    words->erase(words->begin(), words->end());
    
    //replace words with the set
    vector<Word>::iterator itt;
    for(itt = copyW ->begin(); itt != copyW->end(); itt++){
        Word copy = *itt;
        words->push_back(copy);
    }
    
//    words = &wordSet;
//    words->begin() = wordSet->begin();
//    vector<Word>* erased(wordSet->begin(), wordSet->end());
//    words = erased;
//    set<Word>::iterator setIt;
//    for (setIt = wordSet->begin(); setIt != wordSet->end(); setIt++){
//        Word yup = *setIt;
//        words->push_back(yup);
//        
//    }
    
//    cout << "erase" << endl;
////    words->erase(unique (words -> begin(), words->end()), words->end());
//    cout << "ERASED" << endl;
//    for (it = words->begin(); it != words->end(); it++){
//        Word yeah = *it;
//
////        for (setIt = wordSet.begin(); setIt != wordSet.end(); setIt++){
////            Word unique = *setIt;
////            if (unique.getWord() == yeah.getWord()){
////                cout << "YEAH"<< endl;
////                yeah.setFrequency(unique.getFrequency());
////                break;
////            }
////            
////        }
//        
//        cout << yeah.getWord() + "AFTER FREQ " << yeah.getFrequency() << endl;
//        
//    }
}


void Document:: sortWords(){
    sortVector = {};
    vector<Word>::iterator it;
    for (it = words->begin(); it != words->end(); it++){
        Word wordWord = *it;
        string wordString = wordWord.getWord();
        sortVector.push_back({wordWord.getWord(), wordWord.getFrequency()});
    }
    std::sort(sortVector.begin(), sortVector.end(),
            [](const std::pair<string, int>& p1, const std::pair<string, int>& p2) {
                return p1.second > p2.second;
            });

    words->erase(words->begin(), words->end());
    // print the values out
    for (const auto& pa : sortVector) {
        Word newWord = Word(pa.first);
        newWord.setFrequency(pa.second);
        words->push_back(newWord);
    }
    
}


/**
 * @brief Method writes each word and frequency to an outfile
 * @param outFile filename to be written to
 */
void Document::print(const string outFile){
    sortWords();
    ofstream file(outFile);
    vector<Word>::iterator it;
//    vector<pair<string, int>>::iterator it;
    file << "The term frequencies are: \n";
//    for (it = sortVector.begin(); it != sortVector.end(); it++){
//        string word = *it.first;
//        int freq = *it.second();
//        
//        string frequency = to_string(int/getWordCount());
//        file << wordString + ": " + frequency + "\n" ;
//    }
    for (it = words->begin(); it != words->end(); it++){
        Word wordWord = *it;
        string wordString = wordWord.getWord();
        
        string frequency = to_string(wordWord.getFrequency()/getWordCount());
        file << wordString + ": " + frequency + "\n" ;
    }
    file.close();
}

/**
 * @brief Method returns the word count
 * @return word count
 */
int Document:: getWordCount(){
    return wordCount;
}

