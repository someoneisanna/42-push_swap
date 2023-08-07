/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_sort_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:12:27 by ataboada          #+#    #+#             */
/*   Updated: 2023/07/19 14:17:39 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_final_sort(t_stack **sa);
int		ft_get_lowest_pos(t_stack **stack);
int		ft_absolute(int n);

// after the stack is mostly sorted, we will use this sort to make sure the lowest value is at the top
// if it is in the bottom of the stack, we will reverse rotate it to the top
// if it is in the top of the stack, we will rotate it to the top
void	ft_final_sort(t_stack **sa)
{
	int	size;
	int	lowest_pos;

	size = ft_get_size(*sa);
	lowest_pos = ft_get_lowest_pos(sa);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			ft_rra(sa, 1);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_ra(sa, 1);
			lowest_pos--;
		}
	}
}

// here we will get the position of the lowest number in the stack
int	ft_get_lowest_pos(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_ind;
	int		lowest_pos;

	temp = *stack;
	lowest_ind = INT_MAX;
	ft_get_positions(stack);
	lowest_pos = temp->pos;
	while (temp)
	{
		if (temp->ind < lowest_ind)
		{
			lowest_ind = temp->ind;
			lowest_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (lowest_pos);
}

// here we will get the absolute value of a number
int	ft_absolute(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}
