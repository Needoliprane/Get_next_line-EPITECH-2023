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

#define READ_SIZE 1

unsigned int my_len(char const *str)
{
    unsigned int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i]; i++);
    return (i);
}

bool find_char(char const *str, char const c, char const d)
{
    for (unsigned int i = 0; str && str[i]; i++) {
        if (c == str[i])
            return (true);
        if (d == str[i])
            return (true);
    }
    return (false);
}

char *my_starcat_gnl(char *tmp_ret, char *buf, unsigned int *i, int fd)
{
    char *tmp = malloc(sizeof(char) * (my_len(tmp_ret) + my_len(buf + *i) + 1));
    unsigned int cpy = 0;

    if (tmp != NULL)
        tmp[my_len(tmp_ret) + my_len(buf + *i)] = tmp[0] = '\0';
    for (; tmp_ret && tmp && tmp_ret[cpy]; cpy++)
        tmp[cpy] = tmp_ret[cpy];
    for (; tmp && buf[*i] && buf[*i] != '\n'; *i += 1, cpy++)
        tmp[cpy] = buf[*i];
    (tmp != NULL) ? (tmp[cpy] = '\0') : 0 ;
    *i = (buf[*i] == '\0' || buf[*i] == EOF) ? 0 : *i + 1;
    for (unsigned int k = 0; buf && tmp_ret && k <= READ_SIZE; k++) {
        (fd == 0) ? (buf[k] = '\0'), (tmp_ret[k] = '\0') : (tmp_ret[k] = '\0');
    }
    free(tmp_ret);
    return (tmp);
}

char *get_next_line(int fd)
{
    static char buf[READ_SIZE + 1];
    char *tmp = malloc(sizeof(char) * (READ_SIZE + 1));
    static unsigned int i = 0;

    if (tmp == NULL)
        return (NULL);
    buf[READ_SIZE] = tmp[READ_SIZE] = tmp[0] = buf[0] = '\0';
    if (i != 0) {
        if (find_char(buf + i, '\n', EOF) == true)
            return (my_starcat_gnl(tmp, buf, &i, fd));
        tmp = my_starcat_gnl(tmp, buf, &i, fd);
    }
    for (int len = 0; (len = read(fd, buf, READ_SIZE)) > 0; ) {
        if (len == -1)
            return (NULL);
        else if (find_char(buf, '\n', '\0') == true)
            return (my_starcat_gnl(tmp, buf, &i, fd));
        else
            tmp = my_starcat_gnl(tmp, buf, &i, fd);
    }
    return (NULL);
}
