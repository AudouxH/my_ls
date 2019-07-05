/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** check_argv.c
*/

#include "../include/my_ls.h"

int switch_for_flags(char **av, int ac, flags_t *flags)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            for (int y = 1; av[i][y] != '\0'; y++) {
                switch (av[i][y])
                {
                case 'l':
                    flags->dash_l = 1;
                    break;
                case 'R':
                    flags->dash_R = 1;
                    break;
                case 'r':
                    flags->dash_r = 1;
                    break;
                case 't':
                    flags->dash_t = 1;
                    break;
                default:
                    return (84);
                    break;
                }
            }
        }
    }
}

void init_all_flags(flags_t *flags, int ac, char **av)
{
    flags->dash_l = 0;
    flags->dash_R = 0;
    flags->dash_r = 0;
    flags->dash_t = 0;
    switch_for_flags(av, ac, flags);
}

char **check_argument(int ac, char **av)
{
    int y = 0;
    char **argument = malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++)
        argument[i] = malloc(sizeof(char) * 100);
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            argument[y] = av[i];
            y++;
        }
    }
    return (argument);
}
