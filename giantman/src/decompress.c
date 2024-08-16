/*
** EPITECH PROJECT, 2022
** decompress.c
** File description:
** image decompression
*/

#include "../include/giantman.h"

int decompress_txt(char *buf)
{
    int numw = num_words(buf);
    array_char_code_t* array = init_char_code(buf, numw);
    read_words(array, numw, buf);
    read_code(array, buf);
    int i = 0;
    look_which_one(array, buf);
    my_printf("%c",8);
    free(buf);
    return 0;
}

void look_which_one(array_char_code_t* array, char* buffer)
{
    int i = 0; int j = 0;
    while (buffer[i] != '\0' && buffer[i] != 32) {
        i++;
    }
    while (buffer[i] != '\0') {
        if (buffer[i] == '%' && j != 5) {
            i = show_word_percentage(array, buffer, i);
        } else {
            show_word(array, buffer[i]);
            i++;
        }
    }
}

array_char_code_t* init_char_code(char *buffer, int num_words)
{
    array_char_code_t* array;
    array = (array_char_code_t *) malloc(sizeof(array_char_code_t));
    array->size = 0; int n = 0; n = 1;
    array->array_code = (node_t **) malloc(sizeof(node_t*) * num_words);
    int i = 0;
    while (i < num_words) {
        array->array_code[i] = (node_t*) malloc(sizeof(node_t));
        if (i == (127 * n)) {
            n++;
        }
        array->array_code[i]->num = malloc(sizeof(char) * n);
        i++;
    }
    return array;
}
