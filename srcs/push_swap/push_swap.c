/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:31:05 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/27 16:38:53 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = input_process(argc, argv);
	if (!a || check_dup(a))
	{
		free_stack(&a);
		error_print();
	}
	if(!check_if_sorted(a))
		sort_stack(&a);
	free_stack(&a);
	return (0);
}
