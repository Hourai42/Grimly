/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:23:21 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 16:23:22 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

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
