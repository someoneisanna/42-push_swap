/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_stack_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:59:07 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/07 11:59:04 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_fill_stack(int ac, char **av);
t_stack	*ft_add_node(int n, int ac, char **av);
void	ft_add_node_back(t_stack **stack, t_stack *new, int ac, char **av);
int		ft_get_size(t_stack *stack);
void	ft_get_index(t_stack *sa, int size);

// here we will fill the stack with the args passed to the program
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
			sa = ft_add_node(ft_atoi(av[i]), ac, av);
		else
			ft_add_node_back(&sa, ft_add_node(ft_atoi(av[i]), ac, av), ac, av);
		i++;
	}
	return (sa);
}

// here we will create a new node for the stack
t_stack	*ft_add_node(int n, int ac, char **av)
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

// here we will add a node to the back of the stack
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

// here we will get the size of the stack
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

// here we will get the index of each node in the stack (it is in ascending order)
void	ft_get_index(t_stack *sa, int size)
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
