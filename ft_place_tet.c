/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:23:45 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/02 16:50:47 by mhaziza          ###   ########.fr       */
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

char	*ft_go_and_place(char *map, t_write ln, int position, int size)
{
	int		i;
	int		j;
	int		current_position;

	i = -1;
	while (++i < ln.len / 2)
	{
		ln.tmp1 = ln.idfig[i] - '0';
		ln.tmp2 = ln.idfig[i + ln.len / 2] - '0';
		j = -1;
		while (++j < ln.tmp1)
		{
			current_position = position + i * (size + 1) + ln.tmp2 - ln.i0;
			if ((position + 1) % (size + 1) - ln.i0 + ln.tmp2 <= 0 ||
				current_position + j > (int)ft_strlen(map) ||
				map[current_position + j] != '.')
			{
				ft_strcpy(map, ln.map_tmp);
				return (NULL);
			}
			map[current_position + j] = ln.c;
		}
	}
	return (map);
}

char	*ft_we_place(char *map, const char *idfig, int position, int size)
{
	t_write	ln;

	ft_bzero(&ln, sizeof(t_write));
	if ((ln.map_tmp = ft_strdup(map)) == NULL)
		return (NULL);
	ln.len = (int)ft_strlen(idfig);
	ln.i0 = idfig[ln.len / 2] - '0';
	ln.c = idfig[ln.len - 1];
	ln.idfig = idfig;
	if ((map = ft_go_and_place(map, ln, position, size)) == NULL)
		return (NULL);
	if (ln.map_tmp && ln.map_tmp[0])
		free(ln.map_tmp);
	return (map);
}

char	*is_solved(char *map, int position, int square_size,
		const char **figures)
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
