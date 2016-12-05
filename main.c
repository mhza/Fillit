/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 22:15:36 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/05 12:49:55 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_new_map(int size)
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

static char	*ft_try_square(char *map, int size, const char **figures)
{
	map = ft_new_map(size);
	map = is_solved(map, 0, size, figures);
	if (map != NULL)
		return (map);
	else
		return (ft_try_square(map, size + 1, figures));
}

static char	**ft_get_idfigures(char *str)
{
	char	*id_fig;
	char	**figures;
	int		count;
	t_read	fig;

	if ((figures = (char**)malloc(sizeof(char*))))
		figures[0] = 0;
	count = 0;
	if (ft_strlen(str) < 20)
		return (NULL);
	while ((ft_strstr(str, "\n\n") != NULL) || ft_strlen(str) == 20)
	{
		count += 1;
		ft_bzero(&fig, sizeof(t_read));
		if ((id_fig = ft_findtet(ft_strncpy(ft_strnew(20), str, 20), 0, &fig))
			== NULL)
			return (NULL);
		id_fig[ft_strlen(id_fig)] = 'A' + count - 1;
		if (!(figures = ft_realloc(figures, id_fig)))
			return (NULL);
		str = str + 20 + 1;
	}
	if (str && str[0])
		free(str);
	return (figures);
}

static int	ft_fillit(int fd)
{
	char	*str;
	int		result_read;
	char	**figures;
	char	*map;

	if ((figures = (char**)malloc(sizeof(char*))))
		figures[0] = 0;
	result_read = 0;
	if ((str = ft_strnew(BUFF_SIZE)) == NULL)
		return (0);
	result_read = read(fd, str, BUFF_SIZE);
	if (result_read % 21 != 20)
		return (0);
	str[ft_strlen(str)] = '\0';
	if ((figures = ft_get_idfigures(str)) == NULL)
		return (0);
	if ((map = ft_strnew(1)) != NULL)
		map[0] = '\0';
	if ((map = ft_try_square(map, 2, (const char**)figures)) == NULL)
		return (0);
	if (figures && figures[0])
		free(figures);
	ft_putstr(map);
	return (1);
}

int			main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		write(1, "usage: ./fillit file_name\n", 26);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	if (ft_fillit(fd) != 1)
		write(1, "error\n", 6);
	if (close(fd) > 0)
		return (1);
	return (0);
}
