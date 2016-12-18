/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findtet_ingreatmemory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:05:20 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/30 22:13:38 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_wePlace(char *map, char *idfig, int position, int size)
{
	int		i0;
	int		i;
	int		j;
	int		current_position;
	int		tmp1;
	int		tmp2;
	char	*map_tmp;

	map_tmp = ft_strdup(map);
	i0 = idfig[ft_strlen(idfig) / 2] - '0';
	i = 0;
	while (i < ft_strlen(idfig) / 2)
	{
		j = 0;
		tmp1 = idfig[i] - '0';
		tmp2 = idfig[ft_strlen(idfig) / 2 + i] - '0';
		while (j < tmp1)
		{
			current_position = position + i * (size + 1) + tmp2 - i0;
			if (position % (size + 1) - i0 + tmp2 <= 0)
			{
				ft_strcpy(map, map_tmp);
				return (NULL);
			}
			if (map[current_position + j] && map[current_position + j] != '.')
			{
				ft_strcpy(map, map_tmp);
				return (NULL);
			}
			map[current_position + j] = idfig[ft_strlen(idfig) - 1];
			j++;
		}
		i++;
	}
	return (map);
}


t_line	*ft_ifpix(int count, t_line *ln, int tf)
{
	if (tf)
	{
		ln->pix += 1;
		ln->allpix += 1;
		if (ln->is_pix == 0)
		{
			ln->is_pix = 1;
			ln->old = ln->new;
			ln->new = count % 5;
		}
	}
	else
	{
		ln->no_pix += 1;
		if (ln->is_pix == 1)
			ln->is_pix = 2;
	}
	return (ln);
}

t_line	*ft_ifend(t_line *ln, int is_found, int tet)
{
	if (!ln->pix && ln->allpix)
		ln->is_emptyafterpix = 1;
	ln->tet = tet;
	if (ln->pix)
	{
		ln->code1 = ln->code1 * 10 + ln->pix;
		ln->code2 = ln->code2 * 10 + ln->new;
	}
	ln->pix = 0;
	ln->no_pix = 0;
	ln->is_pix = 0;
	ln->is_found = is_found;
	return (ln);
}

t_line	*ft_which_tet2(t_line *ln)
{
	if (!(ln->tet % 10) && ln->allpix == 3)
	{
		if (ln->pix == 1 && ln->tet == 20 && (ln->new - ln->old) % 4 < 2)
			return (ft_ifend(ln, 1, ln->tet + (ln->new - ln->old)));
		if (ln->pix == 2 && ln->tet == 10 && (ln->new - ln->old) % 4 < 2)
			return (ft_ifend(ln, 0, 13 * (1 - ln->old + ln->new)
			+ 15 * (-ln->new + ln->old)));
	}
	if (ln->tet == 10 && ln->pix == 1 && ln->new == ln->old)
		return (ft_ifend(ln, 0, 17));
	if ((ln->tet == 13 || ln->tet == 15) && ln->pix == 1 &&
	ln->allpix == 4 && (ln->new - ln->old) % 4 < 2)
		return (ft_ifend(ln, 1, ln->tet + ln->new - ln->old));
	if (ln->tet == 17)
	{
		if (ln->pix == 1 && ln->new == ln->old)
			return (ft_ifend(ln, 1, 19));
		if (ln->pix == 2 && (ln->old - ln->new) % 4 < 2)
			return (ft_ifend(ln, 1, ln->tet + ln->old - ln->new));
	}
	return (ln);
}

t_line	*ft_which_tet(t_line *ln)
{
	if (!ln->pix)
		return (ft_ifend(ln, ln->is_found, ln->tet));
	if (ln->pix && ln->tet == 0)
		return (ft_ifend(ln, ln->pix / 4, ln->pix * 10));
	if (ln->is_found && ln->pix == 1 && ln->new == ln->old)
		return (ft_ifend(ln, 1, ln->tet));
	if (!(ln->tet % 10) && ln->allpix == 4)
	{
		if (ln->pix == 1 && ln->tet == 30 && (ln->new - ln->old) % 4 != 3)
			return (ft_ifend(ln, 1, ln->tet + (ln->new - ln->old)));
		if (ln->pix == 2 && ln->tet == 20 && ABS(ln->new - ln->old) <= 1)
			return (ft_ifend(ln, 1, ln->tet + 3 + (ln->new - ln->old)));
		if (ln->pix == 3 && ln->tet == 10 && (ln->old - ln->new) % 4 != 3)
			return (ft_ifend(ln, 1, ln->tet + (ln->old - ln->new)));
	}
	return (ft_which_tet2(ln));
}

t_line	*ft_findtet(char *s, int count, t_line *ln)
{
	if (!s)
		return (NULL);
	count += 1;
	if (s[0] == '.' && count % 5)
		return (ft_findtet(s + 1, count, ft_ifpix(count, ln, 0)));
	if (s[0] == '#' && count % 5 && ln->allpix < 4 &&
			ln->is_pix < 2 && !ln->is_emptyafterpix)
		return (ft_findtet(s + 1, count, ft_ifpix(count, ln, 1)));
	if (s[0] == '\n' && !(count % 5))
		return (ft_findtet(s + 1, count, ft_which_tet(ln)));
	if (s[0] == '\0')
		return (ln);
	return (NULL);
}
