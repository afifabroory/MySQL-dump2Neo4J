#pragma once

#include <sys/stat.h>

class SourceBuffer {
    private:
        void *addr;
        off_t file_size;


    public:
        char *text = nullptr;

        SourceBuffer(char *filename);
        ~SourceBuffer();
};


