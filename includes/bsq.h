/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-BSQ-philemon.linossier
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_

    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "struct.h"

void my_putchar (char c);
int my_putstr (char *str);
int my_strlen (char *str);
int my_intlen (int z);
int	my_put_nbr (int nb);
int errors (const char *filepath, int fd);
int read_file (const char *filepath);
int free_all (char **map, int **tab, int nb_rows);
int count_rows (char *buffer);
int count_cols (char *buffer);
int jump_first_line (char *buffer);
char **fill_arr (char **map ,char *buffer);
void mem_alloc_2d_array(char *buffer);
void change_loop (char **map, int **tab, int i, int j);
void print_tabint (int **tab, int nb_rows, int nb_cols);
void print_tabchar (char **map, int nb_rows, int nb_cols);
void change_to_nb (char **map, int **tab, int nb_rows, int nb_cols);
int **mem_alloc_2d_tab(char **map, char *buffer);
void find_square (char **map, int **tab, int nb_rows, int nb_cols);
void find_loop (int **tab, int i, int j);
void check_sides (int **tab, int i, int j);
void disp_square (int **tab, char **map, int nb_rows, int nb_cols);
char **change_to_x (char **map, value_t *nb);
int find_max (int **tab, value_t *nb, int i, int j);
int create_patern (char **av);
int my_getnbr(char *str);
void fill_patern (int size, char **av, char *str);
int arg_errors (char **av);


#endif /* !BSQ_H_ */
