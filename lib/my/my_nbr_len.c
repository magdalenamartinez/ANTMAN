/*
** EPITECH PROJECT, 2022
** my_nbr_len.c
** File description:
** my_nbr_len.c
*/

int my_nbr_len(int n)
{
    int count = 0;
    if (n < 0) {
        count = 1;
        n *= -1;
    }
    do {
        n /= 10;
        count++;
    } while (n != 0);
    return count;
}
