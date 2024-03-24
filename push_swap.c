/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:31:05 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/24 15:59:19 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *quoted_string(char **argv)
{
	t_stack *a;
	char **temp;
	int i;
	int j;

	i = 0;
	a = NULL;
	temp = ft_split(argv[1], ' ');
	while(temp[i])
	{
		j = mod_atoi(temp[i]);
		add_back(&a, new_stack(j));
		i++;
	}
	// free temp
	return (a);
}

// 1. To check if the number of input is less than 2.
// 2. To check if the number of input is equal to 2 - quoted string.
// 3. To check if the number of input is greater than 2 - list the arguments.

t_stack *input_process(int argc, char **argv)
{
	t_stack *a;
	int i;
	int j;

	a = NULL;
	i = 1;
	if(argc < 2)
		error_print();
	else
	if(argc == 2)
		a = quoted_string(argv);
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
