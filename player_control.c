/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:46:46 by sozbayra          #+#    #+#             */
/*   Updated: 2023/06/19 16:46:49 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_handle_right(t_checker *checker)
{
	ft_exit_control(checker, checker->player_y, (checker->player_x + 1));
	ft_control_player_x(checker->player_y, (checker->player_x + 1), +1,
		checker);
}

void	ft_handle_left(t_checker *checker)
{
	ft_exit_control(checker, checker->player_y, (checker->player_x - 1));
	ft_control_player_x(checker->player_y, (checker->player_x - 1), -1,
		checker);
}

void	ft_handle_down(t_checker *checker)
{
	ft_exit_control(checker, (checker->player_y + 1), checker->player_x);
	ft_control_player_y((checker->player_y + 1), checker->player_x, +1,
		checker);
}

void	ft_handle_up(t_checker *checker)
{
	ft_exit_control(checker, (checker->player_y - 1), checker->player_x);
	ft_control_player_y((checker->player_y - 1), checker->player_x, -1,
		checker);
}

int	ft_handle_keys(int keycode, t_checker *checker)
{
	if (keycode == 53)
		ft_exit(checker->mlx, checker->win);
	if (keycode == 13)
	{
		ft_handle_up(checker);
	}
	if (keycode == 1)
	{
		ft_handle_down(checker);
	}
	if (keycode == 0)
	{
		ft_handle_left(checker);
	}
	if (keycode == 2)
	{
		ft_handle_right(checker);
	}
	return (0);
}
