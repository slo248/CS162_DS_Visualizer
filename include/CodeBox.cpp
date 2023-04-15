#include "CodeBox.h"

void CodeBox::loadFromFile(std::string path)
{
    std::ifstream fin(path);
    if(!fin.is_open()){
        std::cout << "Error: code file not found" << std::endl;
        return;
    }
    std::string line;
    while(std::getline(fin, line)) code.push_back(line);
    fin.close();
}
