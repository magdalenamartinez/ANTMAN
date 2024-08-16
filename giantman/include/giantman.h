/*
** EPITECH PROJECT, 2023
** giantman.h
** File description:
** giantman.h
*/

#ifndef GIANTMAN_H_
    #define GIANTMAN_H_
    #include "../../include/my.h"
    #include "fcntl.h"
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    typedef struct Char_Code{
        char *num;
        char* word;
    } node_t;
    typedef struct Array_Char_Code{
        int size;
        int j;
        node_t **array_code;
    } array_char_code_t;
int decompress_img(char *filename);
int parse_first_line(char *buffer);
int parse_w_h(char *buffer);
int check_if_header_left(char *buffer);
int get_nodes(char *buffer);
int decompress_txt(char *buf);
void insert_percentage(char b, array_char_code_t* array, int n, int j);
int check_if_porc_inst(char* buffer, array_char_code_t* array, int i, int j);
void look_which_one(array_char_code_t* array, char* buffer);
int show_word_percentage(array_char_code_t* array, char *buffer, int i);
void show_word(array_char_code_t* array, char b);
int num_words(char *buffer);
void read_code(array_char_code_t* array, char* buffer );
array_char_code_t* init_char_code(char *buffer, int num_words);
void add_new_word(char word[ ], array_char_code_t* array, int j);
void read_words(array_char_code_t* array, int num_words, char* buffer);
int which_file(int argc, char **argv);
int open_file(char *filename);
int num_characters(int i, char *buffer);
int look_code(int i, char* buffer);
int function_porc(char* buffer, array_char_code_t* array, int i, int j);
void insertar(array_char_code_t* array, char* buffer, int i, int j);
int check_if_not_inserted(array_char_code_t* array, char* buffer, int r, int j);
//array_char_code_t* init_char_code(char *buffer, int tam);
char *read_file(char *filepath);
#endif /*GIANTMAN_H_*/
