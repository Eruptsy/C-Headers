/*
    file_reader.h
@title: file reader
@author: Erupt
@since: 4/23/22
*/
#pragma once
#ifndef FILE_READER_H
#define FILE_READER_H

typedef struct Skrillec {
    char    *filepath[1024];
    char    *data[1024];
    void*   (*set_file)(sk, sk);
    void*   (*process)(sk);
    void*   (*print_data)(sk);
    void*   (*get_data)(sk);
    void*   (*large_process)(sk);
} sk;

int __set_file(sk *s, char *path) {
    if(strlen(path) > 255) return 0;
    if(!access(path, F_OK) == 0) return 0;
    sprintf(s->filepath, "%s", path);
    return 1;
}

void __process(sk *s) {
    FILE *fd;
    fd = fopen(s->filepath, "r");
    if(fd == NULL) return;
    fread(s->data, 1024, 1, fd);
    fclose(fd);
}

char __data(sk *s) {
    return s->data;
}

void __large_process(sk *s, char *dest) {
    FILE *fd;
    char *file_data;
    long fd_size;

    fd = fopen(s->filepath, "r");
    if(fd == NULL) return;
    fseek(fd, 0L, SEEK_END);
    fd_size = ftell(fd);
    fseek(fd, 0L, SEEK_SET);

    file_data = (char*)malloc(sizeof(char *)*fd_size);

    if(file_data == NULL) return;

    fread(file_data, sizeof(char ), fd_size, fd);
    fclose(fd);
    free(file_data);
    strcpy(dest, file_data);
}

sk Build() {
    sk s;
    s.set_file = __set_file;
    s.process = __process;
    s.get_data = __data;
    s.large_process = __large_process;
    return s;
}
#endif
