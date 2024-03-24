#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"


typedef struct s_stack
{
	long num;
	long index;
	struct s_stack *next;
	struct s_stack *index;
} t_stack;

void	error_print(void);
t_stack *input_process(int argc, char **argv);

#endif
