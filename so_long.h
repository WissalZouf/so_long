/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:22:41 by wzouf             #+#    #+#             */
/*   Updated: 2022/04/15 00:09:45 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_check
{
	char	**map;
	int		i;
	int		j;
	int		height;
	int		width;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*floor_img;
	void	*wall_img;
	void	*door_img;
	void	*mainc_img;
	void	*item_img;
	int		x;
	int		y;
	int		player;
	int		item;
	int		exit;
	int		move;
}	t_check;

void		get_line(t_check *check, char *map);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strstr(char *str, char *to_find);
void		ft_ft_printf(char *str);
char		*ft_strdup(char *s1);
char		*get_next_line(int fd);
void		get_line(t_check *check, char *map);
void		ft_map(t_check *check, char *map);
void		ft_check_map(t_check *check);
void		ft_check_map2( t_check *check);
void		ft_check_walls(t_check *check);
void		load_img(t_check *check);
void		check_img(char **map, t_check *check);
void		find_player(t_check *check, char **map);
int			player_move(int keycode, t_check *check);
void		ft_putchar(char c);
void		ft_putnbr(long n);
void		ft_putstr(char *str);
void		ft_mlx(t_check *check);
int			ft_exit(t_check *check);
void		ft_error(t_check *check);
void		key_extra(int keycode, t_check *check);
void		key_extra1(int keycode, t_check *check);
void		ft_freemap(char **map);
void		ft_norm(t_check *check);

#endif
