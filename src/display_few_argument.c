/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** display_few_argument.c
*/

#include "../include/my_ls.h"

void display_few_argv_more(char **argument, flags_t *flags)
{
    struct dirent *fichierLU = NULL;
    DIR *repo = NULL;

    for (int i = 0; argument[i][0] != '\0'; i++) {
        write(1, argument[i], my_strlen(argument[i]));
        write(1, ":\n", 2);
        if (flags->dash_l == 1)
            display_l(argument[i]);
        else if (flags->dash_r == 1)
            display_r(argument[i]);
        else if (flags->dash_R == 1)
            display_big_r(argument[i]);
        else if (flags->dash_t == 1)
            display_t_(argument[i]);
        else
            display_argv(argument[i]);
        if (argument[i + 1][0] != '\0')
            write(1, "\n", 1);
    }
}

void display_few_argv(char **argument, flags_t *flags)
{
    struct dirent *fichierLU = NULL;
    DIR *repo = NULL;

    for (int i = 0; argument[i][0] != '\0'; i++) {
        if ((argument[i][0] != '\0') && (argument[i + 1][0] != '\0')) {
            display_few_argv_more(argument, flags);
            return;
        }
        if (flags->dash_l == 1)
            display_l(argument[i]);
        else if (flags->dash_r == 1)
            display_r(argument[i]);
        else if (flags->dash_R == 1)
            display_big_r(argument[i]);
        else if (flags->dash_t == 1)
            display_t_(argument[i]);
        else
            display_argv(argument[i]);
        if (argument[i + 1][0] != '\0')
            write(1, "\n", 1);
    }
}

void display_argv(char *filepath)
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