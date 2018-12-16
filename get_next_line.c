/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** get_next_line
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define SIZE 1

unsigned int my_strlen(char const *str)
{
    unsigned int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i]; i++);
    return (i);
}

bool find_char(char const *str, char c)
{
    for (unsigned int i = 0; str && str[i]; i++) {
        if (c == str[i])
            return (true);
    }
    return (false);
}

char *my_starcat_gnl(char *s1, char *s2, unsigned int *i, int fd)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2 + *i) + 1));
    unsigned int copy = 0;

    if (tmp != NULL)
        tmp[my_strlen(s1) + my_strlen(s2 + *i)] = tmp[0] = '\0';
    for (int j = 0; s1 && tmp && s1[j]; j++, copy++)
        tmp[copy] = s1[j];
    for (; s2 && tmp && s2[*i] != '\0' && s2[*i] != '\n'; *i += 1, copy++)
        tmp[copy] = s2[*i];
    tmp[copy] = '\0';
    *i = (s2[*i] == '\0') ? 0 : *i + 1;
    for (unsigned int k = 0; s2 && s2[k] && s1 && s1[k] && k <= SIZE; k++) {
        if (fd == 0)
            s2[k] = '\0';
        s1[k] = '\0';
    }
    free(s1);
    return (tmp);
}

char *get_next_line(int fd)
{
    static char buffer[SIZE + 1];
    char *tmp = malloc(sizeof(char) * SIZE + 1);
    static unsigned int i = 0;

    if (tmp != NULL)
        buffer[SIZE] = tmp[SIZE] = tmp[0] = buffer[0] = '\0';
    if (tmp && i != 0) {
        if (find_char(buffer + i, '\n') == true)
            return (my_starcat_gnl(tmp, buffer, &i, fd));
        tmp = my_starcat_gnl(tmp, buffer, &i, fd);
    }
    for (int len = 0; tmp && (len = read(fd, buffer, SIZE)) != 0; ) {
        if (len == -1)
            return (NULL);
        else if (find_char(buffer, '\n') == true)
            return (my_starcat_gnl(tmp, buffer, &i, fd));
        else
            tmp = my_starcat_gnl(tmp, buffer, &i, fd);
    }
    return (NULL);
}