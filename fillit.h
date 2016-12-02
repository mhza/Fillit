/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 21:59:55 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/02 16:23:02 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# define ABS(Value) (Value < 0 ? -Value : Value)
# define BUFF_SIZE	546

typedef struct	s_read
{
	int	linepix;
	int allpix;
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
char			*ft_new_map(int size);
char			*ft_we_place(char *map, const char *idfig, int position,
				int size);
char			*ft_go_and_place(char *map, t_write ln, int position, int size);
char			*is_solved(char *map, int position, int square_size,
				const char **figures);
t_read			*ft_ifpix(int count, t_read *ln);
t_read			*ft_ifend(t_read *ln);
char			*ft_create_id(int code1, int code2);
char			*ft_try_square(char *map, int size, const char **figures);

#endif
