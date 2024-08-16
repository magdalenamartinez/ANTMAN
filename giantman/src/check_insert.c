/*
** EPITECH PROJECT, 2023
** read_check.c
** File description:
** readcheck
*/

#include "../include/giantman.h"

void read_code(array_char_code_t* array, char* buffer )
{
    int i = 0;
    while (buffer[i] != '\0' && buffer[i] != 32) {
        i++;
    }
    int j = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '%' && j != 5) {
            i = check_if_porc_inst(buffer, array, i, j);
        } else {
            j = check_if_not_inserted(array, buffer, i, j);
            i++;
        }
    }
}

int check_if_not_inserted(array_char_code_t* array, char* buffer, int r, int j)
{
    int i = 0; int found = 0;
    while (i < array->j) {
        if (buffer[r] == array->array_code[i]->num[0]) {
            found = 1; break;
        }
        i++;
    }
    if (found == 0) {
        insertar(array, buffer, r, j);
        j++;
    }
    return j;
}

void insertar(array_char_code_t* array, char* buffer, int i, int j)
{
    array->array_code[array->j]->num = malloc(sizeof(char) + 1);
    array->array_code[array->j]->num[0] = buffer[i];
    array->array_code[array->j]->num[1] = '\0';
    array->j++;
}
