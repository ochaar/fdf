/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:16:35 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/14 16:31:54 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_fdf(char *str, int iso_par)
{
	t_mlx	info;

	ft_bzero(&info, sizeof(t_mlx));
	info.cord = ft_parsing(str, &info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, 1000, 1000, "FDF");
	info.img = mlx_new_image(info.mlx, 1000, 1000);
	info.data = mlx_get_data_addr(info.img, &info.bpp, &info.sizel, &info.end);
	info.ver = 0;
	info.hor = 0;
	info.size = 1;
	info.scale = 5;
	if (iso_par == 0)
	{
		ft_create_map(&info);
		mlx_hook(info.win, 2, 0, ft_putaclic, &info);
	}
	else if (iso_par == 1)
	{
		ft_create_map_par(&info);
		mlx_hook(info.win, 2, 0, ft_putaclic_par, &info);
	}
	mlx_loop(info.mlx);
	return (0);
}

static int	ft_verif_argc(int argc, char **argv, int *iso_par)
{
	if (argc < 2)
		ft_error(-1);
	else if (argc == 3)
	{
		if (ft_strcmp(argv[2], "par") == 0)
			*iso_par = 1;
		else if (ft_strcmp(argv[2], "iso") == 0)
			;
		else
			ft_error(-4);
	}
	else if (argc > 3)
		ft_error(-1);
	return (0);
}

int			main(int argc, char **argv)
{
	char	*line;
	char	*tab;
	char	*tmp;
	int		iso_par;
	int		fd;

	iso_par = 0;
	ft_verif_argc(argc, argv, &iso_par);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(-1);
	tab = ft_strnew(0);
	while ((get_next_line(fd, &line)) > 0)
	{
		tmp = tab;
		tab = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		tmp = tab;
		tab = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	if (*tab == '\0' || *tab == '\n')
		ft_error(-1);
	ft_fdf(tab, iso_par);
	return (0);
}
