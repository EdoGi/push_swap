/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:27:47 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/05 15:43:57 by egiacomi         ###   ########.fr       */
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
	ft_stkadd_top(aroot, NULL, nbr, NULL);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*aroot;
	t_stack	*broot;
	t_stack	*it;
	t_stack	*mv;
	int		i;

	if (ac < 2)
		return (0);
	i = ac;
	aroot = ft_createstk();
	broot = ft_createstk();
	mv = ft_createstk();
	while (--i > 0)
	{
		if (!(ft_fill_stack_a(aroot, av[i])))
		{
			ft_putstr_fd("Error\n", 2);
			ft_stkclean(broot);
			ft_stkclean(aroot);
			return (0);
		}
	}
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	ft_stkclean(mv);
	ft_stkclean(broot);
	ft_stkclean(aroot);
}
