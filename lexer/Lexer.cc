#include "Lexer.h"

#include <iostream>
#include <cstring>
#include <cassert>

// Public method
Lexer::Lexer(SourceBuffer &src): text {src.text} {}

Token *Lexer::next() {
    // Skip whitespace
    skipWhitespace();

    Token *t = (Token *) malloc(sizeof(Token));

    // Find recognized token while not EOF and whitespace
    while (!isEOF(*text)) {

        if (isIdentifier(*text)) {
            // If first character is start with _ or alphabet then
            // read next character.

            // Hold first position of recognizable identifier
            void *firstPos = text;
            // Declare counter variable to keep track identifier length (min. 1)
            uint16_t size = 1;

            // Read character until isn't a recognizable identifier character stream
            while (isIdentifier(*text++)) size++;
            text--; // Decrement for next token

            // Store and return token pair
            t->type = TOKEN_IDENTIFIER;

            t->lexeme.identifier = (char *) malloc(size);
            memcpy(t->lexeme.identifier, firstPos, size-1);
            t->lexeme.identifier[size] = '\0';

            return t;
        }
        text++;
    }

    // It should be EOF...
    assert(isEOF(*text));
    t->type = TOKEN_EOF;
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
    while (isWhitespace(*text)) text++;
}