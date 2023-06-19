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

typedef struct s_temp
{
    int		control;
	char	*string;
	int		matrix_i;
	int		matrix_j;
}   t_temp;

void	ft_draw_map(t_checker	*checker, char **map);
void    ft_check_valid_path_extension(t_checker *checker, int x_of_p, int y_of_p);
void ft_check_valid_path(int x_of_p, int y_of_p, t_checker *checker);
int	ft_handle_keys(int keycode, t_checker *checker);
void	ft_control_player_y(int player_y, int player_x, int indicator,
		t_checker *checker);
void	ft_control_player_x(int player_y, int player_x, int indicator,
		t_checker *checker);
void	ft_exit_control(t_checker *checker, int player_y, int player_x);
void	ft_exit(void *mlx, void *win);
#endif