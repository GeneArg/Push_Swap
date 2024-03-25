/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:35:45 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/25 11:38:45 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a)
{
	t_stack *stack_b;
	int	i;

	stack_b = NULL;
	if(ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
	}
}

t_stack **sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	t_stack *temp;

	while(*stack_b)
	{
		temp = *stack_b;
		i = rotate_type_ba(*stack_a, *stack_b);
	}
}