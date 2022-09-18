#pragma  once

#include "../source/SourceBuffer.h"

// TokenType and Lexeme pair
enum TokenType {
    // https://dev.mysql.com/doc/refman/8.0/en/identifiers.html
    TOKEN_IDENTIFIER,   // `*[0-9A-Za-z_$]+`*

    // Keyword
    TOKEN_CREATE,
    TOKEN_TABLE,

    // Literal
    TOKEN_STRING,
    TOKEN_INT,

    // Separator
    TOKEN_LPAREN,               // (
    TOKEN_RPAREN,               // )
    TOKEN_SEMICOLON,            // ,
    TOKEN_BACKTICK,             // `

    // Comment
    TOKEN_SINGLE_COMMENT,      // [//]
    TOKEN_LMULTI_COMMENT,      // /*
    TOKEN_RMULTI_COMMENT,      // */

    // Special
    TOKEN_EOF
};

struct Token {
    // https://en.wikipedia.org/wiki/Lexical_analysis#Token
    TokenType type;
    union {
        char *identifier;
    }  lexeme;
};

class Lexer {
    private:
        char *text = nullptr;

        bool isEOF(char &c);
        bool isWhitespace(char &c);
        bool isIdentifier(char &c);

        void skipWhitespace();

    public:
        Lexer(SourceBuffer &src);

        // Get next token
        Token *next();
};