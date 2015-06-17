//
// Created by 李冲 on 15/6/17.
//

#ifndef LS_DIR_POSIXIMPL_H
#define LS_DIR_POSIXIMPL_H

#include "Dir.h"
#include <dirent.h>
#include <sys/param.h>
#include <unistd.h>

namespace cmd {
namespace sys {
class dir_posiximpl : public Dir {
    std::string     m_root;
    DIR*            m_dir;
public:
    dir_posiximpl(std::string filePath) :
        m_root(filePath), m_dir(nullptr)
    {
        m_dir = opendir(m_root.c_str());
    }
    virtual ~dir_posiximpl()
    {
        if (m_dir) {
            closedir(m_dir);
        }
    }
public:
    bool isValid() const {
        return m_dir != nullptr;
    }
public:
    //dir impl
    virtual auto getSubfiles() -> std::vector<std::string> {
        std::vector<std::string> files;
        dirent *file = nullptr;
        while ((file = readdir(m_dir)) != nullptr) {
            std::string filePath = file->d_name;
            files.push_back(filePath);
        }
        return files;
    }
};
std::string dir_posixGetCurrentPath();
}
}



#endif //LS_DIR_POSIXIMPL_H
