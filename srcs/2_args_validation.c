/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_args_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:01:32 by ataboada          #+#    #+#             */
/*   Updated: 2023/08/07 11:57:19 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include "../push_swap.h"

void	ft_args_validation(int ac, char **av);
int		ft_is_num(char *s);
int		ft_is_int(char *s);
int		ft_is_dup(char **args, int i);

// here we will check if the arguments are valid
// we will check if there are only numbers, if they are int (and not longs) and if there are duplicates
void	ft_args_validation(int ac, char **av)
{
	int		i;

	if (ac < 2)
		ft_perror("Error: wrong number of arguments\n", NULL, NULL, ac, av);
	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		if (ft_is_num(av[i]) == 0)
			ft_perror("Error: argument has a character that is not a number\n", NULL, NULL, ac, av);
		if (ft_is_int(av[i]) == 0)
			ft_perror("Error: argument has a characater that is not an integer\n", NULL, NULL, ac, av);
		if (ft_is_dup(av, i) == 0)
			ft_perror("Error: argument has one or more duplicates\n", NULL, NULL, ac, av);
		i++;
	}
}

// here we check if all args are numbers
int	ft_is_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// here we check if all args are integers (and not longs)
// obs: we can't use atoi - it returns a random int if you pass overflow values
int	ft_is_int(char *s)
{
	int		i;
	int		sig;
	long	res;

	i = 0;
	res = 0;
	sig = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sig = -1;
		i++;
	}
	while (ft_isdigit(s[i]) && s[i])
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sig;
	return (res >= INT_MIN && res <= INT_MAX);
}

// here we check if there are duplicate args
int	ft_is_dup(char **args, int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atoi(args[i]) == ft_atoi(args[j]))
			return (0);
		j++;
	}
	return (1);
}
