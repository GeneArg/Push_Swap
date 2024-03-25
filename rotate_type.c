/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:39:25 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/25 13:28:25 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_type_ba(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	t_stack	*temp;

	temp = stack_b;
	i = case_rrarrb_a(stack_a, stack_b, stack_b->num);
}

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

int find_place_a(t_stack *stack_a, int num_push)
{
	int i;
	t_stack *temp;

	i = 1;
	if (num_push < stack_a->num && num_push > (ft_lstlast(stack_a)).num)
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

	i = 1;
	if (num_push > stack_b->num && num_push < (ft_lstlast(stack_b)).num)
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