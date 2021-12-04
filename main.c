/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:27:47 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/04 23:08:15 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fill_stack_a(t_stack *aroot, char *val)
{
	long	nbr;

	if (!(ft_isnumber(val)))
		return (0);
	nbr = ft_atoi(val);
	if (ft_exist(aroot, nbr) || ft_islong(nbr))
		return (0);
	ft_stkadd_top(aroot, NULL, nbr);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*aroot;
	t_stack	*broot;
	int		i;

	if (ac < 2)
		return (0);
	printf("there are %d arguments\n", ac);
	i = ac;
	aroot = ft_createstk();
	broot = ft_createstk();
	while (--i > 0)
	{
		printf("arg %d is %s\n", i, av[i]);
		if (!(ft_fill_stack_a(aroot, av[i])))
		{
			ft_putstr_fd("Error", 2);
			ft_stkclean(broot);
			ft_stkclean(aroot);
			return (0);
		}
	}
	ft_stkclean(broot);
	ft_stkclean(aroot);
}
