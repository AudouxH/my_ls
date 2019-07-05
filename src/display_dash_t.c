/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** display_dash_t.c
*/

#include "../include/my_ls.h"

void tried_list(char *filepath)
{
    struct stat s;
    struct tm *time;
    char *buffer = ctime(&s.st_mtime) + 4;

    stat(filepath, &s);
    write (1, buffer, my_strlen(buffer) - 6);
    write (1, " ", 1);
}

void display_t_(char *filepath)
{
    struct dirent *fichierLU = NULL;
    DIR *repo = NULL;

    repo = opendir(filepath);
    while ((fichierLU = readdir(repo)) != NULL)
        if (fichierLU->d_name[0] != '.') {
            tried_list(str_cat(filepath, fichierLU->d_name));
            write (1, "\n", 1);
        }
}