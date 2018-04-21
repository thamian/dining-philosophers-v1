#ifndef FILE_H
#define FILE_H


#include <fstream>
#include <string>
#include <vector>

class File
{
public:
    File(std::string pathname);
    ~File();
    std::vector<std::string> content();

private:
    std::ifstream ifstream_;
};

#endif // FILE_H
