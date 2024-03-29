/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:57:51 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/28 12:11:10 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to create a new stack node with the given number
t_stack	*new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error_print();
	new->num = content;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}

int	mod_atoi(const char *str)
{
	int				sign;
	long long int	i;

	sign = 1;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
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

t_stack	*quoted_string(char **argv)
{
	t_stack	*a;
	char	**temp;
	int		i;
	int		j;

	i = 0;
	a = NULL;
	temp = ft_split(argv[1], ' ');
	while (temp[i])
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
t_stack	*input_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	if (argc < 2)
		error_print();
	check_sign(argv);
	if (argc == 2)
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
