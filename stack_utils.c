/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:05:51 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/25 13:22:22 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int ft_lstsize(t_stack *stack)
{
	size_t i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int ft_min(t_stack *stack_a)
{
	int i;
	i = stack_a->num;
	while (stack_a)
	{
		if (i > stack_a->num)
			i = stack_a->num;
		stack_a = stack_a->next;
	}
	return (i);
}

int ft_max(t_stack *stack_a)
{
	int i;
	
	i = stack_a->num;
	while (stack_a)
	{
		if (i < stack_a->num)
			i = stack_a->num;
		stack_a = stack_a->next;
	}
	return (i);
}
