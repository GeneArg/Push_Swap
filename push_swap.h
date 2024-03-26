/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:41:44 by eagranat          #+#    #+#             */
/*   Updated: 2024/03/26 14:50:19 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_stack
{
	long num;
	long index;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

int	case_rarb(t_stack *stack_a, t_stack *stack_b, int num_push);
int	case_rrarrb(t_stack *stack_a, t_stack *stack_b, int num_push);
int	case_rrarb(t_stack *stack_a, t_stack *stack_b, int num_push);
int	case_rarrb(t_stack *stack_a, t_stack *stack_b, int num_push);
int case_rrarrb_a(t_stack *a, t_stack *b, int c);
int case_rarb_a(t_stack *stack_a, t_stack *stack_b, int num_push);
int	case_rarrb_a(t_stack *stack_a, t_stack *stack_b, int num_push);
int	case_rrarb_a(t_stack *stack_a, t_stack *stack_b, int num_push);
int	sign(int c);
int	digit(int c);
int	space(int c);
int	check_error(char **argv, int i, int j);
void	list_args(char **argv, t_stack **stack_a);
int	ft_isalpha(int c);
void	alpha_check(char **argv);
int	check_args(char **argv);
void	error_print(void);
void free_stack(t_stack **stack);
void	free_str(char **str);
t_stack *ft_parse(int argc, char **argv);
t_stack *parse_quoted(char **argv);
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int n);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int n);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int n);
int		check_if_sorted(t_stack *stack_a);
int	check_dup(t_stack *stack);
t_stack *new_stack(int content);
void 	add_back(t_stack **stack, t_stack *stack_new);
int mod_atoi(const char *str);
t_stack *quoted_string(char **argv);
t_stack *input_process(int argc, char **argv);
void	ft_ra(t_stack **stack_a, int n);
void	ft_rb(t_stack **stack_b, int n);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int n);
void	ft_rra(t_stack **stack_a, int n);
void	ft_rrb(t_stack **stack_b, int n);
int	apply_rarb(t_stack **a, t_stack **b, int c, char s);
int	apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int	apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int	apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int	rotate_type_ab(t_stack *stack_a, t_stack *stack_b);
int	rotate_type_ba(t_stack *stack_a, t_stack *stack_b);
int find_place_a(t_stack *stack_a, int num_push);
int find_place_b(t_stack *stack_b, int num_push);
int find_index(t_stack *a, int num);
void	sort_stack(t_stack **stack_a);
t_stack **sort_a(t_stack **stack_a, t_stack **stack_b);
t_stack *sort_b(t_stack **stack_a);
void 	sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);
t_stack *ft_lstlast(t_stack *stack);
int ft_lstsize(t_stack *stack);
int ft_min(t_stack *stack_a);
int ft_max(t_stack *stack_a);
void	ft_sa(t_stack **stack_a, int n);
void	ft_sb(t_stack **stack_b, int n);
void 	ft_ss(t_stack **stack_a, t_stack **stack_b, int n);

#endif
