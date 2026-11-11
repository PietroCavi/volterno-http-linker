#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lexer/token.h"

void parse(){
    printf("I'm parsing!\n");
}

void file_error(char* error_msg, char* file){

    fprintf(stderr,"%s %s\n",error_msg,file);

    exit(EXIT_FAILURE);

}

int main(int argc, char**argv){
    
    token t = arrow_tok;
    
    printf("%s\n",t.string);

    for(int i=1;i<argc;i++){
        
        FILE* config_file = fopen(argv[i],"r");

        if(config_file == NULL){
            file_error("Failed to open config file:",argv[i]);
        }

        parse();
        
        fclose(config_file);
    }

}
