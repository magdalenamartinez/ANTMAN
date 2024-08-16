/*
** EPITECH PROJECT, 2022
** isdigit.c.c
** File description:
** isdigit
*/

int check_digit(char c)
{
    if ((c >= '0') && (c <= '9'))
        return 1;
    return 0;
}
