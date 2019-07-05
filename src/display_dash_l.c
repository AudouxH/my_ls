/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** display_dash_l.c
*/

#include "../include/my_ls.h"

void display_permission(char *filepath)
{
    struct stat s;

    stat(filepath, &s);
    write(1,((S_ISDIR(s.st_mode)) ? "d" : "-"), 1);
    write(1,((s.st_mode & S_IRUSR) ? "r" : "-"), 1);
    write(1,((s.st_mode & S_IWUSR) ? "w" : "-"), 1);
    write(1,((s.st_mode & S_IXUSR) ? "x" : "-"), 1);
    write(1,((s.st_mode & S_IWGRP) ? "w" : "-"), 1);
    write(1,((s.st_mode & S_IXGRP) ? "x" : "-"), 1);
    write(1,((s.st_mode & S_IRGRP) ? "r" : "-"), 1);
    write(1,((s.st_mode & S_IWOTH) ? "w" : "-"), 1);
    write(1,((s.st_mode & S_IXOTH) ? "x" : "-"), 1);
    write(1,((s.st_mode & S_IROTH) ? "r" : "-"), 1);
    write (1, ". ", 2);
}

void displaytime(char *filepath)
{
    struct stat s;
    struct tm *time;
    char *buffer = ctime(&s.st_mtime) + 4;

    stat(filepath, &s);
    write (1, buffer, my_strlen(buffer) - 6);
    write (1, " ", 1);
}

void display_link(char *filepath)
{
    struct stat s;
    struct passwd *pwd;
    struct group *grp;

    stat(filepath, &s);
    my_put_nbr(s.st_nlink);
    pwd = getpwuid(s.st_uid);
    grp = getgrgid(s.st_gid);
    write (1, " ", 1);
    write (1, pwd->pw_name, my_strlen(pwd->pw_name));
    write (1, " ", 1);
    write (1, grp->gr_name, my_strlen(grp->gr_name));
    write (1, " ", 1);
    my_put_nbr(s.st_size);
    write (1, " ", 1);
}

void display_total(char *filepath)
{
    struct dirent *fichierLU = NULL;
    DIR *repo = NULL;
    struct stat s;
    int total = 0;

    repo = opendir(filepath);
    while ((fichierLU = readdir(repo)) != NULL)
        if (fichierLU->d_name[0] != '.') {
            stat(str_cat(filepath, fichierLU->d_name), &s);
            total = total + s.st_blocks;
        }
        write (1, "total ", 6);
        my_put_nbr(total/2);
        write (1, "\n", 1);
}

void display_l(char *filepath)
{
    struct dirent *fichierLU = NULL;
    DIR *repo = NULL;

    repo = opendir(filepath);
    display_total(filepath);
    while ((fichierLU = readdir(repo)) != NULL)
        if (fichierLU->d_name[0] != '.') {
            display_permission(str_cat(filepath, fichierLU->d_name));
            display_link(str_cat(filepath, fichierLU->d_name));
            displaytime(str_cat(filepath, fichierLU->d_name));
            write (1, fichierLU->d_name, my_strlen(fichierLU->d_name));
            write (1, "\n", 1);
        }
}
