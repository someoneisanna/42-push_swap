/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:35:45 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/07 16:42:17 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	this is the start of the code. it will:
	1) get the arguments, in case you use "1 2 3" and then validate them
	2) in this project, I used a linked list, and the first step is to init it
	3) we will then get its size and index it in ascending order
	4) before sorting, we will check if it is already sorted
	5) if it is not sorted, we will go to a sort function that will assign the
		sort method according to its size
	6) finally, we will free all the memory used
*/

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
	ft_fill_ind(stack_a, size);
	if (ft_is_sorted(stack_a) == 0)
		ft_sort(&stack_a, &stack_b, size);
	if (argc == 2)
		ft_free_split(argv);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
