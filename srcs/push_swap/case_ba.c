/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:20:01 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/26 14:51:26 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calculates the required amount of rotation for rra+rrb case
int case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = ft_lstsize(a) - find_place_a(a, c);
	if ((i < (ft_lstsize(b) - find_index(b, c))) && find_index(b, c))
		i = ft_lstsize(b) - find_index(b, c);
	return (i);
}

// calculates the required amount of rotation for ra+rb case
int case_rarb_a(t_stack *stack_a, t_stack *stack_b, int num_push)
{
	int i;

	i = find_place_a(stack_a, num_push);
	if (i < find_index(stack_b, num_push))
		i = find_index(stack_b, num_push);
	return (i);
}

// calculates the required amount of rotation for ra+rrb case
int	case_rarrb_a(t_stack *stack_a, t_stack *stack_b, int num_push)
{
	int i;

	i = 0;
	if (find_index(stack_b, num_push))
		i = ft_lstsize(stack_b) - find_index(stack_b, num_push);
	i = find_place_a(stack_a, num_push) + i;
	return (i);
}

// calculates the required amount of rotation for rra+rb case
int	case_rrarb_a(t_stack *stack_a, t_stack *stack_b, int num_push)
{
	int i;

	i = 0;
	if (find_place_a(stack_a, num_push))
		i = ft_lstsize(stack_a) - find_place_a(stack_a, num_push);
	i = find_index(stack_b, num_push) + i;
	return (i);
}
