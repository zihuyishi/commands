//
// Created by 李冲 on 15/6/17.
//

#include "dir_posiximpl.h"
namespace cmd {
namespace sys {
    std::string dir_posixGetCurrentPath() {
        char *filePath = new char[MAXPATHLEN];
        getcwd(filePath, MAXPATHLEN);
        std::string curPath = filePath;
        delete[] filePath;
        return curPath;
    }
}
}
