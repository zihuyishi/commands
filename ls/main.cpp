#include <string>
#include <pathCore/Path.h>
#include <pathCore/Dir.h>
#include <iostream>

using namespace std;
using namespace cmd;

int main(int, char **) {
    auto curPath = sys::dir_getCurrentPath();
    auto curDir = sys::dir_createWithPath(curPath);
    auto files = curDir->getSubfiles();
    std::string dirColor = "\x1b[33m";
    std::string fileColor = "\x1b[32m";
    std::string restore = "\x1b[0m";
    for (auto iter = files.begin(); iter != files.end(); iter++) {
        if (iter->isDirectory()) {
            std::cout << dirColor << iter->getFilename() << "\t";
        } else {
            std::cout << fileColor << iter->getFilename() << "\t";
        }
    }
    std::cout << restore;
    std::cout << std::endl;
    return 0;
}