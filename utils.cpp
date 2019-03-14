#include <string> 
#include <vector> 
#include "utils.h"

std::string getARandomWord(std::vector<std::string>& listWord) {
    int id = rand() % listWord.size() ;
    return listWord[id] ;
}