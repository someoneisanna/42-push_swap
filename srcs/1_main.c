/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:35:45 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/07 11:56:28 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_perror(char *s, t_stack **sa, t_stack **sb, int ac, char **av);
void	ft_free_stack(t_stack **stack);
void	ft_free_split(char **split);

int		main(int argc, char **argv)
{
	int			size;
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_args_validation(argc, argv);
	stack_a = ft_fill_stack(argc, argv);
	stack_b = NULL;
	size = ft_get_size(stack_a);
	ft_get_index(stack_a, size);
	if (ft_is_sorted(stack_a) == 1)
		return (0);
	ft_sort(&stack_a, &stack_b, size);
	if (argc == 2)
		ft_free_split(argv);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

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
