/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:28:24 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/13 15:49:34 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_line_iso(t_mlx *info, int i, int j, int color)
{
	t_xy	a;
	t_xy	b;

	a.x = (((CORD[i][j].x - CORD[i][j].y) * SCALE) + 1) + HORI;
	a.y = (((CORD[i][j].z * info->size * SCALE / 40) +
		(CORD[i][j].x + CORD[i][j].y) * SCALE) + 1) + VER;
	a.color = CORD[i][j].color;
	b.x = (((CORD[i][j + 1].x - CORD[i][j + 1].y) * SCALE) + 1) + HORI;
	b.y = (((CORD[i][j + 1].z * info->size * SCALE / 40) +
		(CORD[i][j + 1].x + CORD[i][j + 1].y) * SCALE) + 1) + VER;
	b.color = CORD[i][j + 1].color;
	ft_segment(info, a, b, color);
}

void	ft_print_col_iso(t_mlx *info, int i, int j, int color)
{
	t_xy	a;
	t_xy	b;

	a.x = (((CORD[i][j].x - CORD[i][j].y) * SCALE) + 1) + HORI;
	a.y = (((CORD[i][j].z * info->size * SCALE / 40) +
		(CORD[i][j].x + CORD[i][j].y) * SCALE) + 1) + VER;
	a.color = CORD[i][j].color;
	b.x = (((CORD[i + 1][j].x - CORD[i + 1][j].y) * SCALE) + 1) + HORI;
	b.y = (((CORD[i + 1][j].z * info->size * SCALE / 40) +
		(CORD[i + 1][j].x + CORD[i + 1][j].y) * SCALE) + 1) + VER;
	b.color = CORD[i + 1][j].color;
	ft_segment(info, a, b, color);
}

void	ft_clearmap(t_mlx *info)
{
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	color = -1;
	while (i < info->lines)
	{
		while (j < info->col)
		{
			if (j + 1 < info->col)
				ft_print_line_iso(info, i, j, color);
			if (i + 1 < info->lines)
				ft_print_col_iso(info, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void	ft_create_map(t_mlx *info)
{
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	color = 0;
	while (i < info->lines)
	{
		while (j < info->col)
		{
			if (j + 1 < info->col)
				ft_print_line_iso(info, i, j, color);
			if (i + 1 < info->lines)
				ft_print_col_iso(info, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}
