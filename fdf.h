/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:00:39 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/14 16:32:03 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# define CORD info->cord
# define SCALE info->scale
# define HORI info->hor
# define VER info->ver

typedef	struct	s_data
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_data;

typedef struct	s_mlx
{
	t_data	**cord;
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		end;
	int		lines;
	int		col;
	int		sizel;
	int		scale;
	int		size;
	int		ver;
	int		hor;
}				t_mlx;

typedef struct	s_bresenham
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}				t_bresenham;

typedef struct	s_xy
{
	int	x;
	int	y;
	int	color;
}				t_xy;

int				ft_putaclic(int input, void *param);
int				ft_putaclic_par(int input, void *param);
int				deal_key(int input, void *param);
t_data			**ft_parsing(char *str, t_mlx *info);
void			ft_count_col(char *str, int *nbcol, int *nbline);
void			ft_count_line(int *save, int *nbcol, int *nbline);
void			ft_create_map(t_mlx *info);
void			ft_clearmap(t_mlx *info);
void			ft_create_map_par(t_mlx *info);
void			ft_clearmap_par(t_mlx *info);
void			ft_print_line_iso(t_mlx *info, int i, int j, int color);
void			ft_print_col_iso(t_mlx *info, int i, int j, int color);
void			ft_print_line_par(t_mlx *info, int i, int j, int color);
void			ft_print_col_par(t_mlx *info, int i, int j, int color);
void			ft_segment(t_mlx *info, t_xy a, t_xy b, int color);
void			ft_error(int x);
void			ft_color(t_data **pos, char **str, int *i, int *j);
void			ft_good_color(char *str, int *i);

#endif
