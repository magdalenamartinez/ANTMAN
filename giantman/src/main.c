/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** giantman main
*/
#include "../include/giantman.h"
int decompress_img(char *filename);

int main(int argc, char **argv)
{
    if (argc > 2) {
        which_file(argc, argv);
    } else {
        return ERROR_EXIT;
    }
    return 0;
}

int which_file(int argc, char **argv)
{
    int i = 0; int pos = 0; pos = -1; int r = 0;
    if (my_strcmp(argv[2], "1") == 0) {
        r = open_file(argv[1]);
    }
    if (my_strcmp(argv[2], "2") == 0) {
        //decompress_img(argv[1]);
    }
    if (my_strcmp(argv[2], "3") == 0) {
    }
    return r;
}
