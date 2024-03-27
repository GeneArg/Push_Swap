/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:39:25 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/26 14:00:26 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_type_ab(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	t_stack	*temp;

	temp = stack_a;
	i = case_rrarrb(stack_a, stack_b, stack_a->num);
	while (temp)
	{
		if (i > case_rarb(stack_a, stack_b, temp->num))
			i = case_rarb(stack_a, stack_b, temp->num);
		if (i > case_rrarrb(stack_a, stack_b, temp->num))
			i = case_rrarrb(stack_a, stack_b, temp->num);
		if (i > case_rarrb(stack_a, stack_b, temp->num))
			i = case_rarrb(stack_a, stack_b, temp->num);
		if (i > case_rrarb(stack_a, stack_b, temp->num))
			i = case_rrarb(stack_a, stack_b, temp->num);
		temp = temp->next;
	}
	return (i);
}

int	rotate_type_ba(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	t_stack	*temp;

	temp = stack_b;
	i = case_rrarrb_a(stack_a, stack_b, stack_b->num);
	while (temp)
	{
		if (i > case_rarb_a(stack_a, stack_b, temp->num))
			i = case_rarb_a(stack_a, stack_b, temp->num);
		if (i > case_rrarrb_a(stack_a, stack_b, temp->num))
			i = case_rrarrb_a(stack_a, stack_b, temp->num);
		if (i > case_rarrb_a(stack_a, stack_b, temp->num))
			i = case_rarrb_a(stack_a, stack_b, temp->num);
		if (i > case_rrarb_a(stack_a, stack_b, temp->num))
			i = case_rrarb_a(stack_a, stack_b, temp->num);
		temp = temp->next;
	}
	return (i);
}

int find_place_a(t_stack *stack_a, int num_push)
{
	int i;
	t_stack *temp;

	i = 1;
	if (num_push < stack_a->num && num_push > (ft_lstlast(stack_a)->num))
		i = 0;
	else if (num_push > ft_max(stack_a) || num_push < ft_min(stack_a))
		i = find_index(stack_a, ft_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->num > num_push || temp->num < num_push)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}

int find_place_b(t_stack *stack_b, int num_push)
{
	int i;
	t_stack *temp;
	t_stack *last;

	i = 1;
	last = ft_lstlast(stack_b);
	if (num_push > stack_b->num && num_push < last->num)
		i = 0;
	else if (num_push > ft_max(stack_b) || num_push < ft_min(stack_b))
		i = find_index(stack_b, ft_max(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->num < num_push || temp->num > num_push)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int find_index(t_stack *a, int num)
{
	int i;

	i = 0;
	while (a->num != num)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}
