//
// Created by 李冲 on 15/6/16.
//

#include "Path.h"

void Path::setPath(std::string path) {
    m_path = path;
}

std::string Path::getPath() const {
    return m_path;
}

std::string Path::getDirectory() const {
    auto lastSeparatePos = findLastSeparate();
    if (lastSeparatePos != std::string::npos) {
        m_path.substr(0, lastSeparatePos);
    } else {
        return "";
    }
}

//private
size_t Path::findLastSeparate() const {
    return m_path.rfind('/');
}
