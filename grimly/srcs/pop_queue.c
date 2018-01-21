/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:21:58 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 16:21:59 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_bfs	*pop_queue(t_queue **queue)
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
