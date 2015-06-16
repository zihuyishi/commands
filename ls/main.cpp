#include <string>
#include <iostream>
#include <pathCore/Path.h>

using namespace std;

int main(int argc, char **argv) {
    string filePath(argv[0]);
    Path path(filePath);
    cout << "Directory is : " << path.getDirectory() << endl;
    cout << "Filename is : " << path.getFilename() << endl;
    return 0;
}