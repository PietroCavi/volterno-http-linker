#ifndef __PARSER_CAVI__
#define __PARSER_CAVI__

#include "../lexer/lexer.h"
#include "parser_structs.h"
#include "../array_list/array_list.h"

extern unsigned char parser_base;

void setup_parser(FILE* file);

void parse();

typedef enum{
    NOT_DEFINED,
    GET,
    POST,
    DELETE,
    PUT,
    PATCH
}http_method;


#endif
