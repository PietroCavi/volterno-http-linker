#pragma once

#include <stdio.h>
#include "token.h"
#include "../array_list/array_list.h"

#include "../error_handling/error_handling.h"

extern long long unsigned lexer_line;

void setup_lexer(FILE* file);

token lex();
