#include "parser.h"

unsigned char parser_method = 0;
unsigned char parser_root = 0;
unsigned char parser_functions = 0;
unsigned char parser_base = 0;
    
token current_tok = {0,NULL};

void baseexpr();
void rootexpr();
void methodexpr();
void functionsexpr();
void fileexpr();
void direxpr();

void setup_parser(FILE* file){
    setup_lexer(file);
    parser_method = 0;
    parser_root = 0;
    parser_functions = 0;
    parser_base = 0;
}

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
            error_at_line_tok("Unexpected token",lexer_line,current_tok);
            break;
    }
}

void baseexpr(){
    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <base>",lexer_line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <base>",lexer_line);
    }

    free_tok(current_tok);
    
    parser_base = 1;
    
    current_tok = lex();
    parse();
}

void rootexpr(){
    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <root>",lexer_line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <root>",lexer_line);
    }

    free_tok(current_tok);
    
    parser_root = 1;
    
    current_tok = lex();
    parse();
}

void methodexpr(){
    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <method>",lexer_line);
    }

    current_tok = lex();
    
    switch(current_tok.tag){
        case GET_TAG: break;
        case POST_TAG: break;
        case DELETE_TAG: break;
        case PUT_TAG: break;
        case PATCH_TAG: break;
        default:
            error_at_line_tok("Not a valid method (GET,POST,DELETE,PUT,PATCH)",lexer_line,current_tok);
            break;
    }

    parser_method = 1;

    current_tok = lex();
    parse();
}

void functionsexpr(){
    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <functions>",lexer_line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <functions>",lexer_line);
    }

    free_tok(current_tok);
    
    parser_functions = 1;

    current_tok = lex();
    parse();
}

void fileexpr(){
    
    if(!parser_root){
        error_at_line("No <root> was set for <file>",lexer_line);
    }

    if(!parser_method){
        error_at_line("No <method> was set for <file>",lexer_line);
    }

    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <file>",lexer_line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <file>",lexer_line);
    }
    
    free_tok(current_tok);
    
    current_tok = lex();

    if(current_tok.tag == ARROW_TAG){
        if(!parser_functions){
            error_at_line("No <functions> was set for <file>",lexer_line);
        }

        current_tok = lex();
        if(current_tok.tag != IDENTIFIER_TAG){
            error_at_line("Expected function name for <file>",lexer_line);
        }

        free_tok(current_tok);
        current_tok = lex();
    }

    parse();

}

void direxpr(){
    if(!parser_root){
        error_at_line("No <root> was set for <dir>",lexer_line);
    }

    if(!parser_method){
        error_at_line("No <method> was set for <dir>",lexer_line);
    }

    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <dir>",lexer_line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <dir>",lexer_line);
    }
    
    free_tok(current_tok);
    
    current_tok = lex();

    if(current_tok.tag == ARROW_TAG){
        if(!parser_functions){
            error_at_line("No <functions> was set for <dir>",lexer_line);
        }

        current_tok = lex();
        if(current_tok.tag != IDENTIFIER_TAG){
            error_at_line("Expected function name for <dir>",lexer_line);
        }

        free_tok(current_tok);
        current_tok = lex();
    }

    parse();
}
