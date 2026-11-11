#pragma once

#include <stdio.h>
#include "token.h"

int setup_lexer(FILE* file);

token lex();
