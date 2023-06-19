/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:35:30 by sozbayra          #+#    #+#             */
/*   Updated: 2023/06/19 19:35:34 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_exit(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	exit(0);
}

void	ft_exit_control(t_checker *checker, int player_y, int player_x)
{
	if (checker->map[player_y][player_x] == 'E' && checker->collectibles == 0)
		ft_exit(checker->mlx, checker->win);
}

void	ft_control_player_y(int player_y, int player_x, int indicator,
		t_checker *checker)
{
	if (checker->map[player_y][player_x] == '0'
		|| checker->map[player_y][player_x] == 'C')
	{
		if (checker->map[player_y][player_x] == 'C')
			checker->collectibles--;
		checker->map[player_y][player_x] = 'P';
		checker->map[checker->player_y][checker->player_x] = '0';
		checker->player_y += indicator;
		ft_generate_images(checker);
	}
}

void	ft_control_player_x(int player_y, int player_x, int indicator,
		t_checker *checker)
{
	if (checker->map[player_y][player_x] == '0'
		|| checker->map[player_y][player_x] == 'C')
	{
		if (checker->map[player_y][player_x] == 'C')
			checker->collectibles--;
		checker->map[player_y][player_x] = 'P';
		checker->map[checker->player_y][checker->player_x] = '0';
		checker->player_x += indicator;
		ft_generate_images(checker);
	}
}
