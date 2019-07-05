/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** display_dash_bigr.c
*/

#include "../include/my_ls.h"

void display_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        write (1, tab[i], my_strlen(tab[i]));
        write (1, "\n", 1);
    }
}

char *str_cat(char *filepath, char *filepath_2)
{
    char *file_end = malloc(my_strlen(filepath) + my_strlen(filepath_2) + 2);
    int y = 0;

    for (int i = 0; filepath[i] != '\0'; i++) {
        file_end[y] = filepath[i];
        y++;
    }
    if (file_end[y - 1] != '/') {
    file_end[y] = '/';
    y++;
    }
    for (int z = 0; filepath_2[z] != '\0'; z++) {
        file_end[y] = filepath_2[z];
        y++;
    }
    file_end[y] = '\0';
    return (file_end);
}

void display_big_r(char *filepath)
{
    struct dirent *fichierLU = NULL;
    DIR *repo = NULL;
    int y = 0;
    char *filepath2;
    char **directory = malloc(sizeof(char *) * 100);

    for (int i = 0; i < 100; i++)
        directory[i] = malloc(100);
    if ((repo = opendir(filepath)) != NULL) {
    write (1, filepath, my_strlen(filepath));
    write (1, ":\n", 2);
    while ((fichierLU = readdir(repo)) != NULL)
        if (fichierLU->d_name[0] != '.') {
            directory[y] = fichierLU->d_name;
            write(1, fichierLU->d_name, my_strlen(fichierLU->d_name));
            write(1, "\n", 1);
            y++;
        }
        directory[y] = NULL;
    for (int z = 0; directory[z] != NULL ; z++) {
        if (opendir(directory[z]) != NULL) {
            write (1, "\n", 1);
            filepath2 = str_cat(filepath, directory[z]);
            display_big_r(filepath2);
        }
    }
    }
}