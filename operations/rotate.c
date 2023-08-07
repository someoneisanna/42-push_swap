/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:47:37 by ataboada          #+#    #+#             */
/*   Updated: 2023/07/18 12:08:58 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack **sa, int p);
void	ft_rb(t_stack **sb, int p);
void	ft_rr(t_stack **sa, t_stack **sb);

void	ft_ra(t_stack **sa, int p)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *sa;
	*sa = (*sa)->next;
	last = *sa;
	while (last->next)
		last = last->next;
	temp->next = NULL;
	last->next = temp;
	if (p)
		ft_printf("ra\n");
}

void	ft_rb(t_stack **sb, int p)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *sb;
	*sb = (*sb)->next;
	last = *sb;
	while (last->next)
		last = last->next;
	temp->next = NULL;
	last->next = temp;
	if (p)
		ft_printf("rb\n");
}

void	ft_rr(t_stack **sa, t_stack **sb)
{
	ft_ra(sa, 0);
	ft_rb(sb, 0);
	ft_printf("rr\n");
}
