/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:06 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/26 14:00:20 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotates both stack_a and stack_b in the same direction as required amount.
int	apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c && find_place_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)->num != c)
			ft_ra(a, 0);
		while (find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->num != c && find_place_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)->num != c)
			ft_rb(b, 0);
		while (find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c && find_place_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->num != c)
			ft_rra(a, 0);
		while (find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->num != c && find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->num != c)
			ft_rrb(b, 0);
		while (find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c)
			ft_rra(a, 0);
		while (find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b)->num != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c)
			ft_ra(a, 0);
		while (find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		while ((*b)->num != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}
