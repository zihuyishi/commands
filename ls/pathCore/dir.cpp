//
// Created by 李冲 on 15/6/17.
//

#include "Dir.h"
#include "dir_posiximpl.h"

namespace cmd {
namespace sys {
    Dir * dir_createWithPath(std::string filePath) {
        auto retPtr = new dir_posiximpl(filePath);
        return retPtr;
    }
    std::string dir_getCurrentPath() {
        return dir_posixGetCurrentPath();
    }
}
}
