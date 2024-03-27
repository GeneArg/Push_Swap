/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:25:21 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/25 18:16:20 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack_a, int n)
{
	t_stack *temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	if (n == 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b, int n)
{
	t_stack *temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	if (n == 0)
		write(1, "sb\n", 3);
}

void 	ft_ss(t_stack **stack_a, t_stack **stack_b, int n)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	if (n == 0)
		write(1, "ss\n", 3);
}
