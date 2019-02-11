/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:32:18 by ochaar            #+#    #+#             */
/*   Updated: 2018/12/14 15:54:47 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int x)
{
	if (x == -1)
		ft_putendl_fd("Wrong number of map", 2);
	if (x == -2)
		ft_putendl_fd("Wrong map", 2);
	if (x == -3)
		ft_putendl_fd("Wrong color", 2);
	if (x == -4)
		ft_putendl_fd("Bad representation", 2);
	exit(-1);
}
