/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:51:10 by wzouf             #+#    #+#             */
/*   Updated: 2022/04/15 00:11:04 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	char	buff[8000000];
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		buff[i] = c;
		i++;
	}
	buff[i] = 0;
	if (buff[0] == '\0')
		return (NULL);
	return (ft_strdup(buff));
}

void	get_line(t_check *check, char *map)
{
	int		fd;
	char	c;
	char	*tmp;
	int		line;

	check->move = 0;
	line = 0;
	fd = open (map, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp)
		line++;
	while (read (fd, &c, 1))
	{
		if (c == '\n')
			line++;
	}
	check->height = ++line;
	check->width = 0;
	if (tmp)
		check->width = ft_strlen(tmp);
	free(tmp);
	close (fd);
}

void	ft_map(t_check *check, char *map)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map, O_RDONLY);
	check->map = malloc(sizeof(char *) * (check->height + 1));
	if (!check->map)
		exit(0);
	while (i < check->height)
	{
		check->map[i] = get_next_line(fd);
		if (check->map[i] == NULL)
			break ;
		i++;
	}
	if (i != check->height)
	{
		ft_putstr("map invalid !\n");
		exit(0);
	}
	check->map[i] = 0;
	close(fd);
}

void	ft_mlx(t_check *check)
{
	check->mlx = mlx_init();
	check->mlx_win = mlx_new_window(check->mlx, 50 * check->width, \
	50 * check->height, "So long");
	load_img(check);
	check_img(check->map, check);
	mlx_key_hook(check->mlx_win, player_move, check);
	mlx_hook(check->mlx_win, 17, 0, ft_exit, check);
	mlx_loop(check->mlx);
}

int	main(int argc, char **argv)
{
	t_check	check;
	int		i;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments !\n");
		exit(0);
	}
	if (ft_strcmp(".ber", ft_strstr(argv[1], ".ber\0")))
	{
		ft_putstr("Wrong file format !\n");
		exit (0);
	}
	if (open(argv[1], O_RDONLY) == -1)
	{
		ft_putstr("File doesn't exist \n");
		exit (0);
	}
	get_line(&check, argv[1]);
	ft_map(&check, argv[1]);
	ft_norm(&check);
	ft_mlx(&check);
	ft_freemap(check.map);
	return (0);
}
