/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:56:09 by ttran             #+#    #+#             */
/*   Updated: 2018/01/19 14:56:10 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include <libft.h>

typedef struct s_key
{
    char *key;
    int row;
    int column;
    int **arr;
    int startx;
    int starty;
}               t_key;

typedef struct s_rs
{
    int run;
    int n;
    int exits;
    int entrance;
}   t_rs;

typedef struct s_bfs
{
    int x;
    int y;
    struct s_bfs *parent;
}               t_bfs;

typedef struct s_queue
{
    struct s_bfs *node;
    struct s_queue *next;
}               t_queue;

int main(int argc, char **argv);
int dup_check(char *str);
int validmaze(int fd);
int solvemaze(t_key *key);

#endif
