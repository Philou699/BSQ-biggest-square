/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-BSQ-philemon.linossier
** File description:
** main
*/

#include "../includes/bsq.h"

int free_all (char **map, int **tab, int nb_rows)
{
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);

    for (int i = 0; i < nb_rows; i++) {
        free(tab[i]);
    }
    free(tab);
    return 0;
}

int main (int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return 84;
    if (ac == 2) {
        if (read_file(av[1]) == 84)
            return 84;
    }
    if (ac == 3) {
        if (create_patern(av) == 84)
            return 84;
    }
    return 0;
}
