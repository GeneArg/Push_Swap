/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:04:58 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/26 18:15:34 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// after checking, add the number to the stack
void	list_args(char **argv, t_stack **stack_a)
{
	long i;

	i = 1;
	while (argv[i] != NULL)
	{
		add_back(stack_a, new_stack(ft_atoi(argv[i])));
		i++;
	}
}

int	ft_isalpha(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 47)
		|| (c == 44) || (c == 46) || (c == 47))
		return (1);
	return (0);
}


void	alpha_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				error_print();
			j++;
		}
		i++;
	}
}

int	check_args(char **argv)
{
	alpha_check(argv);
	if (!check_error(argv, 1, 0))
		return (false);
	return (true);
}

int	check_sign(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && !ft_isdigit(argv[i][j + 1]))
				error_print();
			j++;
		}
		i++;
	}
	return (0);
}
