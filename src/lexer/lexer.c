#include "lexer.h"

#define NEXT (char)fgetc(br)
#define streq(A,B) (strcmp(A,B) == 0)

long long unsigned lexer_line;

char peek;
FILE* br = NULL;

void setup_lexer(FILE*file){
    if(file == NULL){
        generic_error("Parser failed to setup, the passed file was NULL");
    }

    br = file;
    peek = NEXT;
    lexer_line = 1;
}

token lex(){
    
    if(br == NULL){
        generic_error("Parser was not setupped correctly");
    }

	while(peek == ' ' || peek == '\t' || peek == '\r' || peek == '\n'){
		if(peek == '\n'){
            lexer_line++;
        }
        peek = NEXT;
	}

    switch(peek){
        case '-':
            peek = NEXT;
            if(peek != '>'){
                error_at_line("Missing '>' to complete the arrow",lexer_line);
            }
            peek = NEXT;
            return arrow_tok;
        case '@':
            while(peek != '\n' && peek != EOF){
                peek = NEXT;
            }
            return comment_tok;
        case ':':
            peek = NEXT;
            return semicolon_tok;
        case EOF:
            br = NULL;
            lexer_line--;
            return eof_tok;
        default:
            {}
            char_al read_string = {0};            
            while(peek != '@' && peek != ':' && peek != ' ' && peek != '\t' && peek != '\r' && peek != '\n' && peek != EOF){
                
                if(peek == '-'){
                    peek = NEXT;
                    if(peek == '>'){
                        ungetc(peek,br);
                        peek = '-';
                        append_al(read_string,'\0');
                        return (token){IDENTIFIER_TAG,read_string.items};
                    }
                    
                    ungetc(peek,br);
                    peek = '-';
                }
                
                append_al(read_string,peek);

                peek = NEXT;
            
            }
            
            append_al(read_string,'\0');
            //trim_to_size_al(read_string);

            if(streq(read_string.items,     "base")){
                return base_tok;
            }
            else if(streq(read_string.items,"root")){
                return root_tok;
            }
            else if(streq(read_string.items,"method")){
                return method_tok;
            }
            else if(streq(read_string.items,"GET")){
                return get_tok;
            }
            else if(streq(read_string.items,"POST")){
                return post_tok;
            }
            else if(streq(read_string.items,"PUT")){
                return put_tok;
            }
            else if(streq(read_string.items,"DELETE")){
                return delete_tok;
            }
            else if(streq(read_string.items,"PATCH")){
                return patch_tok;
            }
            else if(streq(read_string.items,"functions")){
                return functions_tok;
            }
            else if(streq(read_string.items,"file")){
                return file_tok;
            }
            else if(streq(read_string.items,"dir")){
                return dir_tok;
            }


            return (token){IDENTIFIER_TAG,read_string.items};
    }
    
    generic_error("Something went wrong with the lexer... :c");
}

#undef NEXT
#undef streq
