/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:21:30 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 16:21:31 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int			fixmap(t_key *key, t_bfs *solution, int steps)
{
	solution = solution->parent;
	while (solution->parent != NULL)
	{
		key->arr[solution->y][solution->x] = key->key[2];
		solution = solution->parent;
		steps++;
	}
	key->arr[solution->y][solution->x] = key->key[3];
	return (steps);
}
