#include <string>
#include <pathCore/Path.h>
#include <pathCore/Dir.h>
#include <iostream>

using namespace std;
using namespace cmd;

int main(int argc, char **argv) {
    auto curPath = sys::dir_getCurrentPath();
    auto curDir = sys::dir_createWithPath(curPath);
    vector<string> files = curDir->getSubfiles();
    for (auto iter = files.begin(); iter != files.end(); iter++) {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;
    return 0;
}