/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:52:03 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/26 15:21:31 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_parse(int argc, char **argv)
{
	t_stack *stack_a;
	// int	i;
	// int	j;

	// i = 1;
	stack_a = NULL;
	if (argc < 2)
		error_print();
	else if (argc == 2)
		stack_a = parse_quoted(argv);
	else
		list_args(argv, &stack_a);
	return (stack_a);
}

t_stack *parse_quoted(char **argv)
{
	t_stack *stack_a;
	char	**temp;
	// int		i;
	// int		j;

	stack_a = NULL;
	// i = 0;
	temp = ft_split(argv[1], ' ');
	list_args(temp, &stack_a);
	free_str(temp);
	free(temp);
	return (stack_a);
}
