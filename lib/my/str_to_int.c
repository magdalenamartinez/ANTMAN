/*
** EPITECH PROJECT, 2022
** str_to_int.c
** File description:
** converts str to int
*/

int str_to_int(char *line)
{
    int result = 0;
    for (int i = 0; 48 <= line[i] && line[i] <= 57; i++)
        result = result * 10 + (line[i] - 48);
    return result;
}
