/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main for antman
*/

#include "../include/antman.h"

// void process_image(char *buffer);

// int compress_ppm(char  *filename)
// {
//     int fp = 0;
//     fp = open(filename, O_RDONLY);
//     if (fp != -1) {
//         char *buffer = read_file(filename);
//         process_image(buffer);
//         free(buffer);
//     } else {
//         return ERROR_EXIT;
//     }
//     return 0;
// }

void which_file(int argc, char **argv)
{
    int i = 0; int pos = 0; pos = -1; int r = 0;
    if (my_strcmp(argv[2], "1") == 0) {
        compress_txt(argv);
    }
    if (my_strcmp(argv[2], "2") == 0) {
        //compress_ppm(argv[1]);
    }
    if (my_strcmp(argv[2], "3") == 0) {
    }
}

int main(int argc, char **argv)
{
    if (argc > 2) {
        which_file(argc, argv);
    } else {
        return ERROR_EXIT;
    }
    return 0;
}