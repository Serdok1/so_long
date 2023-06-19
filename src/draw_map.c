/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:52:48 by sozbayra          #+#    #+#             */
/*   Updated: 2023/06/19 19:42:53 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_generate_last(t_checker *checker)
{
	mlx_put_image_to_window(checker->mlx, checker->win, checker->hero1,
		checker->player_x * 48, checker->player_y * 48);
	mlx_put_image_to_window(checker->mlx, checker->win, checker->exit_img,
		checker->exit_x * 48, checker->exit_y * 48);
}

void	print_coordinates_and_collectibles(int x_x, int y_y, t_checker *checker)
{
	printf("x:%d\ny:%d\n", x_x, y_y);
	printf("collectible_count:%d", checker->collectibles);
}

void	put_image_on_window(t_checker *checker, int x, int y, void *image)
{
	mlx_put_image_to_window(checker->mlx, checker->win, image, x * 48, y * 48);
}

void	ft_generate_images(t_checker *checker)
{
	int	x_x;
	int	y_y;

	y_y = -1;
	while (++y_y < (checker->rows - 1))
	{
		x_x = -1;
		while (checker->map[y_y][++x_x])
		{
			print_coordinates_and_collectibles(x_x, y_y, checker);
			if (checker->map[y_y][x_x] == '1' || checker->map[y_y][x_x] == 'C')
			{
				if (checker->map[y_y][x_x] == '1')
					put_image_on_window(checker, x_x, y_y, checker->wall);
				else if (checker->map[y_y][x_x] != '1'
						&& checker->map[y_y][x_x] != '\n')
					put_image_on_window(checker, x_x, y_y, checker->background);
			}
			if (checker->map[y_y][x_x] == 'C')
				put_image_on_window(checker, x_x, y_y, checker->collectible);
		}
	}
	ft_generate_last(checker);
}

void	ft_draw_map(t_checker *checker, char **map)
{
	void	*hero2;
	void	*hero3;
	int		x;
	int		y;

	x = 48;
	y = 48;
	checker->background = mlx_xpm_file_to_image(checker->mlx,
			"./tiles/grass-tile.xpm", &x, &y);
	checker->exit_img = mlx_xpm_file_to_image(checker->mlx,
			"./tiles/exit_xpm.xpm", &x, &y);
	checker->collectible = mlx_xpm_file_to_image(checker->mlx,
			"./tiles/tube_xpm.xpm", &x, &y);
	checker->wall = mlx_xpm_file_to_image(checker->mlx, "./tiles/wall.xpm", &x,
			&y);
	checker->hero1 = mlx_xpm_file_to_image(checker->mlx, "./tiles/char1.xpm",
			&x, &y);
	hero2 = mlx_xpm_file_to_image(checker->mlx, "./tiles/char2.xpm", &x, &y);
	hero3 = mlx_xpm_file_to_image(checker->mlx, "./tiles/char3.xpm", &x, &y);
	ft_generate_images(checker);
	mlx_hook(checker->win, 2, 1L << 0, ft_handle_keys, checker);
	mlx_loop(checker->mlx);
}
