#include "Tokenizer.h"
#include <sstream>


std::vector<std::string> Tokenizer::Parse(std::string line){
    for (char &Chr : line){
        if (!isdigit(Chr) && Chr != '.')
            Chr = ' ';
    }
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;
    while (ss >> token)
        tokens.push_back(token);
    return tokens;
}