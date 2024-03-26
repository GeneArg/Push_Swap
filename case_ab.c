/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:27:58 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/26 15:23:36 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb(t_stack *stack_a, t_stack *stack_b, int num_push)
{
	int i;

	i = find_place_b(stack_b, num_push);
	if (i < find_index(stack_a, num_push))
		i = find_index(stack_a, num_push);
	return (i);
}

int	case_rrarrb(t_stack *stack_a, t_stack *stack_b, int num_push)
{
	int i;

	i = 0;
	if (find_place_b(stack_b, num_push))
		i = ft_lstsize(stack_b) - find_place_b(stack_b, num_push);
	if ((i < (ft_lstsize(stack_a) - find_index(stack_a, num_push))) && find_index(stack_a, num_push))
		i = ft_lstsize(stack_a) - find_index(stack_a, num_push);
	return (i);
}

int	case_rrarb(t_stack *stack_a, t_stack *stack_b, int num_push)
{
	int i;

	i = 0;
	if (find_index(stack_a, num_push))
		i = ft_lstsize(stack_a) - find_index(stack_a, num_push);
	i = find_place_b(stack_b, num_push) + i;
	return (i);
}

int	case_rarrb(t_stack *stack_a, t_stack *stack_b, int num_push)
{
	int i;

	i = 0;
	if (find_place_b(stack_b, num_push))
		i = ft_lstsize(stack_b) - find_place_b(stack_b, num_push);
	i = find_index(stack_a, num_push) + i;
	return (i);
}
