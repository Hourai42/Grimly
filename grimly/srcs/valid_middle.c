/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_middle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 18:34:15 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 18:34:23 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int		valid_middle(t_key *key, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (i == 0 || i == key->column - 1)
		{
			if (line[i] != key->key[0] && line[i] != key->key[3]
			&& line[i] != key->key[4])
				return (-1);
		}
		else
		{
			if (line[i] != key->key[0] && line[i] != key->key[1]
			&& line[i] != key->key[3] && line[i] != key->key[4])
				return (-1);
		}
		i++;
	}
	return (0);
}
