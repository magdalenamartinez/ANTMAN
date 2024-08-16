/*
** EPITECH PROJECT, 2022
** image.c
** File description:
** image.c
*/

#include "../include/antman.h"

void print_coded_pair(char *pair)
{
    char nb;
    if (pair[0] == '\n')
        nb = pair[1] - 16;
    else if (pair[1] == '\n')
        nb = pair[0] - 6;
    if (check_digit(pair[0]) && check_digit(pair[1])) {
        int nbr = (pair[0] - 48) * 10 + (pair[1] - 48);
        nb = nbr + 52;
        if (74 <= nbr) {
            my_putchar('~');
            nb -= 94;
        }
    }
    my_putchar(nb);
}

void compress_numbers(char *buffer)
{
    int i = 0;
    int len = my_strlen(buffer);
    char *a = buffer;
    char b = '\n';
    while (len - i > 2) {
        print_coded_pair(&buffer[i]);
        i += 2;
    }
    my_putchar('\n');
    if (len - i != 0) {
        my_putchar(buffer[i]);
    }
}

void process_image(char *buffer)
{
    int i = parse_first_line(buffer);
    i += parse_w_h(&buffer[i]);
    i += check_if_header_left(&buffer[i]);
    compress_numbers(&buffer[i]);
}