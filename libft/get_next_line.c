/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:32:32 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/27 12:33:23 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	line[100];
	char	buf;
	int		i;
	int		j;

	if (fd < 0)
		return (NULL);
	j = read(fd, &buf, 1);
	i = 0;
	while (j > 0)
	{
		line[i] = buf;
		i++;
		if (buf == '\n')
			break ;
		j = read(fd, &buf, 1);
	}
	line[i] = '\0';
	if (i == 0 && j <= 0)
		return (NULL);
	return (ft_strdup(line));
}
