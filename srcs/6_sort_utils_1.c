/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:56:37 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/08 16:45:21 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_abs(int n);
void	ft_rrr_with_cost(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b);
void	ft_rr_with_cost(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b);
void	ft_ra_with_cost(t_stack **sa, int *cost);
void	ft_rb_with_cost(t_stack **sb, int *cost);

/*
	here we've got the functions that are useful to find and do the best move
	1) ft_abs: returns the absolute value of a number
	2) ft_rrr_with_cost: rotates both stacks in opposite directions
	3) ft_rr_with_cost: rotates both stacks in the same direction
	4) ft_ra_with_cost: depending on the sign of cost, rotates sa to top or bottom
	5) ft_rb_with_cost: depending on the sign of cost, rotates sb to top or bottom
*/

int	ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

void	ft_rrr_with_cost(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(sa, sb);
	}
}

void	ft_rr_with_cost(t_stack **sa, t_stack **sb, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(sa, sb);
	}
}

void	ft_ra_with_cost(t_stack **sa, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ft_ra(sa, 1);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			ft_rra(sa, 1);
		}
	}
}

void	ft_rb_with_cost(t_stack **sb, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ft_rb(sb, 1);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			ft_rrb(sb, 1);
		}
	}
}
