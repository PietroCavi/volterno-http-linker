#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "error_handling/error_handling.h"
#include "lexer/token.h"
#include "lexer/lexer.h"

void parse(){
    printf("I'm parsing!\n");
}

int main(int argc, char**argv){
   
    token t = {0,"ciao"};

    for(int i=1;i<argc;i++){
        
        FILE* config_file = fopen(argv[i],"r");

        if(config_file == NULL){
            file_error("Failed to open config file",argv[i]);
        }
        
        setup_lexer(config_file);
        
        while(t.tag != EOF_TAG){
            t = lex();
            print_tok(t);

            if(t.tag == IDENTIFIER_TAG){
                free_tok(t);
            }
        }

        parse();
        
        fclose(config_file);
    }
    
    printf("Parsed lines: %llu\n",line);
}
