/*
** EPITECH PROJECT, 2023
** antman.h
** File description:
** antman.h
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_
    #include "../../include/my.h"
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #define MAXBUFFER 200000
    void which_file(int argc, char **argv);
    void which_file2(int i, int pos, int argc, char **argv);
    typedef struct NodeValue {
        char character;
        int number;
        char *word;
    } node_value_t;
    typedef struct Node {
        struct NodeValue *value;
        int freq;
        struct Node *l, *r;
    } node_t;
    typedef struct nodevalue {
        char *word;
        char num;
        int counter;
    } nodevalue_t;
    typedef struct node_array{
        nodevalue_t **nodes;
        int size;
        char lastnumber;
        int porc;
    } nodearray_t;
    typedef struct Value_Num_Char {
        struct NodeValue *value;
        char *word;
    } value_t;
    typedef struct Num_Char {
        value_t** array;
        int numelements;
        int max_num;
    } num_char_t;
    void which_file(int argc, char **argv);
    void which_file2(int i, int pos, int argc, char **argv);
    int compress_txt(char **argv);
    char *read_file(char *filepath);
    void read_characters(char *buffer);
    void check_if_added(nodearray_t* array, char *word);
    void add_num(nodearray_t* array);
    nodearray_t* init_node_array(char* buffer);
    char* cut_word(char word[ ]);
    void check_which_word(char* word, nodearray_t* array);
    void print_compress(nodearray_t* array, char* buffer);
    void print_word(nodearray_t* array);
    void counter_before(nodevalue_t* node);
    int parse_first_line(char *buffer);
    int parse_w_h(char *buffer);
    int check_if_header_left(char *buffer);
#endif /*ANTMAN_H_*/
