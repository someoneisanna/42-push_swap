/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:39:15 by ataboada          #+#    #+#             */
/*   Updated: 2023/07/18 12:07:37 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_stack **sa, t_stack **sb);
void	ft_pb(t_stack **sa, t_stack **sb);

void	ft_pa(t_stack **sa, t_stack **sb)
{
	t_stack	*temp;

	if (!*sb)
		return ;
	temp = *sb;
	*sb = (*sb)->next;
	temp->next = *sa;
	*sa = temp;
	ft_printf("pa\n");
}

void	ft_pb(t_stack **sa, t_stack **sb)
{
	t_stack	*temp;

	if (!*sa)
		return ;
	temp = *sa;
	*sa = (*sa)->next;
	temp->next = *sb;
	*sb = temp;
	ft_printf("pb\n");
}
