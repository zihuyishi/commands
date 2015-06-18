//
// Created by 李冲 on 15/6/16.
//

#ifndef LS_PATH_H
#define LS_PATH_H

#include <string>

namespace cmd {
namespace sys {
class Path {
    std::string     m_path;
    bool            m_isDir;
public:
    Path() { }

    Path(std::string path, bool isDirectory) :
            m_path(path), m_isDir(isDirectory)
    { }

    ~Path() { }

    Path(const Path &path) {
        m_path = path.m_path;
    }

public:
    //setter && getter
    void setPath(std::string path);

    std::string getPath() const;

    Path &operator=(const Path &path) {
        m_path = path.m_path;
        return *this;
    }

    bool operator==(const Path &path) const {
        return m_path == path.m_path;
    }

public:
    //component methods

    std::string getDirectory() const;

    std::string getFilename() const;

    bool isDirectory() const {
        return m_isDir;
    }

private:
    /**
* 寻找最后一个路径分隔符位置
* @return 找到返回位置；没找到返回std::string::npos
*/
    size_t findLastSeparate() const;
};

}
}
#endif //LS_PATH_H
