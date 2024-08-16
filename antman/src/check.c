/*
** EPITECH PROJECT, 2023
** check.c
** File description:
** check
*/

#include "../include/antman.h"

void check_which_word(char* word, nodearray_t* array)
{
    int i = 0;
    while (i < array->size) {
        if (my_strcmp3(array->nodes[i]->word, word) == 0) {
            counter_before(array->nodes[i]);
            printf("%c", array->nodes[i]->num); break;
        }
        i++;
    }
}

void check_if_added(nodearray_t* array, char word[ ])
{
    int i = 0; int found = 0;
    while (i < array->size) {
        if (my_strcmp3(array->nodes[i]->word, word) == 0) {
            found = 1; break;
        }
        i++;
    }
    if (found == 0) {
        i = 0;
        array->nodes[array->size] = malloc(sizeof(nodevalue_t));
        while (word[i] != '\0') {
            i++;
        }
        array->nodes[array->size]->word = malloc(sizeof(char) * i); i = 0;
        while (word[i] != '\0') {
            array->nodes[array->size]->word[i] = word[i]; i++;
        }
        array->nodes[array->size]->word[i] = '\0';
        add_num(array); array->size++;
    }
}
