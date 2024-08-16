/*
** EPITECH PROJECT, 2023
** print.c
** File description:
** print
*/

#include "../include/antman.h"
void counter_before(nodevalue_t* node)
{
    int i = 0;
    while (i < node->counter) {
        printf("%%");
        i++;
    }
}

void print_word(nodearray_t* array)
{
    int i = 0;
    while (i < array->size) {
        printf("%s@",array->nodes[i]->word);
        i++;
    }

}

void print_compress(nodearray_t* array, char* buffer)
{
    int i = 0; char word[100]; int j = 0;
    while (buffer[i] != '\0') {
        while (buffer[i] != ' ' && buffer[i] != '\0') {
            word[j] = buffer[i]; j++; i++;
        }
        word[j] = '\0'; j = 0;
        check_which_word(word, array);
        i++;
    }
}
