/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:18:02 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/30 12:33:43 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int					check_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (ft_isalnum(line[1]) == 0 || line[i] != ',')
		{
			ft_putendl("Unknown char in the map file");
			return (-1);
		}
	}
	return (0);
}

// int					put_values(t_env *e, char *line, int i)
// {
	
// }

int					get_map(char *argv, t_env *e)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY, S_IREAD);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) < 1 || ft_strlen(line) > 200)
			return (-1);
		if (check_line(line) == -1)
			return (-1);
		// if (put_values(e, line, i) == -1)
		// 	return (-1);
		i++;
	}
}