/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:35:51 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/27 17:17:54 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/push_swap.h"

void	case_rr(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 1);
	else if (line[2] == 'b')
		ft_rrb(b, 1);
	else if (line[2] == 'r')
		ft_rrr(a, b, 1);
}

char	*checker_read_line(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		case_rr(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(a, b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 1);
	else
		error_print();
	return (get_next_line(0));
}

void	checker_validation(t_stack **a, t_stack **b, char *line)
{
	char *temp;

	while (!check_if_sorted(*a) || (line && *line != '\n'))
	{
		temp = line;
		line = checker_read_line(a, b, line);
		free(temp);
	}
	if (*b || !check_if_sorted(*a))
		write(1, "KO\n", 3);
	else if (!*b && check_if_sorted(*a))
		write(1, "OK\n", 3);
	free(line);
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = input_process(argc, argv);
	stack_b = NULL;
	if (!stack_a || check_dup(stack_a))
	{
		free_stack(&stack_a);
		error_print();
	}
	line = get_next_line(0);
	if (!line && !check_if_sorted(stack_a))
		write(1, "KO\n", 3);
	else if (!line && check_if_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		checker_validation(&stack_a, &stack_b, line);
	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}
