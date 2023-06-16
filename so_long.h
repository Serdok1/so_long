#ifndef SO_LONG_H
# define SO_LONG_H
# include "./minilibx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
typedef struct t_checker
{
    void	*mlx;
	void	*win;
    void	*hero1;
    void	*wall;
    void	*background;
    void	*exit_img;
    void	*collectible;
    char    **map;
    char    **temp_map;
    int     x;
    int     y;
    int     exit;
    int     rectangle;
    int     collectibles;
    int     count;
    int     rows;
    int     player_x;
    int     player_y;
    int     exit_x;
    int     exit_y;
}   t_checker;

void	ft_draw_map(t_checker	*checker, char **map);
#endif