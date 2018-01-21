/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvemaze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:10:33 by ttran             #+#    #+#             */
/*   Updated: 2018/01/19 18:10:34 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int			solvemaze(t_key *key)
{
	t_bfs	*entrance;
	t_bfs	*solution;

	solution = malloc(sizeof(t_bfs));
	entrance = malloc(sizeof(t_bfs));
	entrance->x = key->startx;
	entrance->y = key->starty;
	entrance->parent = NULL;
	if ((solution = bfs(entrance, key)) == NULL)
		return (-1);
	print_maze(key, solution);
	return (0);
}
