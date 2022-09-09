#include "source/SourceBuffer.h"
#include "lexer/Lexer.h"

#include <iostream>

int main() {
    SourceBuffer src((char *) "test");

    Lexer lex(src);
    lex.next();

    std::cout << "Found EOF!" << std::endl;
    std::cout << "Last character: " << *src.text << std::endl;
}