/*
** EPITECH PROJECT, 2023
** percentage.c
** File description:
** percentage
*/

#include "../include/giantman.h"

int check_if_porc_inst(char* buffer, array_char_code_t* array, int i, int j)
{
    int n = 0; int found = 0; int t = 0;
    while (buffer[i] == '%') {
        n++; i++;
    }
    char b[100]; int k = 0;
    while (k < n) {
        b[k] = '%'; k++;
    }
    b[k] = buffer[i]; k++; b[k] = '\0';
    while (t < array->j) {
        if (my_strcmp3(b, array->array_code[t]->num) == 0) {
            found = 1; break;
        }
        t++;
    }
    if (found == 0) {
        insert_percentage(buffer[i], array, n, j);
    }
    i++; return i;
}

void insert_percentage(char b, array_char_code_t* array, int n, int j)
{
    int a = 0;
    array->array_code[array->j]->num = malloc(sizeof(char)* (n + 1));
    while (a < n) {
        array->array_code[array->j]->num[a] = '%';
        a++;
    }
    array->array_code[array->j]->num[a] = b; a++;
    array->array_code[array->j]->num[a] = '\0';
    array->j++;
}

int function_porc(char* buffer, array_char_code_t* array, int i, int j)
{
    int n = 0;
    while (buffer[i] == '%') {
        n++; i++;
    }
    int a = 0;
    array->array_code[j]->num = malloc(sizeof(char)* (n + 2));
    while (a < n) {
        array->array_code[j]->num[a] = '%'; a++;
    }
    array->array_code[j]->num[a] = buffer[i]; a++;
    array->array_code[j]->num[a] = '\0';
    i++;
    return i;

}

int show_word_percentage(array_char_code_t* array, char *buffer, int i)
{
    int n = 0;
    while (buffer[i] == '%') {
        n++; i++;
    }
    char b[100]; int k = 0;
    while (k < n) {
        b[k] = '%'; k++;
    }
    b[k] = buffer[i]; k++; b[k] = '\0'; int t = 0;
    while (t < array->size) {
        if (my_strcmp3(b,array->array_code[t]->num) == 0) {
            printf("%s ",array->array_code[t]->word);
            break;
        }
        t++;
    }
    i++; return i;
}
