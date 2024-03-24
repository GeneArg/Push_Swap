/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:31:05 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/24 19:06:08 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_if_sorted(t_stack *stack_a)
{
	int i;

	i = stack_a->num;
	while (stack_a)
	{
		if (i > stack_a->num)
			return (0);
		i = stack_a->num;
		stack_a = stack_a->next;
	}
	return (1);
}

void free_stack(t_stack **stack)
{
	t_stack *temp;

	if (!stack)
		return;
	while (*stack)
	{
		temp = (*stack)->next;
		(*stack)->num = 0;
		free(*stack);
		*stack = temp;
	}
}

int	check_dup(t_stack *stack)
{
	t_stack *temp;

	while (stack)
	{
		temp = stack->next;
		while(temp)
		{
			if (stack->num == temp->num)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

void	free_str(char **str)
{
	char	*temp;

	if (!str)
		return ;
	while (*str)
	{
		temp = *str;
		str++;
		free(temp);
	}
	*str = NULL;
}

// Function to create a new stack node with the given number
t_stack *new_stack(int content)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error_print();
	new->num = content;
	new->next = NULL;
	return (new);
}

void 	add_back(t_stack **stack, t_stack *stack_new)
{
	int i;

	i = 0;
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}

int mod_atoi(const char *str)
{
	int sign;
	long long int i;

	sign = 1;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			error_print();
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
		error_print();
	return (sign * i);
}

t_stack *quoted_string(char **argv)
{
	t_stack *a;
	char **temp;
	int i;
	int j;

	i = 0;
	a = NULL;
	temp = ft_split(argv[1], ' ');
	while(temp[i])
	{
		j = mod_atoi(temp[i]);
		add_back(&a, new_stack(j));
		i++;
	}
	free_str(temp);
	free(temp);
	return (a);
}

// 1. To check if the number of input is less than 2.
// 2. To check if the number of input is equal to 2 - quoted string.
// 3. To check if the number of input is greater than 2 - list the arguments.

t_stack *input_process(int argc, char **argv)
{
	t_stack *a;
	int i;
	int j;

	a = NULL;
	i = 1;
	if(argc < 2)
		error_print();
	else if(argc == 2)
		a = quoted_string(argv);
	else
	{
		while (i < argc)
		{
			j = mod_atoi(argv[i]);
			add_back(&a, new_stack(j));
			i++;
		}
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = input_process(argc, argv);
	if (!a || check_dup(a))
	{
		free_stack(&a);
		error_print();
	}
	if(!check_if_sorted(a))
		// TODO: Implement sorting algorithm here
}
