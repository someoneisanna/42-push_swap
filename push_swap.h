/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:24:54 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/07 11:58:20 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				n;
	int				ind;
	int				pos;
	int				a_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// --------------------------------- 1_main.c ----------------------------------

void	ft_perror(char *s, t_stack **sa, t_stack **sb, int ac, char **av);
void	ft_free_stack(t_stack **stack);
void	ft_free_split(char **split);

// ---------------------------- 2_args_validation.c ----------------------------

void	ft_args_validation(int ac, char **av);
int		ft_is_num(char *s);
int		ft_is_int(char *s);
int		ft_is_dup(char **args, int i);

// ------------------------------ 3_stack_init.c -------------------------------

t_stack	*ft_fill_stack(int ac, char **av);
t_stack	*ft_add_node(int n, int ac, char **av);
void	ft_add_node_back(t_stack **stack, t_stack *new, int ac, char **av);
int		ft_get_size(t_stack *stack);
void	ft_get_index(t_stack *sa, int size);

// -------------------------------- 4_sort.c -----------------------------------

int		ft_is_sorted(t_stack *stack);
void	ft_sort(t_stack **sa, t_stack **sb, int size);
void	ft_sort_3(t_stack **sa);
void	ft_sort_5(t_stack **sa, t_stack **sb);
void	ft_sort_big(t_stack **sa, t_stack **sb);

// ------------------------------ 5_sort_utils_0.c -----------------------------

int		ft_get_min_max(t_stack **stack, char c);
void	ft_leave_3(t_stack **sa, t_stack **sb);
void	ft_calculate_best_position(t_stack **sa, t_stack **sb);
void	ft_get_positions(t_stack **stack);
int		ft_get_best_position(t_stack **stack, int a_pos, int a_ind, int b_ind);

// ------------------------------ 6_sort_utils_1.c -----------------------------


void	ft_calculate_best_move(t_stack **sa, t_stack **sb);
void	ft_execute_best_move(t_stack **sa, t_stack **sb);
void	ft_call_best_functions(t_stack **sa, t_stack **sb, int cost_a, int cost_b);
void	ft_rev_rotate_both(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b);
void	ft_rotate_both(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b);
void	ft_rotate_a(t_stack **sa, int *cost);
void	ft_rotate_b(t_stack **sb, int *cost);

// ------------------------------ 7_sort_utils_2.c -----------------------------

void	ft_final_sort(t_stack **sa);
int		ft_get_lowest_pos(t_stack **stack);
int		ft_absolute(int n);

// --------------------------------- OPERATIONS --------------------------------

void	ft_pa(t_stack **sa, t_stack **sb);
void	ft_pb(t_stack **sa, t_stack **sb);
void	ft_rra(t_stack **sa, int p);
void	ft_rrb(t_stack **sb, int p);
void	ft_rrr(t_stack **sa, t_stack **sb);
void	ft_ra(t_stack **sa, int p);
void	ft_rb(t_stack **sb, int p);
void	ft_rr(t_stack **sa, t_stack **sb);
void	ft_sa(t_stack *sa, int p);
void	ft_sb(t_stack *sb, int p);
void	ft_ss(t_stack **sa, t_stack **sb);

#endif

