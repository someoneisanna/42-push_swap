/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:41:41 by ataboada          #+#    #+#             */
/*   Updated: 2023/07/18 12:13:11 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack *sa, int p);
void	ft_sb(t_stack *sb, int p);
void	ft_ss(t_stack **sa, t_stack **sb);

void	ft_sa(t_stack *sa, int p)
{
	int	temp;

	if (!sa || !sa->next)
		return ;
	temp = sa->n;
	sa->n = sa->next->n;
	sa->next->n = temp;
	temp = sa->ind;
	sa->ind = sa->next->ind;
	sa->next->ind = temp;
	if (p == 1)
		ft_printf("sa\n");
}

void	ft_sb(t_stack *sb, int p)
{
	int	temp;

	if (!sb || !sb->next)
		return ;
	temp = sb->n;
	sb->n = sb->next->n;
	sb->next->n = temp;
	temp = sb->ind;
	sb->ind = sb->next->ind;
	sb->next->ind = temp;
	if (p == 1)
		ft_printf("sb\n");
}

void	ft_ss(t_stack **sa, t_stack **sb)
{
	ft_sa(*sa, 0);
	ft_sb(*sb, 0);
	ft_printf("ss\n");
}
