#pragma once

#include "../lexer/lexer.h"

extern unsigned char parser_base;

void setup_parser(FILE* file);

void parse();
