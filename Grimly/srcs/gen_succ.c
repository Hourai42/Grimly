/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_succ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:32:06 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 16:32:08 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

static t_bfs		*gen_north(t_queue **queue, t_key *key, t_bfs *item)
{
	t_bfs	*fuckyeah;

	if (item->y > 0)
	{
		if (key->arr[item->y - 1][item->x] == key->key[4])
		{
			fuckyeah = malloc(sizeof(t_bfs));
			fuckyeah->parent = item;
			fuckyeah->y = item->y - 1;
			fuckyeah->x = item->x;
			return (fuckyeah);
		}
		else if (key->arr[item->y - 1][item->x] == key->key[1])
		{
			fuckyeah = malloc(sizeof(t_bfs));
			fuckyeah->parent = item;
			fuckyeah->y = item->y - 1;
			fuckyeah->x = item->x;
			push_queue(fuckyeah, queue, key);
		}
	}
	return (NULL);
}

static t_bfs		*gen_west(t_queue **queue, t_key *key, t_bfs *item)
{
	t_bfs	*fuckyeah;

	if (item->x > 0)
	{
		if (key->arr[item->y][item->x - 1] == key->key[4])
		{
			fuckyeah = malloc(sizeof(t_bfs));
			fuckyeah->parent = item;
			fuckyeah->y = item->y;
			fuckyeah->x = item->x - 1;
			return (fuckyeah);
		}
		else if (key->arr[item->y][item->x - 1] == key->key[1])
		{
			fuckyeah = malloc(sizeof(t_bfs));
			fuckyeah->parent = item;
			fuckyeah->y = item->y;
			fuckyeah->x = item->x - 1;
			push_queue(fuckyeah, queue, key);
		}
	}
	return (NULL);
}

static t_bfs		*gen_east(t_queue **queue, t_key *key, t_bfs *item)
{
	t_bfs	*fuckyeah;

	if (item->x < key->column - 1)
	{
		if (key->arr[item->y][item->x + 1] == key->key[4])
		{
			fuckyeah = malloc(sizeof(t_bfs));
			fuckyeah->parent = item;
			fuckyeah->y = item->y;
			fuckyeah->x = item->x + 1;
			return (fuckyeah);
		}
		else if (key->arr[item->y][item->x + 1] == key->key[1])
		{
			fuckyeah = malloc(sizeof(t_bfs));
			fuckyeah->parent = item;
			fuckyeah->y = item->y;
			fuckyeah->x = item->x + 1;
			push_queue(fuckyeah, queue, key);
		}
	}
	return (NULL);
}

static t_bfs		*gen_south(t_queue **queue, t_key *key, t_bfs *item)
{
	t_bfs	*fuckyeah;

	if (item->y < key->row - 1)
	{
		if (key->arr[item->y + 1][item->x] == key->key[4])
		{
			fuckyeah = malloc(sizeof(t_bfs));
			fuckyeah->parent = item;
			fuckyeah->y = item->y + 1;
			fuckyeah->x = item->x;
			return (fuckyeah);
		}
		else if (key->arr[item->y + 1][item->x] == key->key[1])
		{
			fuckyeah = malloc(sizeof(t_bfs));
			fuckyeah->parent = item;
			fuckyeah->y = item->y + 1;
			fuckyeah->x = item->x;
			push_queue(fuckyeah, queue, key);
		}
	}
	return (NULL);
}

t_bfs		*gen_succ(t_queue **queue, int direction, t_key *key, t_bfs *item)
{
	t_bfs	*done;

	if (direction == 0)
	{
		if ((done = gen_north(queue, key, item)) != NULL)
			return (done);
	}
	else if (direction == 1)
	{
		if ((done = gen_west(queue, key, item)) != NULL)
			return (done);
	}
	else if (direction == 2)
	{
		if ((done = gen_east(queue, key, item)) != NULL)
			return (done);
	}
	else
	{
		if ((done = gen_south(queue, key, item)) != NULL)
			return (done);
	}
	return (NULL);
}
