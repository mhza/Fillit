/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:06:02 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/24 15:14:25 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, int n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_intlen_base(unsigned int n, int base);
char				**ft_realloc(char **tab, char *neww);

#endif
