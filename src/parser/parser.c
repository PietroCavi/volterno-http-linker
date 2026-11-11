#include "parser.h"

void setup_parser(FILE* file){
    setup_lexer(file);
}

void parse(){
    token t = {0,"ciao"};

    while(t.tag != EOF_TAG){
        t = lex();

        print_tok(t);

        if(t.tag == IDENTIFIER_TAG){
            free_tok(t);
        }
    }
}
