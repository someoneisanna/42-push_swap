/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort_utils_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:33:12 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/08 16:45:01 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_leave_3(t_stack **sa, t_stack **sb);
void	ft_fill_best_position(t_stack **sa, t_stack **sb);
int		ft_find_best_position(t_stack **sa, int a_pos, int a_ind, int b_ind);
void	ft_fill_costs(t_stack **sa, t_stack **sb);
void	ft_find_and_do_best_move(t_stack **sa, t_stack **sb);

/*
	here are some of the helper functions for the big sorting algorithm
	1) ft_leave_3:
		- pushes all numbers but 3 to sb
		- for efficiency, we will push smaller values first
	2) ft_fill_best_position:
		- fill the a_pos variable of each element of sb (best pos for sb in sa)
		- we will first fill the pos variables of the stacks (ft_fill_pos)
		- then, we will calculate the best position for each number of sb in sa
		- we use (ft_get_best_position) to find that and assign that value to a_pos
	3) ft_find_best_position:
		- find the best position for the number in sb in sa
		- first, we will check if the b_index can be placed between two nbrs in sa
		- for that, we will check if there is an element in sa with a bigger index
		- if we don't find it, a_ind will be INT_MAX and we get the second loop
		- in it, we will find the nbr with the smallest ind and assign that to a_pos
	4) ft_fill_costs:
		- here we will fill the costs in the stacks
		- cost_b is the cost of getting the number to the top of sb
		- cost_a is the cost of getting the number to the right place in sa
		- the cost will be positive if the element is in the bottom half of the stack
		- the cost will be negative if it is in the top half
	5) ft_find_best_move:
		- here we will find the best move for each element of sb (cheapest move)
		- it will look for the element in stack b with the lowest cost
		- after that, it will move it to the correct position in sa
		- if the costs are both negative or both positive, we will rrr or rr
		- else, we will rotate the stacks depending on the sign of the cost
		- after the rotations are done, we will push the element to sa
*/

void	ft_leave_3(t_stack **sa, t_stack **sb)
{
	int	i;
	int	pushed;
	int	size;

	i = 0;
	pushed = 0;
	size = ft_get_size(*sa);
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*sa)->ind <= size / 2)
		{
			ft_pb(sa, sb);
			pushed++;
		}
		else
			ft_ra(sa, 1);
		i++;
	}
	while (size - pushed > 3)
	{
		ft_pb(sa, sb);
		pushed++;
	}
}

void	ft_fill_best_position(t_stack **sa, t_stack **sb)
{
	int		a_pos;
	t_stack	*temp_b;

	a_pos = 0;
	temp_b = *sb;
	ft_fill_pos(sa);
	ft_fill_pos(sb);
	while (temp_b)
	{
		a_pos = ft_find_best_position(sa, a_pos, INT_MAX, temp_b->ind);
		temp_b->a_pos = a_pos;
		temp_b = temp_b->next;
	}
}

int	ft_find_best_position(t_stack **sa, int a_pos, int a_ind, int b_ind)
{
	t_stack	*temp_a;

	temp_a = *sa;
	while (temp_a)
	{
		if (temp_a->ind > b_ind && temp_a->ind < a_ind)
		{
			a_ind = temp_a->ind;
			a_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (a_ind != INT_MAX)
		return (a_pos);
	temp_a = *sa;
	while (temp_a)
	{
		if (temp_a->ind < a_ind)
		{
			a_ind = temp_a->ind;
			a_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (a_pos);
}

void	ft_fill_costs(t_stack **sa, t_stack **sb)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		a_size;
	int		b_size;

	temp_a = *sa;
	temp_b = *sb;
	a_size = ft_get_size(temp_a);
	b_size = ft_get_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > b_size / 2)
			temp_b->cost_b = (b_size - temp_b->pos) * (-1);
		temp_b->cost_a = temp_b->a_pos;
		if (temp_b->a_pos > a_size / 2)
			temp_b->cost_a = (a_size - temp_b->a_pos) * (-1);
		temp_b = temp_b->next;
	}
}

void	ft_find_and_do_best_move(t_stack **sa, t_stack **sb)
{
	t_stack	*t;
	int		best_a;
	int		cost_a;
	int		cost_b;

	t = *sb;
	best_a = INT_MAX;
	while (t)
	{
		if (ft_abs(t->cost_a) + ft_abs(t->cost_b) < ft_abs(best_a))
		{
			best_a = ft_abs(t->cost_a) + ft_abs(t->cost_b);
			cost_a = t->cost_a;
			cost_b = t->cost_b;
		}
		t = t->next;
	}
	if (cost_a < 0 && cost_b < 0)
		ft_rrr_with_cost(sa, sb, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rr_with_cost(sa, sb, &cost_a, &cost_b);
	ft_ra_with_cost(sa, &cost_a);
	ft_rb_with_cost(sb, &cost_b);
	ft_pa(sa, sb);
}
