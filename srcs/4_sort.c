/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:19:14 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/07 16:24:50 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_is_sorted(t_stack *stack);
void	ft_sort(t_stack **sa, t_stack **sb, int size);
void	ft_sort_3(t_stack **sa);
void	ft_sort_5(t_stack **sa, t_stack **sb);
void	ft_sort_big(t_stack **sa, t_stack **sb);

/*
	this is where the main sort functions are
	1) ft_is_sorted: checks if the stack is already sorted
	2) ft_sort: decides which sort to use depending on the size of the stack
		- ft_sort_3: sorts a stack of 3 numbers
		- ft_sort_5: sorts a stack of 5 numbers
		- ft_sort_big: sorts a stack of more than 5 numbers
*/

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort(t_stack **sa, t_stack **sb, int size)
{
	if (size == 2)
		ft_sa(*sa, 1);
	else if (size == 3)
		ft_sort_3(sa);
	else if (size == 5)
		ft_sort_5(sa, sb);
	else
		ft_sort_big(sa, sb);
}

void	ft_sort_3(t_stack **sa)
{
	int	min;
	int	max;

	min = ft_get_min_max(sa, MIN);
	max = ft_get_min_max(sa, MAX);
	if ((*sa)->n == max && (*sa)->next->n != min)
	{
		ft_sa(*sa, 1);
		ft_rra(sa, 1);
	}
	if ((*sa)->n == max && (*sa)->next->n == min)
		ft_ra(sa, 1);
	if ((*sa)->n != max && (*sa)->next->n == min)
		ft_sa(*sa, 1);
	if ((*sa)->n != min && (*sa)->next->n == max)
		ft_rra(sa, 1);
	if ((*sa)->n == min && (*sa)->next->n == max)
	{
		ft_sa(*sa, 1);
		ft_ra(sa, 1);
	}
}

void	ft_sort_5(t_stack **sa, t_stack **sb)
{
	int	min;
	int	max;

	min = ft_get_min_max(sa, MIN);
	max = ft_get_min_max(sa, MAX);
	while (ft_get_size(*sa) > 3)
	{
		if ((*sa)->n == min || (*sa)->n == max)
			ft_pb(sa, sb);
		else
			ft_ra(sa, 1);
	}
	ft_sort_3(sa);
	ft_pa(sa, sb);
	if (ft_is_sorted(*sa) == 1)
	{
		ft_pa(sa, sb);
		ft_ra(sa, 1);
	}
	else
	{
		ft_ra(sa, 1);
		ft_pa(sa, sb);
	}
}

/*
	this is the main sort function for stacks of more than 5 numbers (or 4 numbers)
	1) ft_leave_3: pushes everything to sb, but three numbers
	2) ft_sort_3: sorts the three numbers that were left in sa
	3) ft_calculate_best_position: calculates the best position for each number in sb
	4) ft_calculate_best_move: calculates the best move for each number in sb
	5) ft_execute_best_move: executes the best move for each number in sb
	6) ft_final_sort: sorts the numbers in sa in order
*/

void	ft_sort_big(t_stack **sa, t_stack **sb)
{
	ft_leave_3(sa, sb);
	ft_sort_3(sa);
	while (*sb)
	{
		ft_fill_best_position(sa, sb);
		ft_fill_costs(sa, sb);
		ft_find_and_do_best_move(sa, sb);
	}
	if (ft_is_sorted(*sa) == 0)
		ft_final_sort(sa);
}
