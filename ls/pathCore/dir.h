//
// Created by 李冲 on 15/6/17.
//

#ifndef LS_DIR_H
#define LS_DIR_H
#include <string>
#include <vector>
#include "Path.h"

namespace cmd {
namespace sys {


class Dir {
public:
    virtual ~Dir() {}
public:
    virtual auto getSubfiles() -> std::vector<Path> = 0;
};

Dir * dir_createWithPath(std::string filePath);
std::string dir_getCurrentPath();
} //namespace sys
} //namespace cmd

#endif //LS_DIR_H
