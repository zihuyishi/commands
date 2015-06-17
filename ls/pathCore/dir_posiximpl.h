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
        if (m_root[m_root.length()-1] == '/') {
            m_root = m_root.substr(0, m_root.length()-1);
        }
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
    virtual auto getSubfiles() -> std::vector<Path> {
        std::vector<Path> files;
        dirent *file = nullptr;
        while ((file = readdir(m_dir)) != nullptr) {
            bool isDir = file->d_type == DT_DIR;
            std::string fullPath = m_root + "/" + file->d_name;
            Path filePath(fullPath, isDir);
            files.push_back(filePath);
        }
        return files;
    }
};
std::string dir_posixGetCurrentPath();
}
}



#endif //LS_DIR_POSIXIMPL_H
