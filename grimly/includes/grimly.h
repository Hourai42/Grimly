/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:56:09 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 13:13:12 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include <libft.h>

typedef struct		s_key
{
	char			*key;
	int				row;
	int				column;
	int				**arr;
	int				startx;
	int				starty;
}					t_key;

typedef struct		s_rs
{
	int				run;
	int				n;
	int				exits;
	int				entrance;
}					t_rs;

typedef struct		s_bfs
{
	int				x;
	int				y;
	struct s_bfs	*parent;
}					t_bfs;

typedef struct		s_queue
{
	struct s_bfs	*node;
	struct s_queue	*prev;
	struct s_queue	*head;
}					t_queue;
void				print_check(t_key *key);
void				print_maze(t_key *key, t_bfs *solution);
int					fixmap(t_key *key, t_bfs *solution, int steps);
int					ft_matoi(char **line);
int					dup_check(char *str);
int					validmaze(int fd);
int					valid_middle(t_key *key, char *line);
void				value_checker(char c, t_key *key, int x, t_rs *s);
int					main(int argc, char **argv);
int					solvemaze(t_key *key);
void				push_queue(t_bfs *node, t_queue **queue, t_key *key);
t_bfs				*pop_queue(t_queue **queue);
int					isqueue_empty(t_queue *queue);
t_bfs				*bfs(t_bfs *entrance, t_key *key);
t_bfs				*gen_succ(t_queue **queue, int direction,
					t_key *key, t_bfs *item);
#endif
