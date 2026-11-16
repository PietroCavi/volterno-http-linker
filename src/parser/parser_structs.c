#include "parser_structs.h"

http_resource base = {0};

http_resource_al get_resources = {0};
http_resource_al post_resources = {0};
http_resource_al delete_resources = {0};
http_resource_al put_resources = {0};
http_resource_al patch_resources = {0};

int equals_http_resource(http_resource res0,http_resource res1){
    return strcmp(res0.path,res1.path)==0 && res0.dir == res1.dir;
}

int contains_http_resouce(http_resource_al list,http_resource elem){
    for(size_t i=0;i<list.size;i++){
        if(equals_http_resource(list.items[i],elem)){
            return 1;
        }
    }

    return 0;
}

void print_http_resource(http_resource res){
    printf("path: %s\ndir: %s\nfunction_name: %s\n",res.path,res.dir==0?"No":"Yes",res.function_name);
}

void free_http_resource(http_resource res){
    if(res.path != NULL){
        free(res.path);
    }
    if(res.function_name != NULL){
        free(res.function_name);
    }
    res.dir = 0;
}
