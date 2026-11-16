#include "parser.h"

http_method parser_method = NOT_DEFINED;
unsigned char parser_root = 0;
// unsigned char parser_functions = 0;
unsigned char parser_base = 0;
    
token current_tok = {0,NULL};

void baseexpr();
void rootexpr();
void methodexpr();
// void functionsexpr();
void fileexpr();
void direxpr();

char* current_root = NULL;

void setup_parser(FILE* file){
    setup_lexer(file);
    parser_method = 0;
    parser_root = 0;
    // parser_functions = 0;
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
        // case FUNCTIONS_TAG:
        //     functionsexpr();
        //     break;
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
    
    free_http_resource(base);

    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <base>",lexer_line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <base>",lexer_line);
    }
    
    base.path = current_tok.string;

    // free_tok(current_tok);
    
    parser_base = 1;
    
    current_tok = lex();

    if(current_tok.tag == ARROW_TAG){
        // if(!parser_functions){
        //     error_at_line("No <functions> was set for <base>",lexer_line);
        // }

        current_tok = lex();
        if(current_tok.tag != IDENTIFIER_TAG){
            error_at_line("Expected function name for <base>",lexer_line);
        }
        
        base.function_name = current_tok.string;

        // free_tok(current_tok);
        current_tok = lex();
    }
    
    parse();
}

void rootexpr(){

    if(current_root != NULL){
        free(current_root);
    }

    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){
        error_at_line("Expected <:> after <root>",lexer_line);
    }

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){
        error_at_line("Expected path for <root>",lexer_line);
    }

    current_root = current_tok.string;

    //free_tok(current_tok);
    
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
        case GET_TAG:
            parser_method = GET;
            break;
        case POST_TAG:
            parser_method = POST;
            break;
        case DELETE_TAG:
            parser_method = DELETE;
            break;
        case PUT_TAG:
            parser_method = PUT;
            break;
        case PATCH_TAG:
            parser_method = PATCH;
            break;
        default:
            error_at_line_tok("Not a valid method (GET,POST,DELETE,PUT,PATCH)",lexer_line,current_tok);
            break;
    }

    current_tok = lex();
    parse();
}

// void functionsexpr(){
//     current_tok = lex();
// 
//     if(current_tok.tag != SEMICOLON_TAG){
//         error_at_line("Expected <:> after <functions>",lexer_line);
//     }
// 
//     current_tok = lex();
// 
//     if(current_tok.tag != IDENTIFIER_TAG){
//         error_at_line("Expected path for <functions>",lexer_line);
//     }
// 
//     free_tok(current_tok);
//     
//     parser_functions = 1;
// 
//     current_tok = lex();
//     parse();
// }

static void insert_resource(http_resource resource){
    switch(parser_method){
        case GET:
            if(!contains_http_resouce(get_resources,resource)){
                append_al(get_resources,resource); 
            }
            else{
                error_at_line_resource("Duplicated resource",lexer_line,resource);
            }
            break;
        case POST:
            if(!contains_http_resouce(post_resources,resource)){
                append_al(post_resources,resource); 
            }
            else{
                error_at_line_resource("Duplicated resource",lexer_line,resource);
            }
            break;
        case DELETE:
            if(!contains_http_resouce(delete_resources,resource)){
                append_al(delete_resources,resource); 
            }
            else{
                error_at_line_resource("Duplicated resource",lexer_line,resource);
            }
            break;
        case PUT:
            if(!contains_http_resouce(put_resources,resource)){
                append_al(put_resources,resource); 
            }
            else{
                error_at_line_resource("Duplicated resource",lexer_line,resource);
            }
            break;
        case PATCH:
            if(!contains_http_resouce(patch_resources,resource)){
                append_al(patch_resources,resource); 
            }
            else{
                error_at_line_resource("Duplicated resource",lexer_line,resource);
            }
            break;
        default:
            error_at_line("Invalid method (GET,POST,DELETE,PUT,PATCH) while parsing (Parser failure)",lexer_line);
            break;
    }
}

void fileexpr(){

    http_resource file_resource = {0};

    if(!parser_root){error_at_line("No <root> was set for <file>",lexer_line);}
    if(parser_method == NOT_DEFINED){error_at_line("No <method> was set for <file>",lexer_line);}

    current_tok = lex();

    if(current_tok.tag != SEMICOLON_TAG){error_at_line("Expected <:> after <file>",lexer_line);}

    current_tok = lex();

    if(current_tok.tag != IDENTIFIER_TAG){error_at_line("Expected path for <file>",lexer_line);}
    
    file_resource.path = current_tok.string;

    current_tok = lex();
    if(current_tok.tag == ARROW_TAG){
        current_tok = lex();
        if(current_tok.tag != IDENTIFIER_TAG){error_at_line("Expected function name for <file>",lexer_line);}
        
        file_resource.function_name = current_tok.string;
        
        current_tok = lex();
    }
        
    insert_resource(file_resource);
   
    parse();
}

// TODO: exapand dirs into files before translating ?? or I can leave it to the server to handle ??
void direxpr(){
    
    http_resource dir_resource = {0};
    dir_resource.dir = 1;
    
    if(!parser_root){error_at_line("No <root> was set for <dir>",lexer_line);}
    if(parser_method == NOT_DEFINED){error_at_line("No <method> was set for <dir>",lexer_line);}
    current_tok = lex();
    if(current_tok.tag != SEMICOLON_TAG){error_at_line("Expected <:> after <dir>",lexer_line);}
    current_tok = lex();
    if(current_tok.tag != IDENTIFIER_TAG){error_at_line("Expected path for <dir>",lexer_line);}
    
    dir_resource.path = current_tok.string;
    
    current_tok = lex();
    if(current_tok.tag == ARROW_TAG){
        current_tok = lex();
        if(current_tok.tag != IDENTIFIER_TAG){error_at_line("Expected function name for <dir>",lexer_line);}
        
        dir_resource.function_name = current_tok.string;
        current_tok = lex();
    }

    insert_resource(dir_resource);

    parse();
}
