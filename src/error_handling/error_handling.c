#include "error_handling.h"

void file_error(char* error_msg, char* file_name){

    fprintf(stderr,"\033[91mERROR\033[0m: %s: %s\n",error_msg,file_name);

    exit(EXIT_FAILURE);

}

void generic_error(char* error_msg){

    fprintf(stderr,"\033[91mERROR\033[0m: %s\n",error_msg);

    exit(EXIT_FAILURE);

}

void error_at_line(char* error_msg, long long unsigned line){

    fprintf(stderr,"\033[91mERROR\033[0m: %s :: at line %llu\n",error_msg,line);

    exit(EXIT_FAILURE);

}

void error_at_line_tok(char* error_msg, long long unsigned line, token tok){
    
    fprintf(stderr,"\033[91mERROR\033[0m: %s :: at line %llu :: token -> <%s,%d>\n",error_msg,line,tok.string,tok.tag);
    
    exit(EXIT_FAILURE);

}

void warning_at_line_resource(char* error_msg,long long unsigned line,http_resource resource){
    
    fprintf(stderr,"\033[95mWARNING\033[0m: %s :: at line %llu :: %s: %s\n",error_msg,line,resource.dir == 0 ? "file":"dir",resource.path);
    (void)resource;
    // print_http_resource(resource);

}
