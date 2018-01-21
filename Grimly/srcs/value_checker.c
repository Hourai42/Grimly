/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:20:35 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 16:20:36 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	value_checker(char c, t_key *key, int x, t_rs *s)
{
	int		y;

	y = s->run - 1;
	if (c == key->key[3])
	{
		s->entrance++;
		key->startx = x;
		key->starty = y;
	}
	else if (c == key->key[4])
		s->exits++;
}
