/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:48:08 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/26 16:27:20 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if negative
int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

// check if digit
int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

// check if space
int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

// check if valid arguments
int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (false);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
