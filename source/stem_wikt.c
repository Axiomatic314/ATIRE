#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <string.h>
#include "stem_wikt.h"

ANT_stem_wikt::ANT_stem_wikt(){
    std::string wordToStemFilePath = "wordToStem.txt";
    std::fstream wordToStemFile(wordToStemFilePath, std::fstream::in);
    if(!wordToStemFile.is_open()){
        fprintf(stderr, "Error opening file!\nNo stemming will be applied.\n");
    }else{
        std::string line, word, stem;
        while(getline(wordToStemFile, line)){
            std::string delim = " -> ";
            std::vector<std::string> lineSegments;
            word = line.substr(0, line.find(delim));
            stem = line.substr(line.find(delim) + delim.length(), line.length() - delim.length() - word.length());
            lookup_table[word] = stem;
        }
    }
}

size_t ANT_stem_wikt::stem(const char *what, char *destination){
    auto search = lookup_table.find(what);
    if(search == lookup_table.end()){
        strcpy(destination, what);
    }else{
        strcpy(destination, search->second.c_str());
    }
    return 3;
}
