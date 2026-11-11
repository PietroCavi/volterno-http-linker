#include "lexer.h"

char peek;
long long unsigned line;
FILE* br;

int setup_lexer(FILE*file){
    return file == NULL ? 0 : 1;
}

token lex(){
    return eof_tok;    
}

