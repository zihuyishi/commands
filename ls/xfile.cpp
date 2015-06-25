//
// Created by 李冲 on 15/6/25.
//
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <cstdlib>

void printUsage(const char *filename) {
    printf("%s filename [sXXX] [aXXX] [rXXX]\n", filename);
}
void printError(const char *errorInfo) {
    if (errorInfo != nullptr) {
        auto len = strlen(errorInfo);
        write(STDERR_FILENO, errorInfo, len);
    }
}
int main(int argc, char *argv[]) {
    if (argc == 1) {
        printUsage(argv[0]);
        return 0;
    }
    int fd;
    fd = open(argv[1], O_RDWR | O_CREAT,
              S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    if (fd == -1) {
        printError("Open file failed");
        return -1;
    }
    off_t offset;
    size_t len;
    char *buffer = nullptr;
    for (auto i = 2; i < argc; i++) {
        switch(argv[i][0]) {
            case 'a':
                lseek(fd, 0, SEEK_END);
            case 'w':
                len = strlen(argv[i] + 1);
                len = static_cast<size_t>(write(fd, argv[i] + 1, len));
                printf("write %ld data to file.\n", (long)len);
                break;
            case 's':
                offset = atol(argv[i] + 1);
                offset = lseek(fd, offset, SEEK_SET);
                printf("set offset to %lld.\n", (long long)offset);
                break;
            case 'r':
            case 'R':
                len = static_cast<size_t>(atol(argv[i] + 1));
                buffer = new char[len + 1];
                len = static_cast<size_t>(read(fd, buffer, len));
                if (argv[i][0] == 'r') {
                    printf("read %ld data, and data is :%s\n", len, buffer);
                } else {
                    printf("read %ld data, and data is :", len);
                    for (int j = 0; j < len; j++) {
                        printf("0x%.2x ", (uint8_t)buffer[j]);
                    }
                    printf("\n");
                }
                delete[] buffer;
                buffer = nullptr;
                break;
            default:
                break;
        }
    }
    auto result = close(fd);
    if (result == -1) {
        char buf[1024];
        sprintf(buf, "Close file failed with error %s", strerror(errno));
        printError(buf);
        return -1;
    }
    return 0;
}

