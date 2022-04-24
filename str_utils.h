#pragma once
#ifndef STR_UTILS_H
#define STR_UTILS_H
int str_contains(const char *str, const char *find) {
    char *c[5];
    int check_point = 0;
    char *new_str[1024];
    for(int i = 0; i <= strlen(str); i++) {
        if(str[i] == NULL || str[i] == '\0' || i == strlen(str)) return check_point == strlen(find) ? 1 : 0;
        sprintf(c, "%s", &str[i]); // Set current char
        if(str[i] == find[0]) {
            if(strlen(find) > 0) {
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
        if(str[i] == 32) {
            spaces++;
        }
    }
    return spaces/8 == 0 ? 0 : spaces/8+1;
}

int char_count(const char *str, const char *find) {

}
#endif
