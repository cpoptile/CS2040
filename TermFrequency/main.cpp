#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <doc.h>

using namespace std;

void loadStopWords(const string& stopFile, vector<string>* stopWords);

int main(int argc, char **argv)
{
    Document doc;
    vector<string>* stopWords = new std::vector<string>();
    
    cout << "Please enter a text file to read from: " << endl;
    string fileName;
    cin >> fileName;
    ifstream wordDoc;
    wordDoc.open(fileName);
    //check if file valid
    if(!wordDoc.good()){
        cout << "Cannot read file" << endl;
    }
    doc.loadDocument(&wordDoc);
    
    cout << "Please enter a file name containing stop words" << endl;
    string stopFile;
    cin >> stopFile;
    loadStopWords(stopFile, stopWords);
    doc.normalize(stopWords);
    
    cout << "Please enter a file to write the results to" << endl;
    string outFile;
    cin >> outFile;
//    doc.removeDuplicates();
    doc.print(outFile);
	return 0;
}

void loadStopWords(const string& stopFile, vector<string>* stopWords){
    ifstream textFile;
    textFile.open(stopFile);
    if(!textFile.good()){
        cout << "Cannot read file" << endl;
    }
    string word;
    textFile >> word;
    while (textFile) {
        stopWords -> push_back(word);
        textFile >> word;
    }
    
}
