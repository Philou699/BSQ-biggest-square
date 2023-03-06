/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-BSQ-philemon.linossier
** File description:
** change_values
*/

#include "../includes/bsq.h"

void print_tabint (int **tab, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            my_put_nbr(tab[i][j]);
        }
        my_putchar('\n');
    }
}

void change_loop (char **map, int **tab, int i, int j)
{
    if (map[i][j] == 'o') {
        tab[i][j] = 0;
    }
    if (map[i][j] == '.') {
        tab[i][j] = 1;
    }
}

void change_to_nb (char **map, int **tab, int nb_rows, int nb_cols)
{
    int i;
    int j;
    for ( i = 0; i < nb_rows; i++) {
        for ( j = 0; j < nb_cols; j++) {
            change_loop(map, tab, i, j);
        }
    }
}

int **mem_alloc_2d_tab(char **map, char *buffer)
{
    int nb_rows = count_rows(buffer);
    int nb_cols = count_cols(buffer);

    int **tab = (int **)malloc((nb_rows + 1) * sizeof(int*));
    for (int i = 0; i < nb_rows; i++) {
        tab[i] = (int*)malloc((nb_cols + 1) * sizeof(int));
    }
    tab[nb_rows] = NULL;
    change_to_nb(map, tab, nb_rows, nb_cols);
    find_square(map, tab, nb_rows, nb_cols);
    free(buffer);
    return tab;
}
