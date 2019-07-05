/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** str_compare.c
*/

#include "../include/my_ls.h"

int str1_compare(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return (-1);
    return (0);
}

int str2_compare(char *str1, char *str2)
{
    for (int i = 0; str2[i] != '\0'; i++)
        if (str2[i] != str1[i])
            return (-1);
    return (0);
}

int str_compare(char *str1, char *str2)
{
    if (str1_compare(str1, str2) == -1)
        return (-1);
    else if (str2_compare(str1, str2) == -1)
            return (-1);
    return (0);
}