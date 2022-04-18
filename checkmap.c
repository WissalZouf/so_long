/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:55:12 by wzouf             #+#    #+#             */
/*   Updated: 2022/04/15 00:30:06 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_check *check)
{
	int	i;
	int	j;

	i = 0;
	while (check->map[i])
	{
		j = 0;
		while (check->map [i][j])
		{
			if (check->map[i][j] != '1' && check->map[i][j] != '0'
			&& check->map[i][j] != 'C'
			&& check->map[i][j] != 'P'
			&& check->map[i][j] != 'E')
			{
				ft_putstr("INVALID!\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_map2(t_check *check)
{
	int	i;
	int	j;

	i = 0;
	check->player = 0;
	check->item = 0;
	check->exit = 0;
	while (check->map[i])
	{
		j = 0;
		while (check->map[i][j])
		{
			if (check->map[i][j] == 'P')
				check->player += 1;
			if (check->map[i][j] == 'C')
				check->item += 1;
			if (check->map[i][j] == 'E')
				check->exit += 1;
			j++;
		}
		i++;
	}
	if (check->player != 1 || check->item < 1 || check->exit < 1)
		ft_error(check);
}

void	ft_check_walls(t_check *check)
{
	int	i;
	int	j;

	i = 0;
	while (check->map[i])
	{
		j = 0;
		while (check->map[i][j])
		{
			if ((check->map[i][j] != '1' && (i == 0 || i == check->height - 1))
			|| ((check->map[i][0] != '1'
			|| check->map[i][check->width - 1] != '1')
			&& (i != 0 || i != check->height - 1)))
			{
				ft_putstr("Walls error\n");
				exit (0);
			}
			j++;
		}
		i++;
	}
}

int	ft_exit( t_check *check)
{
	mlx_destroy_window(check->mlx, check->mlx_win);
	exit (0);
}
