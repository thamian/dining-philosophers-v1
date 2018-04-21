#include "file.h"

File::File(std::string pathname)
{
    ifstream_.open(pathname);
}

File::~File()
{
    ifstream_.close();
}

std::vector<std::string> File::content()
{
    std::vector<std::string> fileContent;
    std::string line;
    while (std::getline(ifstream_, line))
    {
        fileContent.push_back(line);
    }
    ifstream_.clear();
    ifstream_.seekg(0);
    return fileContent;
}
