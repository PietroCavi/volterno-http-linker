#include "parser.h"

unsigned char method = 0;
unsigned char root = 0;
unsigned char functions = 0;
unsigned char base = 0;
    
token current_tok = {0,NULL};

void baseexpr();
void rootexpr();
void methodexpr();
void functionsexpr();
void fileexpr();
void direxpr();

void parse(){
    
    if(current_tok.string == NULL){ 
        current_tok = lex();
    }

    switch(current_tok.tag){
        case BASE_TAG:
            baseexpr();
            break;
        case ROOT_TAG: 
            rootexpr();
            break;
        case METHOD_TAG:
            methodexpr();
            break;
        case FUNCTIONS_TAG:
            functionsexpr();
            break;
        case FILE_TAG:
            fileexpr();
            break;
        case DIR_TAG:
            direxpr();
            break;
        case COMMENT_TAG:
            current_tok = lex();
            parse();
            break;
        case EOF_TAG:
            current_tok = (token){0,NULL};
            break;
        default:
            error_at_line_tok("Unexpected token",line,current_tok);
            break;
    }
}

void baseexpr(){
    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <base>",line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <base>",line);
    }

    free_tok(current_tok);
    
    base = 1;
    
    current_tok = lex();
    parse();
}

void rootexpr(){
    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <root>",line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <root>",line);
    }

    free_tok(current_tok);
    
    root = 1;
    
    current_tok = lex();
    parse();
}

void methodexpr(){
    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <method>",line);
    }

    current_tok = lex();
    
    switch(current_tok.tag){
        case GET_TAG: break;
        case POST_TAG: break;
        case DELETE_TAG: break;
        case PUT_TAG: break;
        case PATCH_TAG: break;
        default:
            error_at_line_tok("Not a valid method (GET,POST,DELETE,PUT,PATCH)",line,current_tok);
            break;
    }

    method = 1;

    current_tok = lex();
    parse();
}

void functionsexpr(){
    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <functions>",line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <functions>",line);
    }

    free_tok(current_tok);
    
    functions = 1;

    current_tok = lex();
    parse();
}

void fileexpr(){
    
    if(!root){
        error_at_line("No <root> was set for <file>",line);
    }

    if(!method){
        error_at_line("No <method> was set for <file>",line);
    }

    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <file>",line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <file>",line);
    }
    
    free_tok(current_tok);
    
    current_tok = lex();

    if(current_tok.tag == ARROW_TAG){
        if(!functions){
            error_at_line("No <functions> was set for <file>",line);
        }

        current_tok = lex();
        if(current_tok.tag != IDENTIFIER_TAG){
            error_at_line("Expected function name for <file>",line);
        }

        free_tok(current_tok);
        current_tok = lex();
    }

    parse();

}

void direxpr(){
    if(!root){
        error_at_line("No <root> was set for <dir>",line);
    }

    if(!method){
        error_at_line("No <method> was set for <dir>",line);
    }

    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <dir>",line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <dir>",line);
    }
    
    free_tok(current_tok);
    
    current_tok = lex();

    if(current_tok.tag == ARROW_TAG){
        if(!functions){
            error_at_line("No <functions> was set for <dir>",line);
        }

        current_tok = lex();
        if(current_tok.tag != IDENTIFIER_TAG){
            error_at_line("Expected function name for <dir>",line);
        }

        free_tok(current_tok);
        current_tok = lex();
    }

    parse();
}
