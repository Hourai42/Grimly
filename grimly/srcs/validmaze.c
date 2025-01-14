/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmaze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:24:49 by ttran             #+#    #+#             */
/*   Updated: 2018/01/19 16:28:36 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

/*
** Validates the key required to read the labyrinth. Invalid key returns null.
** legend[0] == The "full" character
** legend[1] == The "empty" character
** legend[2] == The character's "path"
** legend[3] == The character's "entered labyrinth"
** legend[4] == The character's "exit labyrinth"
*/

static int	v_mapkey(char *line, t_key *key)
{
	char	*legend;
	int		i;

	i = 0;
	key->row = ft_matoi(&line);
	if (key->row < 3 || *line != 'x')
		return (-1);
	line++;
	key->column = ft_matoi(&line);
	if (key->column < 3 || (key->row * key->column > 1000000000))
		return (-1);
	legend = malloc(sizeof(char) * 6);
	while (i < 5 && *line)
	{
		legend[i++] = *line;
		line++;
	}
	legend[i] = '\0';
	if (*line != '\0' || i != 5)
		return (-1);
	key->key = legend;
	return (0);
}

static int	valid_row(t_key *key, char *line, t_rs *s)
{
	int		i;

	i = 0;
	if (s->n == 0 || s->n == key->row - 1)
		while (line[i])
		{
			if (line[i] != key->key[0] && line[i] != key->key[3]
			&& line[i] != key->key[4])
				return (-1);
			i++;
		}
	else
	{
		if (valid_middle(key, line) == -1)
			return (-1);
	}
	return (0);
}

static int	v_rc(char *line, t_key *key, t_rs *s)
{
	int		*row;
	int		i;

	i = 0;
	if (s->run == key->row + 1)
	{
		if (line[0] == '\0')
			return (0);
		else
			return (-1);
	}
	row = malloc(sizeof(int) * key->column);
	while (line[i] && i < key->column)
	{
		row[i] = line[i];
		value_checker(line[i], key, i, s);
		i++;
	}
	if (line[i] != '\0' || i != key->column)
		return (-1);
	if (valid_row(key, line, s) == -1)
		return (-1);
	key->arr[s->n++] = row;
	return (0);
}

/*
** This will check if the map is valid. It'll call a function to check
** the first line of the given map, the map reader, and return a string of the
** key needed to read the maze. The rest of the lines validate the
** rest of the labyrinth. The reason for run == key->rc + 1 is because of
** how GNL works. If it reads everything, it'll return 1 then read one more
** time and return 0.
*/

static int	valid_line(char *line, t_key *key, t_rs *s)
{
	if (s->run == 0)
	{
		if (v_mapkey(line, key) == -1 || dup_check(key->key) == 1)
			return (-1);
		s->run++;
	}
	else
	{
		if (s->run == 1)
		{
			key->arr = (int **)malloc(sizeof(int *) * key->row);
			s->exits = 0;
			s->entrance = 0;
		}
		if (v_rc(line, key, s) == -1)
			return (-1);
		s->run++;
	}
	return (0);
}

/*
** This will validate the maze, line by line, then parse it into a 2D array.
** The struct rs is used to replace the usage of static variables.
*/

int			validmaze(int fd)
{
	char	*line;
	t_key	*key;
	t_rs	*s;

	line = 0;
	s = malloc(sizeof(t_rs));
	s->run = 0;
	s->n = 0;
	key = malloc(sizeof(t_key));
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &line) > 0)
		if (valid_line(line, key, s) == -1)
			return (-1);
	if (s->exits < 1 || s->entrance != 1)
		return (-1);
	if (solvemaze(key) == -1)
		return (-1);
	return (0);
}
