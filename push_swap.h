#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
	long num;
	long index;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

void	error_print(void);
t_stack *input_process(int argc, char **argv);
t_stack *quoted_string(char **argv);
int mod_atoi(const char *str);
void add_back(t_stack **stack, t_stack *stack_new);
t_stack *new_stack(int content);
void free_str(char **str);
int	check_dup(t_stack *stack);
void free_stack(t_stack **stack);
int		check_if_sorted(t_stack *stack_a);
t_stack ft_lstlast(t_stack *stack);
int ft_lstsize(t_stack *stack);
int ft_min(t_stack *stack_a);
int ft_max(t_stack *stack_a);

#endif
