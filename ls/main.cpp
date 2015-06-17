#include <string>
#include <pathCore/Path.h>
#include <unistd.h>
#include <dirent.h>
#include <vector>
#include <iostream>
#include <sys/param.h>

using namespace std;

int main(int argc, char **argv) {
    char *filePath = new char[MAXPATHLEN];
    getcwd(filePath, MAXPATHLEN);
    Path path(filePath);
    delete[] filePath;
    DIR *root = opendir(path.getDirectory().c_str());

    std::vector<Path> files;
    dirent *file = NULL;
    while ((file = readdir(root)) != NULL) {
        Path childPath = Path(file->d_name);
        files.push_back(childPath);
    }
    closedir(root);

    for (auto iter = files.begin(); iter != files.end(); iter++) {
        std::cout << iter->getFilename() << "\t";
    }
    std::cout << std::endl;
    return 0;
}