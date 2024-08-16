/*
** EPITECH PROJECT, 2022
** read_file.c
** File description:
** read file
*/

#include "../include/giantman.h"

int open_file(char *filename)
{
    int fp = 0;
    fp = open(filename, O_RDONLY);
    if (fp != -1) {
        char *buffer = read_file(filename);
        decompress_txt(buffer);
        return 0;
    } else {
        exit(84);
    }
}

char *read_file(char *filepath)
{
    struct stat st;
    stat(filepath, &st);
    int size = st.st_size;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("An error occured while reading the file\n");
        exit(84);
    }
    char *content = malloc(sizeof(char) * (size + 1));
    size = read(fd, content, size);
    content[size] = '\0';
    return content;
}
