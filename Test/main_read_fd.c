/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** main_read_fd
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *get_next_line(int fd);

int get_fd(char const *str)
{
    int fd = 0;

    if (str == NULL)
        return (-1);
    fd = open(str, O_RDONLY);
    return (fd);
}

int main(int ac, char **av)
{
    int fd = get_fd(av[1]);

    (void)ac;
    if (fd == -1) {
        printf("Error : file doesn't exist or No arguments\n");
        return (84);
    }
    for (char *tmp = NULL; (tmp = get_next_line(fd)) != NULL;) {
        if (tmp != NULL && tmp[0] != '\0') {
            printf("%s\n", tmp);
            free(tmp);
            tmp = NULL;
        } else {
            printf("NULL\n");
        }
    }
    close(fd);
    return (0);
}
