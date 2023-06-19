/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:15:38 by sozbayra          #+#    #+#             */
/*   Updated: 2023/06/19 19:16:34 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_check_valid_path(int x_of_p, int y_of_p, t_checker *checker)
{
	ft_check_valid_path_extension(checker, (x_of_p + 1), y_of_p);
	ft_check_valid_path_extension(checker, x_of_p, (y_of_p - 1));
	ft_check_valid_path_extension(checker, (x_of_p - 1), y_of_p);
	ft_check_valid_path_extension(checker, x_of_p, (y_of_p + 1));
}

void	ft_check_last_column(t_checker *checker, char **map, int row, int *i)
{
	while (map[row - 2][*i] && map[row - 2][*i] != '\n')
	{
		if (checker->x == 1 && map[row - 2][*i] == '1')
		{
			(*i)++;
		}
		else
		{
			checker->x = -1;
			break ;
		}
	}
}

void	ft_check_side_walls(t_checker *checker, char **map, int row)
{
	while (row >= 0)
	{
		if (map[row][0] == '1' && map[row][checker->rectangle - 1] == '1')
		{
			row--;
		}
		else
		{
			checker->y = -1;
			break ;
		}
	}
}

void	ft_check_first_column(t_checker *checker, char **map, int *i)
{
	while (map[0][*i] && map[0][*i] != '\n')
	{
		if (checker->x == 1 && map[0][*i] == '1')
		{
			(*i)++;
		}
		else
		{
			checker->x = -1;
			break ;
		}
	}
}

void	ft_check_walls(t_checker *checker)
{
	int		i;
	int		row;
	char	**map;

	i = 0;
	row = checker->rows;
	checker->x = 1;
	checker->y = 1;
	map = checker->map;
	ft_check_last_column(checker, map, row, &i);
	row -= 3;
	ft_check_side_walls(checker, map, row);
	i = 0;
	ft_check_first_column(checker, map, &i);
}
