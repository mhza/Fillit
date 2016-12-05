/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findtet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:05:20 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/05 12:19:26 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_read	*ft_ifnopix(t_read *ln)
{
	if (ln->is_pix == 1)
		ln->is_pix = -1;
	return (ln);
}

static t_read	*ft_ifpix(int count, t_read *ln)
{
	ln->linepix += 1;
	ln->allpix += 1;
	if (ln->is_pix == 0)
	{
		ln->is_pix = 1;
		ln->pix0 = count % 5;
	}
	return (ln);
}

static t_read	*ft_ifend(t_read *ln)
{
	if (!ln->linepix && ln->allpix)
		ln->is_emptyafterpix = 1;
	if (ln->linepix && ln->code1 > 10)
	{
		if (ln->code1 % 10 + ln->code2 % 10 - 1 < ln->pix0 ||
			ln->pix0 + ln->linepix - 1 < ln->code2 % 10)
			return (NULL);
	}
	if (ln->linepix)
	{
		ln->code1 = ln->code1 * 10 + ln->linepix;
		ln->code2 = ln->code2 * 10 + ln->pix0;
	}
	ln->linepix = 0;
	ln->is_pix = 0;
	return (ln);
}

static char		*ft_create_id(int code1, int code2)
{
	char *idfigure;

	if ((idfigure = ft_strnew(ft_strlen(ft_itoa(code1)) * 2 + 1)) == NULL)
		return (NULL);
	ft_strcpy(idfigure, ft_itoa(code1));
	ft_strcat(idfigure, ft_itoa(code2));
	idfigure[ft_strlen(ft_itoa(code1)) * 2] = '\0';
	return (idfigure);
}

char			*ft_findtet(const char *s, int count, t_read *ln)
{
	if (!s)
		return (NULL);
	count += 1;
	if (s[0] == '.' && count % 5)
		return (ft_findtet(s + 1, count, ft_ifnopix(ln)));
	if (s[0] == '#' && count % 5 && ln->allpix < 4 &&
			ln->is_pix >= 0 && !ln->is_emptyafterpix)
		return (ft_findtet(s + 1, count, ft_ifpix(count, ln)));
	if (s[0] == '\n' && !(count % 5) && (ln = ft_ifend(ln)))
		return (ft_findtet(s + 1, count, ln));
	if (s[0] == '\0' && ln->allpix == 4)
		return (ft_create_id(ln->code1, ln->code2));
	return (NULL);
}
