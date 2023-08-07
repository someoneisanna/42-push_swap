/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:43:37 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/07 16:40:06 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_perror(char *s, t_stack **sa, t_stack **sb, int ac, char **av);
void	ft_free_split(char **split);
void	ft_free_stack(t_stack **stack);
int		ft_get_size(t_stack *stack);
int		ft_get_min_max(t_stack **stack, int flag);

// this function is used to print an error message and free the stacks that had memory allocated
void	ft_perror(char *s, t_stack **sa, t_stack **sb, int ac, char **av)
{
	if (ac == 2)
		ft_free_split(av);
	if (!sa || *sa)
		ft_free_stack(sa);
	if (!sb || *sb)
		ft_free_stack(sb);
	ft_printf(s);
	exit(1);
}

// this function is used to free the split array
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// this function is used to free the stacks that had memory allocated
void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

// this function is used to get the size of the stack
int	ft_get_size(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

// this function is used to get the min or max value of the stack
int	ft_get_min_max(t_stack **stack, int flag)
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
	if (flag == MIN)
		return (min);
	return (max);
}
