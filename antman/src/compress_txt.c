/*
** EPITECH PROJECT, 2022
** compress_txt.c
** File description:
** txt files compression for antman
*/

#include "../include/antman.h"

int compress_txt(char **argv)
{
    char *buffer = read_file(argv[1]);
    read_characters(buffer);
    free(buffer);
    return 0;
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

void read_characters(char *buffer)
{
    int i = 0;
    nodearray_t* array = init_node_array(buffer);
    char word[100000]; int j = 0;
    while (buffer[i] != '\0') {
        while (buffer[i] != ' ' && buffer[i] != '\0') {
            word[j] = buffer[i];
            j++; i++;
        }
        word[j] = '\0'; check_if_added(array, word);
        if (buffer[i] == '\0') {
            break;
        } 
        j = 0;
        i++;
    }
    print_word(array);
    print_compress(array, buffer);
    free_array(array, buffer);
}

void free_array(nodearray_t* a, char* buffer) 
{
    int i = 0; int n = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == ' ') {
            n++;
        }
        i++;
    }
    i = 0;
    while (i < n) {
        free(a->nodes[i]->word);
        free(a->nodes[i]);
        i++;
    }
    free(a);
}

void add_num(nodearray_t* array)
{
    array->nodes[array->size]->num = array->lastnumber;
    array->nodes[array->size]->counter = 0;
    if (array->lastnumber == 36) {
        array->lastnumber++;
    }
    if (array->porc > 0) {
        array->nodes[array->size]->counter = array->porc;
    }
    if (array->lastnumber == 127) {
        array->lastnumber = 32;
        array->porc++;
        array->nodes[array->size]->counter = array->porc;
    }
    array->lastnumber++;
}

nodearray_t* init_node_array(char *buffer)
{
    nodearray_t* array = malloc(sizeof(nodearray_t));
    array->size = 0;
    array->porc = 0;
    array->lastnumber = 32;
    int n = 0; int i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == ' ') {
            n++;
        }
        i++;
    }
    //n++;
    array->nodes = (nodevalue_t**)malloc(sizeof(nodevalue_t) * (n));
    for (int i = 0; i < n; i++) {
        array->nodes[i] = NULL;
    }
    //array->nodes = (nodevalue_t**)malloc(sizeof(nodevalue_t*));
    return array;
}
