/********************************************
    String Modification Header File
@author: 0xLulz
@title: STR_UTILS.h
@since: 02/09/2022
********************************************/
#pragma once
#ifndef STR_UTILS_H
#define STR_UTILS_H

typedef struct STR_UTILS {
    void*   (*replace)(const char *str, const char *substr, const char *replacement, char *dest);
    void*   (*split)()
} StrUtils;

int str__replace(const char *str, const char *substr, const char *replacement, char *dest) {
    // Checking to make sure we got a string over 1 character
    if(strlen(str) < 1) return 0;
    // Checking if substr is bigger than str, if so return 0
    if(strlen(substr) > strlen(str)) return 0;
    if(strlen(replacement) == 0) return 0;
    
    // New String Made To Append to and copy to 'dest' memory address
    char new_str = (char)malloc(sizeof(char *)*255+1);

    // For Words
    char start_c[5], end_c[5];

    // Word Search Toggle
    // If toggle is 1 then ignore the word and record the current character
    int toggle = 0;

    if(strlen(str) > 2) { // Making sure we got 2 character for start and end
        sprintf(start_c, "%c", str[0]); // Grabbing first and last character from string
        sprintf(end_c, "%c", str[strlen(str)]);
    }

    for(int i = 0; i <= strlen(str); i++) {
        sprintf(c, "%c", str[i]);
        if(c == start_c && toggle == 0) {
            togger = 1;
        } else if(c == end_c && toggle == 1) {
            toggle = 0;
            strcat(new_str, replacement);
        } else if(toggle == 0) {
            strcat(new_str, c);
        }
    }
    strcpy(dest, new_str);
    free(new_str);
}

int str_contains(const char *str, const char *find) {
    char *c[5];
    int check_point = 0;
    char *new_str[1024];
    for(int i = 0; i <= strlen(str); i++) {
        if(str[i] == NULL || str[i] == '\0' || i == strlen(str)) return check_point == strlen(find) ? 1 : 0;
        sprintf(c, "%s", &str[i]); // Set current char
        if(str[i] == find[0]) {
            if(strlen(find) > 1) { // finding words
                int new = i;
                for(int a = 0; a <= strlen(find); a++) {
                    if(find[i] == NULL || find[i] == '\0' || a == strlen(find)) return check_point == strlen(find) ? 1 : 0;
                    if(str[new] == find[a]) {
                        check_point++;
                        strcat(new_str, c);
                    } else { check_point--; }
                    new++;
                }
            } else { /* find one char only */ }
        }
    }
    return 0;
}

int count_spaces(const char *str) {
    int spaces = 0;
    for(int i = 0; i <= strlen(str); i++) {
        if(str[i] == NULL || str[i] == '\0' || i == strlen(str)) return spaces;
        if(str[i] == 32) spaces++;
    }
    return spaces/8 == 0 ? 0 : spaces/8+1;
}

int char_count(const char *str, const char *find) {

}

StrUtils Build_StrUtils() {
    StrUtils s;
    s->replace = str__replace;
    return s;
}
#endif
