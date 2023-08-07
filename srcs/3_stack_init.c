/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_stack_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:59:07 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/07 15:24:50 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_fill_stack(int ac, char **av);
t_stack	*ft_add_new_node(int n, int ac, char **av);
void	ft_add_node_back(t_stack **stack, t_stack *new, int ac, char **av);
void	ft_fill_ind(t_stack *sa, int size);
void	ft_fill_pos(t_stack **sa);

/*
	this is where we initialize some values of the stack:
	1) we fill the stack with the args passed to the program with the help of:
		- ft_add_new_node: to create a new node
		- ft_add_node_back: to add that new node to the end of the stack
	2) we fill the stack with an index of each node (in ascending order)
	3) we fill the stack with the position of each node
		- while the index was filled in the values ascending order, the pos
		  is filled in the order of appearance of the values in the args
*/

t_stack	*ft_fill_stack(int ac, char **av)
{
	int		i;
	t_stack	*sa;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	sa = NULL;
	while (av[i])
	{
		if ((ac == 2 && i == 0) || (ac != 2 && i == 1))
			sa = ft_add_new_node(ft_atoi(av[i]), ac, av);
		else
			ft_add_node_back(&sa, ft_add_new_node(ft_atoi(av[i]), ac, av), ac, av);
		i++;
	}
	return (sa);
}

t_stack	*ft_add_new_node(int n, int ac, char **av)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		ft_perror("Error\nMalloc failure in ft_add_node\n", NULL, NULL, ac, av);
	node->n = n;
	node->ind = 0;
	node->pos = -1;
	node->a_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

void	ft_add_node_back(t_stack **stack, t_stack *new, int ac, char **av)
{
	t_stack	*last;

	if (!stack)
		ft_perror("Error\nNull pointer in ft_add_node_back\n", NULL, NULL, ac, av);
	if (!*stack)
		*stack = new;
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	ft_fill_ind(t_stack *sa, int size)
{
	int		max;
	t_stack	*tmp;
	t_stack	*biggest;

	while (size--)
	{
		max = INT_MIN;
		tmp = sa;
		biggest = NULL;
		while (tmp)
		{
			if (tmp->n == INT_MIN && tmp->ind == 0)
				tmp->ind = 1;
			else if (tmp->n > max && tmp->ind == 0)
			{
				max = tmp->n;
				biggest = tmp;
				tmp = sa;
			}
			else
				tmp = tmp->next;
		}
		if (biggest)
			biggest->ind = size + 1;
	}
}

void	ft_fill_pos(t_stack **stack)
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
