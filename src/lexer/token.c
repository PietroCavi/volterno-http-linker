#include "token.h"
#include <stdlib.h>

const token base_tok       = {BASE_TAG,      "base"     };
const token root_tok       = {ROOT_TAG,      "root"     };
const token method_tok     = {METHOD_TAG,    "method"   };
const token get_tok        = {GET_TAG,       "GET"      };
const token post_tok       = {POST_TAG,      "POST"     };
const token put_tok        = {PUT_TAG,       "PUT"      };
const token delete_tok     = {DELETE_TAG,    "DELETE"   };
const token patch_tok      = {PATCH_TAG,     "PATCH"    };
const token functions_tok  = {FUNCTIONS_TAG, "functions"};
const token file_tok       = {FILE_TAG,      "file"     };
const token dir_tok        = {DIR_TAG,       "dir"      };
const token arrow_tok      = {ARROW_TAG,     "->"       };
const token comment_tok    = {COMMENT_TAG,   "@"        };
const token semicolon_tok  = {SEMICOLON_TAG, ":"        };

inline void free_tok(token t){
    if(t.string != NULL){
        free(t.string);
    }
}
