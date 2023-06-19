/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:40:20 by sozbayra          #+#    #+#             */
/*   Updated: 2023/06/19 18:25:46 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_check_valid_path_extension(t_checker *checker, int x_of_p,
		int y_of_p)
{
	if (checker->temp_map[y_of_p][x_of_p] != '1'
		&& checker->temp_map[y_of_p][x_of_p] != '.')
	{
		if (checker->temp_map[y_of_p][x_of_p] == 'E')
		{
			checker->exit++;
			checker->temp_map[y_of_p][x_of_p] = '.';
		}
		else if (checker->temp_map[y_of_p][x_of_p] == 'C')
		{
			checker->collectibles++;
			checker->temp_map[y_of_p][x_of_p] = '.';
		}
		else
		{
			checker->temp_map[y_of_p][x_of_p] = '.';
			ft_check_valid_path(x_of_p, y_of_p, checker);
		}
	}
}
