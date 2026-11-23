#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "parser/parser.h"
#include "translator/translator.h"
#include "error_handling/error_handling.h"

int main(int argc, char**argv){

    FILE* output_file = NULL;
    
    int opt = getopt(argc,argv,"o:");
    if(opt != -1){
        if(opt == 'o'){ output_file = fopen(optarg,"w+"); }
        else{ generic_error("Wrong flag, only one supported: [-o <path>]");}
    }
    else{
        output_file = fopen("resources.c","w+");
    }
    if(output_file == NULL){ generic_error("Could not open specified <output_file>"); }



    for(int i=1;i<argc;i++){
        
        if(strcmp(argv[i],"-o")==0){
            i++;
            continue;
        }

        FILE* config_file = fopen(argv[i],"r");

        if(config_file == NULL){
            file_error("Failed to open config file",argv[i]);
        }
        
        printf("Parsing [%s]\n",argv[i]);

        setup_parser(config_file);
        parse();

        fclose(config_file);
        
        printf("\033[92mSUCCESS\033[0m - parsed lines: %llu\n",lexer_line);
    }

    if(!parser_base){
        generic_error("<base> was not specified");
    }
    
    translate(output_file);

    // debug section

    // printf("BASE:\n");
    // print_http_resource(base);
    // 
    // printf("GET:\n");
    // for(size_t i=0;i<get_resources.size;i++){
    //     print_http_resource(get_resources.items[i]);
    //     printf("\n");
    // }
    // 
    // printf("POST:\n");
    // for(size_t i=0;i<post_resources.size;i++){
    //     print_http_resource(post_resources.items[i]);
    //     printf("\n");
    // }
    // 
    // printf("DELETE:\n");
    // for(size_t i=0;i<delete_resources.size;i++){
    //     print_http_resource(delete_resources.items[i]);
    //     printf("\n");
    // }
    // 
    // printf("PUT:\n");
    // for(size_t i=0;i<put_resources.size;i++){
    //     print_http_resource(put_resources.items[i]);
    //     printf("\n");
    // }
    // 
    // printf("PATCH:\n");
    // for(size_t i=0;i<patch_resources.size;i++){
    //     print_http_resource(patch_resources.items[i]);
    //     printf("\n");
    // }

}
