/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sort_utils_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:33:12 by ataboada          #+#    #+#             */
/*   Updated: 2023/07/19 10:53:03 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_get_min_max(t_stack **stack, char c);
void	ft_leave_3(t_stack **sa, t_stack **sb);
void	ft_calculate_best_position(t_stack **sa, t_stack **sb);
void	ft_get_positions(t_stack **stack);
int		ft_get_best_position(t_stack **stack, int a_pos, int a_ind, int b_ind);

// here we will get the min or max number of a stack
int	ft_get_min_max(t_stack **stack, char c)
{
	t_stack	*temp;
	int		min;
	int		max;

	temp = *stack;
	min = temp->n;
	max = temp->n;
	while (temp)
	{
		if (temp->n < min)
			min = temp->n;
		if (temp->n > max)
			max = temp->n;
		temp = temp->next;
	}
	if (c == 'i')
		return (min);
	return (max);
}

// we will push all numbers but 3 to stack b
// we will first push the smallest numbers, and then the bigger ones
void	ft_leave_3(t_stack **sa, t_stack **sb)
{
	int	i;
	int	push;
	int	size;

	i = 0;
	push = 0;
	size = ft_get_size(*sa);
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*sa)->ind <= size / 2)
		{
			ft_pb(sa, sb);
			push++;
		}
		else
			ft_ra(sa, 1);
		i++;
	}
	while (size - push > 3)
	{
		ft_pb(sa, sb);
		push++;
	}
}

// first, we will fill the pos variables of the stacks
// then, we will calculate the best position for each number of sb in sa
// finally, we will fill the a_pos variables of the stacks with the best position
void	ft_calculate_best_position(t_stack **sa, t_stack **sb)
{
	int		a_pos;
	t_stack *temp_b;

	a_pos = 0;
	temp_b = *sb;
	ft_get_positions(sa);
	ft_get_positions(sb);
	while (temp_b)
	{
		a_pos = ft_get_best_position(sa, a_pos, INT_MAX, temp_b->ind);
		temp_b->a_pos = a_pos;
		temp_b = temp_b->next;
	}
}

// here we will fill the pos variable of the stack
// pos is the position of the number in the stack
// index was in ascending order, this is in the order of appearance
void	ft_get_positions(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

// here we will get the best position for a number of sb in sa
// first we will check if the index of an element of sb can be placed between elements of sa
// we will do that by checking if there are lements in a with a bigger index than the index of b
// if we didn't find it, the a_ind will be INT_MAX and we will get to the second loop
// in it, we will find the element with the smallest index and assign that as the best position
int		ft_get_best_position(t_stack **sa, int a_pos, int a_ind, int b_ind)
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
