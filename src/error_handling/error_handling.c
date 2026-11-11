#include "error_handling.h"

void file_error(char* error_msg, char* file_name){

    fprintf(stderr,"%s: %s\n",error_msg,file_name);

    exit(EXIT_FAILURE);

}

void generic_error(char* error_msg){

    fprintf(stderr,"%s\n",error_msg);

    exit(EXIT_FAILURE);

}

void error_at_line(char* error_msg, long long unsigned line){

    fprintf(stderr,"%s :: at line %llu\n",error_msg,line);

    exit(EXIT_FAILURE);

}
