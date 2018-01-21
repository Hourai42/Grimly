/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:21:53 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 16:21:54 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	push_queue(t_bfs *node, t_queue **queue, t_key *key)
{
	t_queue	*newtail;

	if (key->arr[node->y][node->x] > 0)
	{
		if (*queue == NULL)
		{
			*queue = malloc(sizeof(t_queue));
			(*queue)->prev = NULL;
			(*queue)->node = node;
			(*queue)->head = *queue;
		}
		else
		{
			newtail = malloc(sizeof(t_queue));
			newtail->head = (*queue)->head;
			(*queue)->prev = newtail;
			newtail->prev = NULL;
			newtail->node = node;
			*queue = newtail;
		}
		key->arr[node->y][node->x] = 0;
	}
}
