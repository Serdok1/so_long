/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:38:22 by sozbayra          #+#    #+#             */
/*   Updated: 2023/06/19 16:40:18 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void ft_check_valid_path(int x_of_p, int y_of_p, t_checker *checker){
    //if all around the player is full of '1's, its working. Recursive algorithm is working but not know where is the stop.
    /* printf("y_of_p:%d\nx_of_p:%d\n", y_of_p, x_of_p); */
   	ft_check_valid_path_extension(checker, (x_of_p + 1), y_of_p);
	ft_check_valid_path_extension(checker, x_of_p, (y_of_p - 1));
	ft_check_valid_path_extension(checker, (x_of_p - 1), y_of_p);
	ft_check_valid_path_extension(checker, x_of_p, (y_of_p + 1));
}

void ft_find_exit(char **map, t_checker *checker) {
    int row = checker->rows - 2;
    checker->exit_x = -1;
    checker->exit_y = -1;

    while (row >= 0) {
        int i = 0;
        while (i < checker->rectangle) {
            if (map[row][i] == 'E') {
                checker->exit_y = row;
                checker->exit_x = i;
                break;
            }
            i++;
        }
        if (checker->exit_x != -1 && checker->exit_y != -1) {
            break;
        }
        row--;
    }

    if (checker->exit_x != -1 && checker->exit_y != -1) {
        ft_check_valid_path(checker->player_x, checker->player_y, checker);
    }
}

void ft_find_player(char **map, t_checker *checker) {
    int row = checker->rows - 2;
    checker->player_x = -1;
    checker->player_y = -1;

    while (row >= 0) {
        int i = 0;
        while (i < checker->rectangle) {
            if (map[row][i] == 'P') {
                checker->player_y = row;
                checker->player_x = i;
                break;
            }
            i++;
        }
        if (checker->player_x != -1 && checker->player_y != -1) {
            break;
        }
        row--;
    }

    if (checker->player_x != -1 && checker->player_y != -1) {
        ft_find_exit(map, checker);
    }
}

void ft_check_walls(t_checker *checker) {
    int i;
    int row;
    char **map;

    i = 0;
    row = checker->rows;
    checker->x = 1;
    checker->y = 1;
    map = checker->map;
    
    // Last column
    while (map[row - 2][i] && map[row - 2][i] != '\n') {
        if (checker->x == 1 && map[row - 2][i] == '1') {
            i++;
        } else {
            checker->x = -1;
            break;
        }
    }
    
    row -= 3;
    
    while (row >= 0) {
        if (map[row][0] == '1' && map[row][checker->rectangle - 1] == '1') {
            row--;
        } else {
            checker->y = -1;
            break;
        }
    }
    
    i = 0;
    
    while (map[0][i] && map[0][i] != '\n') {
        if (checker->x == 1 && map[0][i] == '1') {
            i++;
        } else {
            checker->x = -1;
            break;
        }
    }
}

void	ft_convert_to_matrix_func(t_checker *checker, int fd, t_temp *temp)
{
	checker->map = (char **)malloc(checker->rows * sizeof(char *));
	checker->temp_map = (char **)malloc(checker->rows * sizeof(char *));
	while (temp->control != 1)
	{
		temp->string = get_next_line(fd);
		if (temp->string != 0)
		{
			checker->map[temp->matrix_i] = (char *)malloc(checker->rectangle
					* sizeof(char));
			checker->temp_map[temp->matrix_i] = (char *)malloc(checker->rectangle
					* sizeof(char));
			temp->matrix_j = 0;
			while (temp->string[temp->matrix_j]
				&& temp->string[temp->matrix_j] != '\n')
			{
				checker->map[temp->matrix_i][temp->matrix_j] = temp->string[temp->matrix_j];
				checker->temp_map[temp->matrix_i][temp->matrix_j] = temp->string[temp->matrix_j];
				temp->matrix_j++;
			}
			checker->map[temp->matrix_i][temp->matrix_j] = '\0';
			checker->temp_map[temp->matrix_i][temp->matrix_j] = '\0';
			temp->matrix_i++;
		}
		else
			temp->control = 1;
		free(temp->string);
	}
}

void	ft_convert_to_matrix(int fd, t_checker *checker)
{
	t_temp	temp;

	temp.control = 0;
	temp.matrix_i = 0;
	ft_convert_to_matrix_func(checker, fd, &temp);
}

void ft_read_map(int fd, t_checker *checker){
    char *c;
    int length;
    int j;
    int control;
    int size;
    int i;
    
    i = 0;
    control = 0;
    size = 0;
    length = 0;
    while(control != 1)
    {
        j = 0;
        checker->rows++;
        c = get_next_line(fd);
        if(c != 0)
        {
            if(checker->rectangle == length)
            {
                while(c[j] && c[j] != '\n')
                {
                    j++;
                }
                length = j;;
                if(i == 0)
                    checker->rectangle = length;
                if(i > 0){
                    if(checker->rectangle == length)
                        checker->rectangle = length;
                    else
                        checker->rectangle = -1;
                }
                i++;
            }
            else
                checker->rectangle = -1;
        }
        else
            control = 1;
        free(c);
    }
}


int main()
{
    int fd;
    int sd;
    t_checker checker;
    
    fd = open("map.ber", O_RDWR);
    sd = open("map.ber", O_RDWR);
    ft_read_map(fd, &checker);
    close(fd);
    if(checker.rectangle != -1)
    {//If map is not rectangular, missing column count will cause segmentation error.
        ft_convert_to_matrix(sd, &checker);
        close(sd);
    }
    ft_check_walls(&checker);
    if(checker.x == 1 && checker.y == 1)
        ft_find_player(checker.map, &checker);
    checker.mlx = mlx_init();
	checker.win = mlx_new_window(checker.mlx, checker.rectangle * 48, (checker.rows - 1) * 48, "So Long by Sina");
    if(checker.collectibles >= 1 && checker.exit >= 1)
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