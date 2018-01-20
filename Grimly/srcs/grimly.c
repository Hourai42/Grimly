/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:38:43 by ttran             #+#    #+#             */
/*   Updated: 2018/01/19 16:18:34 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

/* Program should be able to handle several labyrinth files. If no arguments are passed, then the program will read a(one) maze from stdin.
 * All errors will be displayed to stderr as "MAP ERROR" followed by a newline. 
 * Watch out for number of new lines expected after every output. */
int main(int argc, char **argv)
{
    char *line;
    int i;

    i = 1;
    line = 0;
    if (argc > 1)
    {
        while (i < argc)
            if (validmaze(open(argv[i++], O_RDONLY)) == -1)
                write(2, "MAP ERROR\n", 10);
    }
    else
    { 
        if (validmaze(0) == -1)
            write(2, "MAP ERROR\n", 10);
    }
    return (0);
}
