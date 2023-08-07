/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:19:14 by ataboada          #+#    #+#             */
/*   Updated: 2023/07/19 10:23:35 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_is_sorted(t_stack *stack);
void	ft_sort(t_stack **sa, t_stack **sb, int size);
void	ft_sort_3(t_stack **sa);
void	ft_sort_5(t_stack **sa, t_stack **sb);
void	ft_sort_big(t_stack **sa, t_stack **sb);

// here we will check if the stack is already sorted
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

// here we will see which sort to use depending on the size of the stack
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

// here we will sort a stack of 3 numbers
void	ft_sort_3(t_stack **sa)
{
	int	min;
	int	max;

	min = ft_get_min_max(sa, 'i');
	max = ft_get_min_max(sa, 'a');
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

// here we will sort a stack of 5 numbers
// we basically push the min and max values to sb, sort the remaining 3 numbers
// and then push them back to sa, messing with their position
void	ft_sort_5(t_stack **sa, t_stack **sb)
{
	int	min;
	int	max;

	min = ft_get_min_max(sa, 'i');
	max = ft_get_min_max(sa, 'a');
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

// if the size is 4 or more than 5, this function will be called
// we will push everything to sb, but three numbers
// we sort these leftovers in sa
// we then calculate the best move for each number in sb and execute it
// finally, we use a final sort to put numbers in sa in order

void	ft_sort_big(t_stack **sa, t_stack **sb)
{
	ft_leave_3(sa, sb);
	ft_sort_3(sa);
	while (*sb)
	{
		ft_calculate_best_position(sa, sb);
		ft_calculate_best_move(sa, sb);
		ft_execute_best_move(sa, sb);
	}
	if (ft_is_sorted(*sa) == 0)
		ft_final_sort(sa);
}
