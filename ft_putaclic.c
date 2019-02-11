/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaclic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:34:55 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/17 17:57:11 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_move(int input, void *param)
{
	if (input == 123)
	{
		ft_clearmap(param);
		((t_mlx*)param)->hor -= 3;
		ft_create_map(param);
	}
	if (input == 124)
	{
		ft_clearmap(param);
		((t_mlx*)param)->hor += 3;
		ft_create_map(param);
	}
	if (input == 125)
	{
		ft_clearmap(param);
		((t_mlx*)param)->ver += 3;
		ft_create_map(param);
	}
	if (input == 126)
	{
		ft_clearmap(param);
		((t_mlx*)param)->ver -= 3;
		ft_create_map(param);
	}
	return (0);
}

static int	ft_zoom(int input, void *param)
{
	if (input == 78)
	{
		ft_clearmap(param);
		((t_mlx*)param)->scale -= 1;
		ft_create_map(param);
	}
	if (input == 69)
	{
		ft_clearmap(param);
		((t_mlx*)param)->scale += 1;
		ft_create_map(param);
	}
	return (0);
}

int			ft_putaclic(int input, void *param)
{
	if (input == 53)
	{
		mlx_destroy_image(((t_mlx*)param)->mlx, ((t_mlx*)param)->img);
		mlx_destroy_window(((t_mlx*)param)->mlx, ((t_mlx*)param)->win);
		exit(0);
	}
	if (input == 0)
	{
		ft_clearmap(param);
		((t_mlx*)param)->size += 1;
		ft_create_map(param);
	}
	if (input == 1)
	{
		ft_clearmap(param);
		((t_mlx*)param)->size -= 1;
		ft_create_map(param);
	}
	ft_zoom(input, param);
	ft_move(input, param);
	return (0);
}
