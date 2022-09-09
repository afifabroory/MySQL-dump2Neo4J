# Lexer Documentation
- Lexer Class
    - Public member and method
        - `Lexer(char *)` constructor

            Initialize the code to be performing lexical analysis.

        - `nextToken(void)` method

            Get next recognized token and ignore anything that isn't part of the lexical analysis specification.

    - Private member and method
        - `char *_code` member

            Private member to store array of character.
