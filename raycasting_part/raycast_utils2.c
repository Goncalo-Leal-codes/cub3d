/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:42:55 by gleal             #+#    #+#             */
/*   Updated: 2021/03/20 17:24:04 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		has_wall(double x, double y, t_adata *a)
{
	int		mapgridx;
	int		mapgridy;

	if ((int)x < 0 || (int)x > a->map.map_w || (int)y < 0 || (int)y > a->map.map_h)
		return (1);
	mapgridx = (int)x / a->map.tile_size;
	mapgridy = (int)y / a->map.tile_size;
	if (mapgridx >= (int)ft_strlen(a->map.maptxt[mapgridy]))
		return (1);
	if (a->map.maptxt[(int)mapgridy][(int)mapgridx] == '1')
		return (1);
	return (0);
}

int		add_sprites(t_item *items, char **strs, t_adata *a)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	j = 0;
	nbr = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == '2')
			{
				items[nbr].x = (double)(j + 0.5) * a->map.tile_size;
				items[nbr].y = (double)(i + 0.5) * a->map.tile_size;
				ftinit_img_sps(&items[nbr], a);
				nbr++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

double	normalrad(double movestep)
{
	if (movestep >= (2 * M_PI))
		movestep -= (2 * M_PI);
	if (movestep < (0))
		movestep += (2 * M_PI);
	return (movestep);
}

double	distancepoints(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

int		ft_countsprites(char **strs)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	j = 0;
	counter = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == '2')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
