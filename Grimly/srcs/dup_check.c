/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:37:03 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 13:16:27 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int	dup_check(char *str)
{
	char	arr[128];
	int		i;

	i = 0;
	while (i < 128)
		arr[i++] = 0;
	i = 0;
	while (str[i])
	{
		if (!(arr[(int)str[i]]))
			arr[(int)str[i]] = str[i];
		i++;
	}
	while (*str)
	{
		if (arr[(int)*str])
		{
			arr[(int)*str] = 0;
			str++;
		}
		else
			return (1);
	}
	return (0);
}
