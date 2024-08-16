/*
** EPITECH PROJECT, 2023
** words.c
** File description:
** words
*/

#include "../include/giantman.h"

void read_words(array_char_code_t* array, int num_words, char* buffer)
{
    int j = 0;
    char word[10000]; int i = 0; int t = 0;
    while (t < num_words && buffer[i] != '\0') {
        while (buffer[i] != '@') {
            word[j] = buffer[i];
            j++;
            i++;
        }
        word[j] = '\0'; t++;
        add_new_word(word, array, j);
        j = 0;
        i++;
    }
}

void add_new_word(char word[ ], array_char_code_t* array, int j)
{
    array->array_code[array->size]->word = malloc(sizeof(char) * j);
    int i = 0;
    while (word[i] != '\0') {
            array->array_code[array->size]->word[i] = word[i];
            i++;
    }
    array->array_code[array->size]->word[i] = '\0';
    array->size++;
}

int num_words(char *buffer)
{
    int numw = 0; int i = 0;
    int found = 0; int j = 0; int k = 0; k = i;
    while (buffer[i] != 32 && buffer[i] != '\0') {
        if (buffer[i] == '@') {
            numw++;
        }
        i++;
    }
    return numw;
}

void show_word(array_char_code_t* array, char b)
{
    int i = 0;
    while (i < array->size) {
        if (array->array_code[i]->num[0] == b) {
            my_printf("%s ", array->array_code[i]->word);
            break;
        }
        i++;
    }
}
