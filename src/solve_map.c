/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-BSQ-philemon.linossier
** File description:
** solve_map
*/

#include "../includes/bsq.h"

int find_min (int **tab, int i, int j)
{
    int min = tab[i - 1][j];

    if (tab[i - 1][j - 1] < min) {
        min = tab[i - 1][j - 1];
    }
    if (tab[i][j - 1] < min) {
        min = tab[i][j - 1];
    }
    return min;
}

void check_sides (int **tab, int i, int j)
{
    int min = find_min(tab, i, j);

    if (min != 0) {
        tab[i][j] += min;
    }
}

void find_loop (int **tab, int i, int j)
{
    if (tab[i][j] == 1) {
        check_sides(tab, i, j);
    } else {
        tab[i][j] = tab[i][j];
    }
}

void find_square (char **map, int **tab, int nb_rows, int nb_cols)
{
    int i;
    int j;

    for ( i = 1; i < nb_rows; i++) {
        for ( j = 1; j < nb_cols; j++) {
            find_loop(tab, i, j);
        }
    }
    disp_square(tab, map, nb_rows, nb_cols);
}
