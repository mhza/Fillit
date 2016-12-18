/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findtet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:05:20 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/30 22:10:01 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

t_line	*ft_ifend(t_line *ln)
{
	if (!ln->pix && ln->allpix)
		ln->is_emptyafterpix = 1;
	if (ln->pix)
	{
		ln->code1 = ln->code1 * 10 + ln->pix;
		ln->code2 = ln->code2 * 10 + ln->new;
	}
	ln->pix = 0;
	ln->no_pix = 0;
	ln->is_pix = 0;
	return (ln);
}

int		ft_shift_left(int nb)
{
	char	*str;
	int		i;

	str = ft_itoa(nb);
	while (ft_strchr(str, '1') == NULL)
	{
		i = -1;
		while (str[++i])
			str[i] -= 1;
	}
	return (ft_atoi(str));
}

char	*ft_create_id(int code1, int code2)
{
	char *idfigure;

	if ((idfigure = ft_strnew(ft_strlen(ft_itoa(code1)) * 2 + 1)) == NULL)
		return (NULL);
	ft_strcpy(idfigure, ft_itoa(code1));
	ft_strcat(idfigure, ft_itoa(code2));
	idfigure[ft_strlen(ft_itoa(code1)) * 2] = '\0';
	return (idfigure);
}

char	*ft_get_id_tetri(int code1, int code2)
{
	code2 = ft_shift_left(code2);
	if (code1 > 100)
	{
		if (code1 == 211 && (code2 == 111 || code2 == 122))
			return (ft_create_id(code1, code2));
		if (code1 == 121 && (code2 == 111 || code2 == 112 || code2 == 212 ||
			code2 == 211))
			return (ft_create_id(code1, code2));
		if (code1 == 112 && (code2 == 111 || code2 == 221))
			return (ft_create_id(code1, code2));
		if (code1 == 1111 && code2 == 1111)
			return (ft_create_id(code1, code2));
	}
	else
	{
		if (code1 == 31 && (code2 == 11 || code2 == 12 || code2 == 13))
			return (ft_create_id(code1, code2));
		if (code1 == 22 && (code2 == 12 || code2 == 11 || code2 == 21))
			return (ft_create_id(code1, code2));
		if (code1 == 13 && (code2 == 11 || code2 == 21 || code2 == 31))
			return (ft_create_id(code1, code2));
		if (code1 == 4 && code2 == 1)
			return (ft_create_id(code1, code2));
	}
	return (NULL);
}
