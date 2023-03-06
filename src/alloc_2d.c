/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-BSQ-philemon.linossier
** File description:
** alloc_2d
*/

#include "../includes/bsq.h"

void print_tabchar (char **map, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            my_putchar(map[i][j]);
        }
        my_putchar('\n');
    }
}

char **fill_arr (char **map ,char *buffer)
{
    int str_i = jump_first_line(buffer);
    int x = 0;
    int y = 0;

    while (buffer[str_i] != '\0') {
        if (buffer[str_i] == '\n') {
            map[x][y] = buffer[str_i];
            map[x][y + 1] = '\0';
            x++;
            y = 0;
        } else {
            map[x][y] = buffer[str_i];
            y++;
        }
        str_i++;
    }
    return map;
}

void mem_alloc_2d_array(char *buffer)
{
    int nb_rows = count_rows(buffer);
    int nb_cols = count_cols(buffer);

    char **map = (char**)malloc((nb_rows + 1) * sizeof(char*));
    for (int i = 0; i < nb_rows; i++) {
        map[i] = (char*)malloc((nb_cols + 2) * sizeof(char));
    }
    map[nb_rows] = NULL;
    fill_arr(map, buffer);
    mem_alloc_2d_tab(map, buffer);
}
