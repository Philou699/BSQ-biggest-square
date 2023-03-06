/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-BSQ-philemon.linossier
** File description:
** open_file
*/

#include "../includes/bsq.h"

int jump_first_line (char *buffer)
{
    int len_line1 = 1;

    for (int j = 0; buffer[j] != '\n'; j++) {
        len_line1++;
    }
    return (len_line1);
}

int count_rows (char *buffer)
{
    int nb_rows = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nb_rows++;
    }
    nb_rows -= 1;
    return (nb_rows);
}

int count_cols (char *buffer)
{
    int nb_cols = 0;
    int j = jump_first_line(buffer);

    while (buffer[j] != '\n') {
        nb_cols++;
        j++;
    }
    return (nb_cols);
}

int errors (const char *filepath, int fd)
{
    if (filepath == NULL) {
        my_putstr("Filepath is empty.\n");
        close(fd);
        return (1);
    }
    if (fd == -1) {
        my_putstr("Cannot open the file.\n");
        close(fd);
        return (1);
    }
    return 0;
}

int read_file (const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (errors(filepath, fd) == 1)
        return 84;
    struct stat buff;
    stat(filepath, &buff);
    size_t file_size = buff.st_size;
    char *buffer = malloc(file_size + 1);
    int bytes_read = read(fd, buffer, file_size);
    if (bytes_read == -1) {
        close(fd);
        return (84);
    }
    if (bytes_read == 0) {
        close(fd);
        return (84);
    }
    buffer[file_size] = '\0';
    mem_alloc_2d_array(buffer);
    close(fd);
    return (0);
}
