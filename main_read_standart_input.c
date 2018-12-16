/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** main_read_standart_output
*/

#include <stdio.h>

char *get_next_line(int fd);

int main(void)
{
    for (char *str = NULL; (str = get_next_line(0)) != NULL;) {
        if (str != NULL)
            printf("%s\n", str);
    }
}