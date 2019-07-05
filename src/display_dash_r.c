/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** display_dash_r.c
*/

#include "../include/my_ls.h"

void display_r(char *filepath)
{
    struct dirent *fichierLU = NULL;
    DIR *repo = NULL;
    int y = 0;
    char **rotate_filepath = malloc(sizeof(char *) * 100);

    for (int i = 0; i < 100; i++)
        rotate_filepath[i] = malloc(sizeof(char) * 100);
    repo = opendir(filepath);
    while ((fichierLU = readdir(repo)) != NULL)
        if (fichierLU->d_name[0] != '.') {
            rotate_filepath[y] = fichierLU->d_name;
            y++;
        }
    while (y > 0) {
        write (1, rotate_filepath[y - 1], my_strlen(rotate_filepath[y - 1]));
        write (1, "\n", 1);
        y--;
    }
}