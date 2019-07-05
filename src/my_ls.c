/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** my_ls.c
*/

#include "../include/my_ls.h"

void display_argument(char **argument, flags_t *flags)
{
    if (check_if_one_argv(argument, flags) == 1)
        return;
    else
        display_few_argv(argument, flags);
}

int main (int ac, char **av)
{
    flags_t flags;
    char **argument;

    init_all_flags(&flags, ac, av);
    argument = check_argument(ac, av);
    display_argument(argument, &flags);
    free(argument);
}
