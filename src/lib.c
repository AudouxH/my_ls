/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** lib.c
*/

#include "../include/my_ls.h"

void my_putchar (char c)
{
    write (1, &c, 1);
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int find_digit(int x)
{
    int i = 0;
    while (x > 0) {
        x = x / 10;
        i++;
    }
    return (i);
}

void disp_val(int v)
{
    int x;
    if (v <= 9) {
        my_putchar(48 + v);
    } else {
        x = v / 10;
        x *= 10;
        my_putchar(48 + (v - x));
    }
}

int my_put_nbr(int nb)
{
    if (nb != 0) {
        int max_pow;
        int target_pow;
        int actual_digit;
        int value;
        if (nb < 0) {
            my_putchar('-');
            nb = nb * -1;
        }
        max_pow = find_digit(nb);
        target_pow = max_pow;
        actual_digit = nb;
        value = actual_digit;
        while (target_pow > 0) {
            value = actual_digit;
            for (int i = 1; i < target_pow; i++) {
                value = value / 10;
            }
            disp_val(value);
            --target_pow;
        }
    } else {
        my_putchar('0');
    }
    return (0);
}
