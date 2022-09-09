#include "SourceBuffer.h"

#include <cassert>
#include <iostream>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

// Intialize source code buffer
SourceBuffer::SourceBuffer(char *filename) {
    // Open file as read only
    int file_descriptor = open(filename, O_RDONLY);
    assert(file_descriptor != -1 && "Something wrong when open the file");

    // Get file information using file descriptor
    struct stat stat_buffer = {};
    int file_info = fstat(file_descriptor, &stat_buffer);
    file_size = stat_buffer.st_size;

    // Print message if errno is EACCESS (File permission problem)
    if (errno == EACCES)
        std::cout << "Permission Denied! Please run this as sudo!\n";
    assert(file_info != -1 && "Something wrong when get file information");

    // Create memory mapping using syscall mmap(2)
    addr = mmap(nullptr, file_size, PROT_READ,MAP_PRIVATE | MAP_POPULATE,
               file_descriptor, 0);
    assert(addr != MAP_FAILED && "Something wrong when creating memory mapping");

    text = static_cast<char *>(addr);

    // It's safe to close the file_descriptor, based on mmap(2) documentation
    assert(close(file_descriptor) != -1 && "Something wrong when close the file");
}

// Delete memory mapping.
// Actually the memory mapping is automatically unmapped when the process is terminated
SourceBuffer::~SourceBuffer() {
    assert(munmap(addr, file_size) != -1 && "Something wrong when unmap memory mapping");
}