//
// Created by 李冲 on 15/6/17.
//

#include "Dir.h"
#ifndef WIN32
#include "dir_posiximpl.h"
#else
#include "dir_winimpl.h"
#endif

namespace cmd {
namespace sys {
    Dir * dir_createWithPath(std::string filePath) {
#ifndef WIN32
        auto retPtr = new dir_posiximpl(filePath);
#else
		auto retPtr = new dir_winimpl(filePath);
#endif
		return retPtr;
    }
    std::string dir_getCurrentPath() {
#ifndef WIN32
        return dir_posixGetCurrentPath();
#else
		return dir_winGetCurrentPath();
#endif
    }
}
}
