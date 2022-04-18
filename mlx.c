/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:05:30 by wzouf             #+#    #+#             */
/*   Updated: 2022/04/13 00:11:36 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_check *check)
{
	check->floor_img = mlx_xpm_file_to_image(check->mlx, \
	"./floor.xpm", &check->width, &check->height);
	if (check->floor_img == NULL)
		ft_error(check);
	check->wall_img = mlx_xpm_file_to_image(check->mlx, \
	"./terrain.xpm", &check->width, &check->height);
	if (check->wall_img == NULL)
		ft_error(check);
	check->mainc_img = mlx_xpm_file_to_image(check->mlx, \
	"./mainc.xpm", &check->width, &check->height);
	if (check->mainc_img == NULL)
		ft_error(check);
	check->item_img = mlx_xpm_file_to_image(check->mlx, \
	"./item.xpm", &check->width, &check->height);
	if (check->item_img == NULL)
		ft_error(check);
	check->door_img = mlx_xpm_file_to_image(check->mlx, \
	"./door.xpm", &check->width, &check->height);
	if (check->door_img == NULL)
		ft_error(check);
}

void	check_img(char **map, t_check *check)
{
	check->i = 0;
	while (map[check->i])
	{
		check->j = 0;
		while (map[check->i][check->j])
		{
			mlx_put_image_to_window(check->mlx, check->mlx_win, \
			check->floor_img, check->j * 50, check->i * 50);
			if (map[check->i][check->j] == '1')
				mlx_put_image_to_window(check->mlx, check->mlx_win, \
				check->wall_img, check->j * 50, check->i * 50);
			if (map[check->i][check->j] == 'P')
				mlx_put_image_to_window(check->mlx, check->mlx_win, \
				check->mainc_img, check->j * 50, check->i * 50);
			if (map[check->i][check->j] == 'C')
				mlx_put_image_to_window(check->mlx, check->mlx_win, \
				check->item_img, check->j * 50, check->i * 50);
			if (map[check->i][check->j] == 'E')
				mlx_put_image_to_window(check->mlx, check->mlx_win, \
				check->door_img, check->j * 50, check->i * 50);
			check->j++;
		}
		check->i++;
	}
}

void	find_player(t_check *check, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				check->x = i;
				check->y = j;
			}
			j++;
		}
		i++;
	}
}

void	keycode_mini(int keycode, t_check *check)
{
	if (keycode == 53)
		ft_exit(check);
	if (keycode == 13)
	{
		if (check->map[check->x - 1][check->y] != '1')
		{
			if (check->map[check->x - 1][check->y] == 'C')
				check->item -= 1;
			if (check->map[check->x - 1][check->y] == 'E' && check->item == 0)
				exit (0);
			if (check->map[check->x - 1][check->y] != 'E')
			{
				check->move++;
				check->map[check->x - 1][check->y] = 'P';
				check->map[check->x][check->y] = '0';
			}
			ft_putnbr(check->move);
			ft_putstr(" moves\n");
		}
	}
	key_extra(keycode, check);
}

int	player_move(int keycode, t_check *check)
{
	find_player(check, check->map);
	mlx_clear_window(check->mlx, check->mlx_win);
	keycode_mini(keycode, check);
	if (keycode == 0)
	{
		if (check->map[check->x][check->y - 1] != '1')
		{
			if (check->map[check->x][check->y - 1] == 'C')
				check->item -= 1;
			if (check->map[check-> x][check->y - 1] != 'E')
			{
				check->move++;
				check->map[check->x][check->y - 1] = 'P';
				check->map[check->x][check->y] = '0';
			}
			ft_putnbr(check->move);
			ft_putstr(" moves\n");
		}
	}
	key_extra1(keycode, check);
	check_img(check->map, check);
	return (0);
}
