/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-BSQ-philemon.linossier
** File description:
** bigest_square
*/

#include "../includes/bsq.h"

char **change_to_x (char **map, value_t *nb)
{
    int a;
    int z;
    for ( a = (nb->my_x); a >= nb->my_x - (nb->max - 1); a--) {
        for ( z = (nb->my_y); z >= nb->my_y - (nb->max - 1); z--) {
            map[a][z] = 'x';
        }
    }
    return map;
}

int find_max (int **tab, value_t *nb, int i, int j)
{
    if (tab[i][j] > nb->max) {
        nb->max = tab[i][j];
        nb->my_x = i;
        nb->my_y = j;
    }
    return nb->max;
}

void disp_square (int **tab, char **map, int nb_rows, int nb_cols)
{
    value_t nb;

    nb.max = 0;
    nb.my_x = 0;
    nb.my_y = 0;
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            nb.max = find_max(tab, &nb, i, j);
        }
    }

    map = change_to_x(map, &nb);
    print_tabchar(map, nb_rows, nb_cols);
    free_all(map, tab, nb_rows);
}
