/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:31:05 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/24 12:55:06 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *input_process(int argc, char **argv)
{
	t_stack *a;
	int i;
	int j;

	a = NULL;
	i = 1;
	if(argc < 2)
		// TODO error function
	if(argc == 2)
		// TODO split function in case of the stacks passed in quotes
	else
	{
		while (i < argc)
		{
			j = //atoi(argv[i])
			// list functions here
			i++;
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = input_process(argc, argv);
}
