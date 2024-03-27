/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:35:45 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/26 14:54:35 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sorts the stack
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
		i = find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->num != ft_min(*stack_a))
				ft_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->num != ft_min(*stack_a))
				ft_rra(stack_a, 0);
		}
	}
}

// pushing back the elements from stack_b to stack_a until stack_b is empty
t_stack **sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	t_stack *temp;

	while(*stack_b)
	{
		temp = *stack_b;
		i = rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb_a(*stack_a, *stack_b, temp->num))
				i = apply_rarb(stack_a, stack_b, temp->num, 'b');
			else if (i == case_rarrb_a(*stack_a, *stack_b, temp->num))
				i = apply_rarrb(stack_a, stack_b, temp->num, 'b');
			else if (i == case_rrarrb_a(*stack_a, *stack_b, temp->num))
				i = apply_rrarrb(stack_a, stack_b, temp->num, 'b');
			else if (i == case_rrarb_a(*stack_a, *stack_b, temp->num))
				i = apply_rrarb(stack_a, stack_b, temp->num, 'b');
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}

// pushes to b until there are 3 elements in a.
// while pushing to b, it sorts the stack b.
// after that, it sorts the stack a.
t_stack *sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !check_if_sorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !check_if_sorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !check_if_sorted(*stack_a))
		sort_b_till_3(stack_a, &stack_b);
	if (!check_if_sorted(*stack_a))
		sort_3(stack_a);
	return (stack_b);
}

// sort and push stacks until there are 3 elements in stack a.
void 	sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	t_stack	*temp;

	while(ft_lstsize(*stack_a) > 3 && !check_if_sorted(*stack_a))
	{
		temp = *stack_a;
		i = rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb(*stack_a, *stack_b, temp->num))
				i = apply_rarb(stack_a, stack_b, temp->num, 'a');
			else if (i == case_rrarrb(*stack_a, *stack_b, temp->num))
				i = apply_rrarrb(stack_a, stack_b, temp->num, 'a');
			else if (i == case_rarrb(*stack_a, *stack_b, temp->num))
				i = apply_rarrb(stack_a, stack_b, temp->num, 'a');
			else if (i == case_rrarb(*stack_a, *stack_b, temp->num))
				i = apply_rrarb(stack_a, stack_b, temp->num, 'a');
			else
				temp = temp->next;
		}
	}
}

// sort if there are 3 elements in stack a
void	sort_3(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->num)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ft_max(*stack_a) == (*stack_a)->num)
	{
		ft_ra(stack_a, 0);
		if (!check_if_sorted(*stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		if (find_index(*stack_a, ft_max(*stack_a)) == 1)
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a, 0);
	}
}
