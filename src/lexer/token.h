#pragma once

typedef enum{

    BASE_TAG,
    ROOT_TAG,
    METHOD_TAG,
        GET_TAG, 
        POST_TAG, 
        PUT_TAG, 
        DELETE_TAG, 
        PATCH_TAG,
    FUNCTIONS_TAG,
    FILE_TAG,
    DIR_TAG,
    ARROW_TAG,
    COMMENT_TAG,
    SEMICOLON_TAG,
    IDENTIFIER_TAG,

    EOF_TAG

}token_tag;

typedef struct{
	token_tag tag;
	char*string; // string or char
}token;

extern const token base_tok;
extern const token root_tok;
extern const token method_tok;
extern const token get_tok;
extern const token post_tok;
extern const token put_tok;
extern const token delete_tok;
extern const token patch_tok;
extern const token functions_tok;
extern const token file_tok;
extern const token dir_tok;
extern const token arrow_tok;
extern const token comment_tok;
extern const token semicolon_tok;
extern const token eof_tok;

void free_tok(token t);
