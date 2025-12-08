#include "../include/utils.h"
#include <string.h>
#include <ctype.h>

void remover_enter(char *str)
{
    int len = strlen(str);
    if(len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void formatar_maiuscula(char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        *(str+i) = toupper(*(str+i));
    }
}