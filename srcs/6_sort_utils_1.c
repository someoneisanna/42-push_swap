/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:56:37 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/07 11:11:54 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_calculate_best_move(t_stack **sa, t_stack **sb);
void	ft_execute_best_move(t_stack **sa, t_stack **sb);
void	ft_call_best_functions(t_stack **sa, t_stack **sb, int cost_a, int cost_b);
void	ft_rev_rotate_both(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b);
void	ft_rotate_both(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b);
void	ft_rotate_a(t_stack **sa, int *cost);
void	ft_rotate_b(t_stack **sb, int *cost);

// here we will fill the costs in the stacks
// cost_b is the cost of getting the number to the top of stack b
// cost_a is the cost of getting the number to the right place in stack a
// the cost will be positive if the element is in the bottom half of the stack, and
// negative if it is in the top half
void	ft_calculate_best_move(t_stack **sa, t_stack **sb)
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

// it will look for the element in stack b with the lowest cost
// after that, it will move it to the correct position in stack a
void	ft_execute_best_move(t_stack **sa, t_stack **sb)
{
	t_stack	*temp;
	int		best_a;
	int		cost_a;
	int		cost_b;

	temp = *sb;
	best_a = INT_MAX;
	while (temp)
	{
		if (ft_absolute(temp->cost_a) + ft_absolute(temp->cost_b) < ft_absolute(best_a))
		{
			best_a = ft_absolute(temp->cost_a) + ft_absolute(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	ft_call_best_functions(sa, sb, cost_a, cost_b);
}

// here we will choose which move to make depending on the cost
// if the costs are both positive or both negative, we will rotate the stacks at the same time
// else, we will rotate the stacks depending on the sign of the cost
// after all those rotations are done, we will push the top number in sb to sa
void	ft_call_best_functions(t_stack **sa, t_stack **sb, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		ft_rev_rotate_both(sa, sb, &cost_a, &cost_b);
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		ft_rotate_both(sa, sb, &cost_a, &cost_b);
	}
	ft_rotate_a(sa, &cost_a);
	ft_rotate_b(sb, &cost_b);
	ft_pa(sa, sb);
}

void	ft_rev_rotate_both(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(sa, sb);
	}
}

void	ft_rotate_both(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(sa, sb);
	}
}

// here we will rotate stack a depending on the cost
void	ft_rotate_a(t_stack **sa, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_ra(sa, 1);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rra(sa, 1);
			(*cost)++;
		}
	}
}

// here we will rotate stack b depending on the cost
void	ft_rotate_b(t_stack **sb, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rb(sb, 1);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrb(sb, 1);
			(*cost)++;
		}
	}
}
