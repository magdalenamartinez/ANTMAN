/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** funcion which
*/

#include <stdio.h>
int return_value(char *a);
int compare(char a, char b);
int my_strcmp3(char* a, char* b)
{
    int i = 0; int j = 0; int notequal = 0;
    i = return_value(a);
    j = return_value(b);
    if (i == j) {
        i = 0;
        while (a[i] == b[i] && i < j && notequal == 0) {
            notequal = compare(a[i], b[i]);
            i++;
        }
        if (a[i] != b[i]) {
            notequal = 1;
        }
    } else {
        notequal = 1;
    }
    return notequal;
}

int return_value(char *a)
{
    int i = 0;
    while (a[i] != '\0') {
        i++;
    }
    return i;
}

int compare(char a, char b)
{
    int notequal = 0;
    if (a != b) {
        notequal = 1;
    }
    return notequal;
}
