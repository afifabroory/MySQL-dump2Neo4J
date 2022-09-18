#include "source/SourceBuffer.h"
#include "lexer/Lexer.h"

#include <iostream>

int main() {
    SourceBuffer src((char *) "test");

    Lexer lex(src);

    Token *tok;
    do {
        tok = lex.next();
        if (tok->type == TOKEN_IDENTIFIER) {
            std::cout << "Type: " << tok->type << "; Value: " << tok->lexeme.identifier << std::endl;
            free(tok->lexeme.identifier);
            free(tok);
        }
    } while(tok->type != TOKEN_EOF);
}