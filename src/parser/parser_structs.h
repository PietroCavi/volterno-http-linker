#ifndef __PARSER_STRUCTS_CAVI__
#define __PARSER_STRUCTS_CAVI__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// TODO: once dirs will be expanded in the parser the dir field will be optional, thus removed
typedef struct{

    char* path;
    unsigned char dir;
    char* function_name;

}http_resource;

typedef struct{
    
    http_resource* items;
    size_t size;
    size_t capacity;
}http_resource_al;


extern http_resource base;

extern http_resource_al get_resources;
extern http_resource_al post_resources;
extern http_resource_al delete_resources;
extern http_resource_al put_resources;
extern http_resource_al patch_resources;


int equals_http_resource(http_resource,http_resource);
int contains_http_resouce(http_resource_al,http_resource);

void print_http_resource(http_resource);
void free_http_resource(http_resource);

#endif
