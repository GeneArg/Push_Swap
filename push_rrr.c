/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:54:07 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/25 19:01:04 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int n)
{
	t_stack *temp;

	if (!*stack_b)
		return ;
	temp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = temp;
	if (n == 0)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, int n)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = temp;
	if (n == 0)
		write(1, "pb\n", 3);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int n)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	if (n == 0)
		write(1, "rrr\n", 4);
}
