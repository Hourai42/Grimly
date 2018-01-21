/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:21:58 by ttran             #+#    #+#             */
/*   Updated: 2018/01/21 15:40:05 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_bfs		*pop_queue(t_queue **queue)
{
	t_queue	*fuckhead;

	fuckhead = NULL;
	if ((*queue)->head->prev == NULL)
	{
		fuckhead = *queue;
		(*queue)->head = NULL;
		*queue = NULL;
	}
	else
	{
		fuckhead = (*queue)->head;
		(*queue)->head = (*queue)->head->prev;
	}
	return (fuckhead->node);
}
