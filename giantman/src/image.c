/*
** EPITECH PROJECT, 2022
** image.c
** File description:
** image decompression
*/

#include "../include/giantman.h"

void get_decoded_number(char nb, int flag)
{
    if (32 <= nb && nb <= 41 && !flag) {
        my_printf("\n%d", (nb - 32) % 10);
    } else if (42 <= nb && nb <= 51 && !flag) {
        my_printf("%d\n", (nb - 32) % 10);
    } else {
        nb = (nb - 52) + 94 * flag;
        if (nb < 10)
            my_printf("0");
        my_printf("%d", nb);
    }
}

void decode(char symb)
{
    static int flag = 0;
    if (symb == '~')
        flag = 1;
    else {
        get_decoded_number(symb, flag);
        if (flag) {
            flag = 0;
        }
    }
}

int decompress_img(char *filename)
{
    char *line = read_file(filename);
    int i = parse_first_line(line);
    i += parse_w_h(&line[i]);
    i += check_if_header_left(&line[i]);
    int len = my_strlen(line);
    while (line[i] != '\n') {
        decode(line[i]);
        i++;
    }
    i++;
    while (len - i != 0){
        if (line[i] != '\n')
        my_putchar(line[i]);
        i++;
    }
    my_putchar('\n');
}