/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 21:59:55 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/05 12:23:37 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE	546

typedef struct	s_read
{
	int	linepix;
	int	allpix;
	int	pix0;
	int	is_pix;
	int	is_emptyafterpix;
	int	code1;
	int	code2;
}				t_read;

typedef struct	s_write
{
	int			tmp1;
	int			tmp2;
	int			i0;
	int			sq_size;
	int			len;
	char		c;
	char		*map_tmp;
	const char	*idfig;

}				t_write;

char			*ft_findtet(const char *s, int count, t_read *ln);
char			*is_solved(char *map, int position, int square_size,
				const char **figures);

#endif
