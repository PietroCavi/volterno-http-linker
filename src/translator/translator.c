#include "translator.h"

void translate(FILE* output_file){
   
    size_t get_resources_len    = 0;
    size_t post_resources_len   = 0;
    size_t delete_resources_len = 0;
    size_t put_resources_len    = 0;
    size_t patch_resources_len  = 0;
                      
    size_t get_dir_resources_len    = 0;
    size_t post_dir_resources_len   = 0;
    size_t delete_dir_resources_len = 0;
    size_t put_dir_resources_len    = 0;
    size_t patch_dir_resources_len  = 0;
    
    for(size_t i=0;i<get_resources.size;i++){
        if(get_resources.items[i].dir){ get_dir_resources_len++; }
        else{ get_resources_len++; }
    }
    for(size_t i=0;i<post_resources.size;i++){
        if(post_resources.items[i].dir){ post_dir_resources_len++; }
        else{ post_resources_len++; }
    }
    for(size_t i=0;i<delete_resources.size;i++){
        if(delete_resources.items[i].dir){ delete_dir_resources_len++; }
        else{ delete_resources_len++; }
    }
    for(size_t i=0;i<put_resources.size;i++){
        if(put_resources.items[i].dir){ put_dir_resources_len++; }
        else{ put_resources_len++; }
    }
    for(size_t i=0;i<patch_resources.size;i++){
        if(patch_resources.items[i].dir){ patch_dir_resources_len++; }
        else{ patch_resources_len++; }
    }

    fprintf(output_file,"#include \"resources.h\"\n\n");
    
    fprintf(output_file,"http_resource base = {\n \
                     .server_path = \"/%s\",\n \
                     .real_path   = \"./%s\",\n \
                     .function    = %s\n \
                    };\n",base.path,base.path,base.function_name == NULL ? "NULL" : base.function_name);

    
    fprintf(output_file,"\n");
   
    fprintf(output_file,"size_t get_resources_len    = %lu;\n", get_resources_len   );
    fprintf(output_file,"size_t post_resources_len   = %lu;\n", post_resources_len  );
    fprintf(output_file,"size_t delete_resources_len = %lu;\n", delete_resources_len);
    fprintf(output_file,"size_t put_resources_len    = %lu;\n", put_resources_len   );
    fprintf(output_file,"size_t patch_resources_len  = %lu;\n", patch_resources_len );
    fprintf(output_file,"\n");
    fprintf(output_file,"size_t get_dir_resources_len    = %lu;\n", get_dir_resources_len   );
    fprintf(output_file,"size_t post_dir_resources_len   = %lu;\n", post_dir_resources_len  );
    fprintf(output_file,"size_t delete_dir_resources_len = %lu;\n", delete_dir_resources_len);
    fprintf(output_file,"size_t put_dir_resources_len    = %lu;\n", put_dir_resources_len   );
    fprintf(output_file,"size_t patch_dir_resources_len  = %lu;\n", patch_dir_resources_len );
     
    fprintf(output_file,"\n");
    
    
    fprintf(output_file,"http_resource get_resources[%lu] = {\n", get_resources_len);
    for(size_t i=0;i<get_resources.size;i++){
        if(get_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   get_resources.items[i].path,
            get_resources.items[i].path,
            get_resources.items[i].function_name == NULL ? "NULL" : get_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");
   
    fprintf(output_file,"\n");

    fprintf(output_file,"http_resource post_resources[%lu] = {\n", post_resources_len);
    for(size_t i=0;i<post_resources.size;i++){
        if(post_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   post_resources.items[i].path,
            post_resources.items[i].path,
            post_resources.items[i].function_name == NULL ? "NULL" : post_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");

    fprintf(output_file,"\n");

    fprintf(output_file,"http_resource delete_resources[%lu] = {\n", delete_resources_len);
    for(size_t i=0;i<delete_resources.size;i++){
        if(delete_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   delete_resources.items[i].path,
            delete_resources.items[i].path,
            delete_resources.items[i].function_name == NULL ? "NULL" : delete_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");

    fprintf(output_file,"\n");

    fprintf(output_file,"http_resource put_resources[%lu] = {\n", put_resources_len);
    for(size_t i=0;i<put_resources.size;i++){
        if(put_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   put_resources.items[i].path,
            put_resources.items[i].path,
            put_resources.items[i].function_name == NULL ? "NULL" : put_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");

    fprintf(output_file,"\n");

    fprintf(output_file,"http_resource patch_resources[%lu] = {\n", patch_resources_len);
    for(size_t i=0;i<patch_resources.size;i++){
        if(patch_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   patch_resources.items[i].path,
            patch_resources.items[i].path,
            patch_resources.items[i].function_name == NULL ? "NULL" : patch_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");
    
    fprintf(output_file,"\n");

    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////
    
    fprintf(output_file,"http_resource get_dir_resources[%lu] = {\n", get_dir_resources_len);
    for(size_t i=0;i<get_resources.size;i++){
        if(!get_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   get_resources.items[i].path,
            get_resources.items[i].path,
            get_resources.items[i].function_name == NULL ? "NULL" : get_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");
   
    fprintf(output_file,"\n");

    fprintf(output_file,"http_resource post_dir_resources[%lu] = {\n", post_dir_resources_len);
    for(size_t i=0;i<post_resources.size;i++){
        if(!post_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   post_resources.items[i].path,
            post_resources.items[i].path,
            post_resources.items[i].function_name == NULL ? "NULL" : post_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");

    fprintf(output_file,"\n");

    fprintf(output_file,"http_resource delete_dir_resources[%lu] = {\n", delete_dir_resources_len);
    for(size_t i=0;i<delete_resources.size;i++){
        if(!delete_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   delete_resources.items[i].path,
            delete_resources.items[i].path,
            delete_resources.items[i].function_name == NULL ? "NULL" : delete_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");

    fprintf(output_file,"\n");

    fprintf(output_file,"http_resource put_dir_resources[%lu] = {\n", put_dir_resources_len);
    for(size_t i=0;i<put_resources.size;i++){
        if(!put_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   put_resources.items[i].path,
            put_resources.items[i].path,
            put_resources.items[i].function_name == NULL ? "NULL" : put_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");

    fprintf(output_file,"\n");

    fprintf(output_file,"http_resource patch_dir_resources[%lu] = {\n", patch_dir_resources_len);
    for(size_t i=0;i<patch_resources.size;i++){
        if(!patch_resources.items[i].dir){ 
            continue;
        }
        else{ 
            fprintf(output_file,"    {\n \
    .server_path = \"/%s\",\n \
    .real_path   = \"./%s\",\n \
    .function    = %s\n \
   },\n",   patch_resources.items[i].path,
            patch_resources.items[i].path,
            patch_resources.items[i].function_name == NULL ? "NULL" : patch_resources.items[i].function_name);
        }
    }
    fprintf(output_file,"}\n");

}
