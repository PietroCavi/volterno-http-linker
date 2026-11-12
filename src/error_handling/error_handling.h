#ifndef __ERROR_HANDLING_CAVI__
#define __ERROR_HANDLING_CAVI__

#include <stdlib.h>
#include <stdio.h>

#include "../lexer/token.h"

void file_error(char* error_msg, char* file_name);

void generic_error(char* error_msg);

void error_at_line(char* error_msg, long long unsigned line);

void error_at_line_tok(char* error_msg, long long unsigned line, token tok);

#endif
