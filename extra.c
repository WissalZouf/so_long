/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:16:20 by wzouf             #+#    #+#             */
/*   Updated: 2022/04/14 23:10:25 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(long n)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -1 * n;
		ft_putchar('-');
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	ft_error(t_check *check)
{	
	(void)check;
	ft_putstr("ERROR!!\n");
	exit (0);
}

void	key_extra(int keycode, t_check *check)
{
	if (keycode == 1)
	{
		if (check->map[check->x + 1][check->y] != '1')
		{
			if (check->map[check-> x + 1][check->y] == 'C')
				check->item -= 1;
			if (check->map[check-> x + 1][check->y] != 'E')
			{
				check->move++;
				check->map[check->x + 1][check->y] = 'P';
				check->map[check->x][check->y] = '0';
			}
			ft_putnbr(check->move);
			ft_putstr(" moves\n");
		}
	}
}

void	key_extra1(int keycode, t_check *check)
{
	if (keycode == 2)
	{
		if (check->map[check->x][check->y + 1] != '1')
		{
			if (check->map[check->x][check->y + 1] == 'C')
				check->item -= 1;
			if (check->map[check->x][check->y + 1] != 'E')
			{
				check->move++;
				check->map[check->x][check->y + 1] = 'P';
				check->map[check->x][check->y] = '0';
			}
			ft_putnbr(check->move);
			ft_putstr(" moves\n");
		}
	}
}
