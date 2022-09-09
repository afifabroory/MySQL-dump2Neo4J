#include "Lexer.h"

#include <iostream>

// Public method
Lexer::Lexer(SourceBuffer &src): text {src.text} {}

Token Lexer::next() {
    // Skip whitespace
    skipWhitespace();

    Token t;

    // Find recognized token while not EOF and whitespace
    while (!isEOF(*text) && !isWhitespace(*text)) {

        if (isIdentifier(*text)) {

        }
        text++;
    }
}

// Private method
bool Lexer::isEOF(char &c) {
    return c == '\0';
}

bool Lexer::isWhitespace(char &c) {
    // https://en.wikipedia.org/wiki/Whitespace_character
    switch (c) {
        case '\t':  // Character tabulation
        case '\n':  // Line feed
        case '\v':  // Line tabulation
        case '\f':  // Form feed
        case '\r':  // Carriage return
        case ' ' :  // Space
            return true;
        default:
            return false;
    }
}

bool Lexer::isIdentifier(char &c) {
    switch(c) {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            return true;
        default:
            return false;
    }
}

void Lexer::skipWhitespace() {
    while (isWhitespace(*text++));
}