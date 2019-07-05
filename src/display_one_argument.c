/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** display_one_argument.c
*/

#include "../include/my_ls.h"

int check_if_one_argv(char **argument, flags_t *flags)
{
    if (argument[0][0] == '\0') {
        display_one_with_dash(flags);
        return (1);
    }
}

void display_one(char *filepath)
{
    struct dirent *fichierLU = NULL;
    DIR *repo = NULL;

    repo = opendir(filepath);
    while ((fichierLU = readdir(repo)) != NULL)
        if (fichierLU->d_name[0] != '.') {
            write (1, fichierLU->d_name, my_strlen(fichierLU->d_name));
            write (1, "\n", 1);
        }
}

void display_one_with_dash(flags_t *flags)
{
    if (flags->dash_r == 1)
        display_r(".");
    else if (flags->dash_l == 1)
        display_l(".");
    else if (flags->dash_R == 1)
        display_big_r(".");
    else if (flags->dash_t == 1)
        display_t_(".");
    else
        display_one(".");
}