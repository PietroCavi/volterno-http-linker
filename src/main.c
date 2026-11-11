#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "parser/parser.h"
#include "error_handling/error_handling.h"

int main(int argc, char**argv){
   

    for(int i=1;i<argc;i++){
        
        FILE* config_file = fopen(argv[i],"r");

        if(config_file == NULL){
            file_error("Failed to open config file",argv[i]);
        }
        
        setup_parser(config_file);
        parse();
       
        fclose(config_file);
    }
    
    printf("Parsed lines: %llu\n",line);
}
