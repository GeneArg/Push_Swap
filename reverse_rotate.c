/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:10:42 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/25 19:00:55 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stack_a, int n)
{
	t_stack *temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = ft_lstlast(*stack_a);
	(*stack_a)->next = temp;
	*stack_a = temp->next;
	temp->next = NULL;
	if (n == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_b, int n)
{
	t_stack *temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = ft_lstlast(*stack_b);
	(*stack_b)->next = temp;
	*stack_b = temp->next;
	temp->next = NULL;
	if (n == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int n)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	if (n == 0)
		write(1, "rr\n", 3);
}

void	ft_rra(t_stack **stack_a, int n)
{
	t_stack *temp;
	int		i;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	i = 0;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (n == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b, int n)
{
	t_stack *temp;
	int		i;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	i = 0;
	while ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		i++;
	}
	(*stack_b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	if (n == 0)
		write(1, "rrb\n", 4);
}
