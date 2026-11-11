#pragma once

#include <stdlib.h>
#include <stdio.h>

void file_error(char* error_msg, char* file_name);

void generic_error(char* error_msg);

void error_at_line(char* error_msg, long long unsigned line);
