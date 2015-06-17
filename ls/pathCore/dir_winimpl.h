//
// Created by saye on 2015/6/17.
//

#ifndef LS_DIR_WINIMPL_H
#define LS_DIR_WINIMPL_H
#include "Dir.h"
#include <Windows.h>
#pragma comment(lib, "User32.lib")

namespace cmd {
namespace sys {
	class dir_winimpl : public Dir {
		std::string		m_root;
	public:
		dir_winimpl(std::string filePath) :
			m_root(filePath)
		{
			
		}
		virtual ~dir_winimpl() {

		}
	public:
		//Dir methods
		virtual auto getSubfiles() -> std::vector<Path> {
			std::vector<Path> files;
			HANDLE hFind = INVALID_HANDLE_VALUE;
			WIN32_FIND_DATA ffd;
			hFind = FindFirstFileA(m_root.c_str(), &ffd);
			if (INVALID_HANDLE_VALUE != hFind) {
				do {
					bool isDir = (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
					Path path(ffd.cFileName, isDir);
					files.push_back(path);
				} while (FindNextFileA(hFind, &ffd) != 0);
				FindClose(hFind);
			}
			return files;
		}
	};
	std::string dir_winGetCurrentPath() {
		char szPath[MAX_PATH];
		if (GetModuleFileNameA(NULL, szPath, MAX_PATH)) {
			return std::string(szPath);
		}
		else {
			throw std::string("get current path failed");
		}
	}
}
}



#endif //LS_DIR_WINIMPL_H
