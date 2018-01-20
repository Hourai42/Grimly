/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:56:09 by ttran             #+#    #+#             */
/*   Updated: 2018/01/19 14:56:10 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include <libft.h>

typedef struct s_key
{
    char *key;
    int row;
    int column;
    char *arr;
}               t_key;

int main(int argc, char **argv);
int dup_check(char *str);


#endif
