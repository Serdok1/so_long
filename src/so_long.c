/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:38:22 by sozbayra          #+#    #+#             */
/*   Updated: 2023/06/19 19:30:27 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_search_exit_coordinates(char **map, t_checker *checker, int row,
		int *i)
{
	while (*i < checker->rectangle)
	{
		if (map[row][*i] == 'E')
		{
			checker->exit_y = row;
			checker->exit_x = *i;
			break ;
		}
		(*i)++;
	}
}

void	ft_find_exit(char **map, t_checker *checker)
{
	int	row;
	int	i;

	row = checker->rows - 2;
	checker->exit_x = -1;
	checker->exit_y = -1;
	while (row >= 0)
	{
		i = 0;
		ft_search_exit_coordinates(map, checker, row, &i);
		if (checker->exit_x != -1 && checker->exit_y != -1)
		{
			break ;
		}
		row--;
	}
	if (checker->exit_x != -1 && checker->exit_y != -1)
	{
		ft_check_valid_path(checker->player_x, checker->player_y, checker);
	}
}

void	ft_search_player_coordinates(char **map, t_checker *checker, int row,
		int *i)
{
	while (*i < checker->rectangle)
	{
		if (map[row][*i] == 'P')
		{
			checker->player_y = row;
			checker->player_x = *i;
			break ;
		}
		(*i)++;
	}
}

void	ft_find_player(char **map, t_checker *checker)
{
	int	row;
	int	i;

	row = checker->rows - 2;
	checker->player_x = -1;
	checker->player_y = -1;
	while (row >= 0)
	{
		i = 0;
		ft_search_player_coordinates(map, checker, row, &i);
		if (checker->player_x != -1 && checker->player_y != -1)
		{
			break ;
		}
		row--;
	}
	if (checker->player_x != -1 && checker->player_y != -1)
	{
		ft_find_exit(map, checker);
	}
}

int	main(void)
{
	int fd;
	int sd;
	t_checker checker;

	fd = open("map.ber", O_RDWR);
	sd = open("map.ber", O_RDWR);
	ft_read_map(fd, &checker);
	close(fd);
	if (checker.rectangle != -1)
	{
		//If map is not rectangular,missing column count will cause segmentation error.
		ft_convert_to_matrix(sd, &checker);
		close(sd);
	}
	ft_check_walls(&checker);
	if (checker.x == 1 && checker.y == 1)
		ft_find_player(checker.map, &checker);
	checker.mlx = mlx_init();
	checker.win = mlx_new_window(checker.mlx, checker.rectangle * 48,
			(checker.rows - 1) * 48, "So Long by Sina");
	if (checker.collectibles >= 1 && checker.exit >= 1)
		ft_draw_map(&checker, checker.map);
	printf("rows:%d\n", checker.rows);
	printf("rectangle:%d\n", checker.rectangle);
	printf("x:%d\n", checker.x);
	printf("y:%d\n", checker.y);
	printf("collectibles:%d\n", checker.collectibles);
	printf("exit:%d\n", checker.exit);
	printf("player_x:%d player_y:%d\n", checker.player_x, checker.player_y);

	/* system("leaks a.out"); */
}