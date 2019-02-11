/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:07:44 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/13 15:58:27 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color(t_data **pos, char **str, int *i, int *j)
{
	if (**str == '0' && *(*str + 1) == 'x')
		*str += 2;
	pos[*i][*j].color = ft_atoi_base(*str, 16);
	*str = *str + 6;
}

void	ft_good_color(char *str, int *i)
{
	int cpt;

	cpt = 0;
	if (str[*i] == '0' && str[*i + 1] == 'x')
		*i += 2;
	while (ft_isdigit(str[*i]) || (str[*i] > 64 && str[*i] < 71) ||
		(str[*i] > 96 && str[*i] < 103))
	{
		(*i)++;
		cpt++;
	}
	if (cpt < 3)
		ft_error(-3);
}
