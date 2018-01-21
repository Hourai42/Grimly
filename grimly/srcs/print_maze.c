/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:21:21 by ttran             #+#    #+#             */
/*   Updated: 2018/01/20 16:21:22 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

static void	print_legend(t_key *key)
{
	ft_putnbr(key->row);
	ft_putchar('x');
	ft_putnbr(key->column);
	ft_putstr(key->key);
	write(1, "\n", 1);
}

static void	print_steps(int steps)
{
	ft_putstr("RESULT IN ");
	ft_putnbr(steps);
	ft_putstr(" STEPS!\n");
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
	print_legend(key);
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
	print_steps(steps);
}
