#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* copy_except_indexed_char(char* src, int index) {
    const int len = (int) strlen(src);
    int j = 0;

    // Allocate memory for the destination string
    char *dest = malloc(len * sizeof(char));

    // Copy characters except the one at the given index
    for (int i = 0; i < len; i++) {
        if (i != index) {
            dest[j] = src[i];
            j++;
        }
    }

    // Null-terminate the destination string
    dest[j] = '\0';

    return dest;
};

char * removeDigit(char * number, char digit) {
    const int length = (int) strlen(number);
    char *out = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        out[i] = '0';
    }

    for (int i = 0; i < length; i++) {
        if (number[i] == (char) digit){
            // get all the digits except the indexed one
            char *substr = copy_except_indexed_char(number, i);

            // compare to current max, if greater, replace
            if (strcmp(substr, out) > 0) {
                strcpy(out, substr);
            }
        }
    }
    return out;
};

int main(){
    char * ans = removeDigit("133235", '3');
    printf("%s\n", ans);
    ans = removeDigit("7795478535679443616467964135298543163376223791274561861738666981419251859535331546947347395531332878", '5');
    printf("%s\n", ans);
};