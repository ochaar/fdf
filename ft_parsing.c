/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:54:44 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/12 14:38:17 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_count_line(int *save, int *nbcol, int *nbline)
{
	if (!*save)
		*save = *nbcol;
	else
	{
		if (*save != *nbcol)
			ft_error(-2);
	}
	*nbcol = 0;
	(*nbline)++;
}

void		ft_count_col(char *str, int *nbcol, int *nbline)
{
	int i;
	int save;

	i = 0;
	save = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (ft_isdigit(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1])))
			(*nbcol)++;
		while (ft_isdigit(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1])))
			i++;
		if (str[i] == ',')
		{
			i++;
			ft_good_color(str, &i);
		}
		if (!ft_isdigit(str[i]) && (str[i] != ' ' && str[i] != '\t' &&
			str[i] != '\n'))
			ft_error(-2);
		if (str[i++] == '\n')
			ft_count_line(&save, nbcol, nbline);
	}
	*nbcol = save;
}

void		ft_pos(t_data **pos, char **str, int *i, int *j)
{
	while (**str == ' ' || **str == '\t' || **str == '\n')
		(*str)++;
	if (ft_isdigit(**str) || **str == '-')
		pos[*i][*j].z = ft_atoi(*str);
	pos[*i][*j].x = *j;
	pos[*i][*j].y = *i;
	while (ft_isdigit(**str) || **str == '-')
		(*str)++;
	if (**str == ',')
	{
		(*str)++;
		ft_color(pos, str, i, j);
	}
	else
		pos[*i][*j].color = 0xffffff;
	(*j)++;
}

t_data		**ft_parsing(char *str, t_mlx *info)
{
	t_data	**pos;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pos = NULL;
	ft_count_col(str, &info->col, &info->lines);
	if (!(pos = (t_data**)malloc(sizeof(t_data*) * info->lines + 1)))
		return (NULL);
	while (i < info->lines)
	{
		if (!(pos[i] = (t_data*)malloc(sizeof(t_data) * info->col + 1)))
			return (NULL);
		while (j < info->col)
			ft_pos(pos, &str, &i, &j);
		j = 0;
		i++;
	}
	return (pos);
}
