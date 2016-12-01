/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 21:59:55 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/01 19:04:19 by mhaziza          ###   ########.fr       */
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

typedef struct	s_line
{
	int	pix;
	int	no_pix;
	int allpix;
	int old;
	int	new;
	int	is_pix;
	int is_found;
	int	is_emptyafterpix;
	int	code1;
	int	code2;
}				t_line;

char			*ft_findtet(char *s, int count, t_line *ln);
char			*ft_new_map(int size);
char			*ft_we_place(char *map, char *idfig, int position, int size);
char			*is_solved(char *map, int position, int square_size,
				char **figures);
t_line			*ft_ifpix(int count, t_line *ln);
t_line			*ft_ifnopix(t_line *ln);
t_line			*ft_ifend(t_line *ln);
char			*ft_create_id(int code1, int code2);
char			*ft_try_square(char *map, int size, char **figures);

#endif
