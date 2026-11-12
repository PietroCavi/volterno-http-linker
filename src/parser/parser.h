#ifndef __PARSER_CAVI__
#define __PARSER_CAVI__

#include "../lexer/lexer.h"

extern unsigned char parser_base;

void setup_parser(FILE* file);

void parse();

#endif
