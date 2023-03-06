/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-BSQ-philemon.linossier
** File description:
** utils
*/

#include "../includes/bsq.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return 0;
}

int my_strlen(char *str)
{
    int a = 0;
    while (str[a] != '\0'){
        a++;
    }
    return (a);
}

int my_intlen(int z)
{
    int b = 0;
    int c = 0;
    while (z > 0) {
        b = z % 10;
        z = z - b ;
        z = z / 10 ;
        c++;
    }
    return (c);
}

int	my_put_nbr(int nb)
{
    int	a;

    if (nb < 0){
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            a = (nb % 10);
            nb = (nb - a) / 10;
            my_put_nbr(nb);
            my_putchar(48 + a);
            } else {
            my_putchar(48 + nb % 10);
        }
    }
    return 0;
}
