/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:23:20 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/04 23:03:16 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		ret = ret * 10 + (nptr[i] - '0');
		i++;
	}
	if (ret > 9223372036854775807)
		return (-1);
	return (ret * sign);
}

int	ft_isnumber(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exist(t_stack *aroot, int nbr)
{
	t_stack	*it;

	it = aroot->next;
	while (it != aroot)
	{
		if (nbr == it->nbr)
			return (1);
		it = it->next;
	}
	return (0);
}

int	ft_islong(long nbr)
{
	if ((nbr > INT_MAX) || (nbr < 0))
		return (1);
	return (0);
}
