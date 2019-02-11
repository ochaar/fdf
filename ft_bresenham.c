/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:25:41 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/14 16:33:19 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(char *data, int sizel, t_xy a)
{
	int i;

	if (a.x < 0 || a.x >= 1000 || a.y >= 1000 || a.y < 0)
		return ;
	i = sizel * a.y + a.x * 4;
	data[i] = a.color & 0xff;
	data[++i] = a.color >> 8 & 0xff;
	data[++i] = a.color >> 16;
}

static void	ft_init(t_bresenham *bres, t_xy a, t_xy b)
{
	bres->dx = abs(b.x - a.x);
	bres->sx = a.x < b.x ? 1 : -1;
	bres->dy = abs(b.y - a.y);
	bres->sy = a.y < b.y ? 1 : -1;
}

void		ft_segment(t_mlx *info, t_xy a, t_xy b, int color)
{
	t_bresenham bres;

	ft_init(&bres, a, b);
	bres.err = (bres.dx > bres.dy ? bres.dx : -bres.dy) / 2;
	bres.e2 = bres.err;
	if (color == -1)
		a.color = 0;
	while (1)
	{
		ft_put_pixel(info->data, info->sizel, a);
		if (a.x == b.x && a.y == b.y)
			break ;
		bres.e2 = bres.err;
		if (bres.e2 > -bres.dx)
		{
			bres.err -= bres.dy;
			a.x += bres.sx;
		}
		if (bres.e2 < bres.dy)
		{
			bres.err += bres.dx;
			a.y += bres.sy;
		}
	}
}
