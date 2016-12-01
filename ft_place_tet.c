/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:23:45 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/01 19:00:21 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_new_map(int size)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_strnew((size + 1) * size)))
		return (NULL);
	while (i < (size + 1) * (size))
	{
		if ((i == 0 || (i + 1) % (size + 1) != 0))
			tmp[i] = '.';
		else
			tmp[i] = '\n';
		i++;
	}
	return (tmp);
}

char	*ft_we_place(char *map, char *idfig, int position, int size)
{
	int		i0;
	int		i;
	int		j;
	int		current_position;
	char	*map_tmp;

	map_tmp = ft_strdup(map);
	i0 = idfig[ft_strlen(idfig) / 2] - '0';
	i = -1;
	while (++i < ((int)ft_strlen(idfig) / 2))
	{
		j = -1;
		while (++j < (idfig[i] - '0'))
		{
			current_position = position + i * (size + 1) +
			(idfig[ft_strlen(idfig) / 2 + i] - '0') - i0;
			if ((current_position + j > (int)ft_strlen(map) ||
			map[current_position + j] != '.' || (position + 1) % (size + 1)
			- i0 + (idfig[ft_strlen(idfig) / 2 + i] - '0') <= 0)
				&& ft_strcpy(map, map_tmp))
				return (NULL);
			map[current_position + j] = idfig[ft_strlen(idfig) - 1];
		}
	}
	return (map);
}

char	*is_solved(char *map, int position, int square_size, char **figures)
{
	char	*map_tmp;

	if (!figures || figures[0] == 0)
		return (map);
	if (map[position] != '.')
		return (is_solved(map, position + 1, square_size, figures));
	while (position < square_size * (square_size + 1) - 1)
	{
		if (!map || !(map_tmp = ft_strdup(map)))
			return (NULL);
		if (ft_we_place(map, figures[0], position, square_size) != NULL)
		{
			if ((map = is_solved(map, 0, square_size, figures + 1)))
				return (map);
		}
		position++;
		map = map_tmp;
	}
	return (NULL);
}
