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

static int	isqueue_empty(t_queue *queue)
{
	if (queue == NULL)
		return (1);
	else
		return (0);
}

static t_bfs	*pop_queue(t_queue **queue)
{
	t_queue		*head;
	t_queue		*fuckhead;

	fuckhead = NULL;
	head = *queue;
	while (head->next != NULL)
	{
		fuckhead = head;
		head = head->next;
	}
	if (fuckhead != NULL)
		fuckhead->next = NULL;
	else
		*queue = NULL;
	return (head->node);
}

static void	push_queue(t_bfs *node, t_queue **queue, t_key *key)
{
	t_queue	*newtail;

	if (key->arr[node->y][node->x] > 0)
	{
		if (*queue == NULL)
		{
			*queue = malloc(sizeof(t_queue));
			(*queue)->next = NULL;
			(*queue)->node = node;
		}
		else
		{
			newtail = malloc(sizeof(t_queue));
			newtail->next = *queue;
			newtail->node = node;
			*queue = newtail;
		}
		key->arr[node->y][node->x] *= -1;
	}
}

t_bfs		*gen_north(t_queue **queue, t_key *key, t_bfs *item)
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

t_bfs		*gen_west(t_queue **queue, t_key *key, t_bfs *item)
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

t_bfs		*gen_east(t_queue **queue, t_key *key, t_bfs *item)
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

t_bfs		*gen_south(t_queue **queue, t_key *key, t_bfs *item)
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

t_bfs		*bfs(t_bfs *entrance, t_key *key)
{
	t_queue	*queue;
	t_bfs	*item;
	int		i;
	t_bfs	*done;

	i = 0;
	queue = NULL;
	push_queue(entrance, &queue, key);
	while (isqueue_empty(queue) != 1)
	{
		item = pop_queue(&queue);
		while (i < 4)
		{
			if ((done = gen_succ(&queue, i, key, item)) != NULL)
				return (done);
			i++;
		}
		i = 0;
	}
	return (NULL);
}

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

void		print_maze(t_key *key, t_bfs *solution)
{
	int		i;
	int		n;
	int		steps;
	int		neg;

	neg = ((int)key->key[1]) * -1;
	steps = 0;
	i = 0;
	n = 0;
	ft_putnbr(key->row);
	ft_putchar('x');
	ft_putnbr(key->column);
	ft_putstr(key->key);
	write(1, "\n", 1);
	steps = fixmap(key, solution, steps);
	while (n < key->row)
	{
		while (i < key->column)
		{
			if (key->arr[n][i] == neg)
				key->arr[n][i] = key->key[1];
			ft_putchar(key->arr[n][i]);
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		n++;
	}
	ft_putstr("RESULT IN ");
	ft_putnbr(steps);
	ft_putstr(" STEPS!\n");
}

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
