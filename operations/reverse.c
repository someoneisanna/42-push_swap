/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:50:28 by ataboada          #+#    #+#             */
/*   Updated: 2023/07/18 12:08:40 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stack **sa, int p);
void	ft_rrb(t_stack **sb, int p);
void	ft_rrr(t_stack **sa, t_stack **sb);

void	ft_rra(t_stack **sa, int p)
{
	t_stack	*temp;
	t_stack	*new_last;
	t_stack *prev_last;

	temp = *sa;
	new_last = *sa;
	prev_last = *sa;
	while (prev_last->next)
		prev_last = prev_last->next;
	while (new_last->next->next)
		new_last = new_last->next;
	*sa = prev_last;
	(*sa)->next = temp;
	new_last->next = NULL;
	if (p == 1)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack **sb, int p)
{
	t_stack	*temp;
	t_stack	*new_last;
	t_stack *prev_last;

	temp = *sb;
	new_last = *sb;
	prev_last = *sb;
	while (prev_last->next)
		prev_last = prev_last->next;
	while (new_last->next->next)
		new_last = new_last->next;
	*sb = prev_last;
	(*sb)->next = temp;
	new_last->next = NULL;
	if (p == 1)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack **sa, t_stack **sb)
{
	ft_rra(sa, 0);
	ft_rrb(sb, 0);
	ft_printf("rrr\n");
}
