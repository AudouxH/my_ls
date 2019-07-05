/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** my_ls.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>


typedef struct flags_s
{
    int dash_l;
    int dash_R;
    int dash_r;
    int dash_t;
} flags_t;

int my_strlen(char const *str);
void display_few_argv(char **argument, flags_t *flags);
int check_if_one_argv(char **argument, flags_t *flags);
int switch_for_flags(char **av, int ac, flags_t *flags);
void init_all_flags(flags_t *flags, int ac, char **av);
char *str_cat(char *filepath, char *filepath_2);
char **check_argument(int ac, char **av);
void display_one_with_dash(flags_t *flags);
void display_l(char *filepath);
void display_t_(char *filepath);
void display_r(char *filepath);
void display_permission(char *filepath);
void display_argv(char *filepath);
void display_big_r(char *filepath);
int my_put_nbr(int nb);