//
// Created by 李冲 on 15/6/16.
//

#include "Path.h"
namespace cmd {
namespace sys {
    void Path::setPath(std::string path) {
        m_path = path;
        detectSeparateChar();
    }

    std::string Path::getPath() const {
        return m_path;
    }

    std::string Path::getDirectory() const {
        auto lastSeparatePos = findLastSeparate();
        if (lastSeparatePos != std::string::npos) {
            return m_path.substr(0, lastSeparatePos);
        } else {
            return m_path;
        }
    }

    std::string Path::getFilename() const {
        auto lastSeparatePos = findLastSeparate();
        if (lastSeparatePos != std::string::npos && lastSeparatePos + 1 < m_path.length()) {
            return m_path.substr(lastSeparatePos + 1);
        } else {
            return m_path;
        }
    }

    //private
    size_t Path::findLastSeparate() const {
        return m_path.rfind(m_separate);
    }

    void Path::detectSeparateChar() {
        if (m_path.find('/') != std::string::npos) {
            m_separate = '/';
        } else {
            m_separate = '\\';
        }
    }
}
}
