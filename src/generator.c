/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-BSQ-philemon.linossier
** File description:
** generator
*/

#include "../includes/bsq.h"

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-') {
            sign = sign * (-1);
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        result = result * 10 + str[i] - '0';
        i++;
    }
    result = result * sign;
    return (result);
}

int arg_errors (char **av)
{
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] != '.' && av[2][i] != 'o')
            return 1;
    }
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] < 0 && av[1][i] > 9)
            return 1;
    }
    if (my_strlen(av[2]) == 0)
        return 1;
    return 0;
}

void fill_patern (int size, char **av, char *str)
{
    int j = 0;
    int k = 0;
    int i;

    str[0] = '\n';
    for ( i = 1 ; i < size * size + size ; i++) {
        if (k == size) {
            k = 0;
            str[i] = '\n';
            i++;
        }
        if (av[2][j] == '\0')
            j = 0;
        str[i] = av[2][j];
        j++;
        k++;
    }
    str[i] = '\n';
    str[i + 1] = '\0';
}

int create_patern (char **av)
{
    int size = my_getnbr(av[1]);
    if (size == 0)
        return 84;
    if (arg_errors(av) == 1)
        return 84;

    char *str = malloc(sizeof(char) * size * size + size + 4);

    fill_patern(size, av, str);
    mem_alloc_2d_array(str);
    return 0;
}
