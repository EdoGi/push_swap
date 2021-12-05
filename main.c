/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:27:47 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/05 22:13:32 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fill_stack_a(t_stack *aroot, char *val)
{
	long	nbr;

	if (!(ft_isnumber(val)))
		return (0);
	nbr = ft_atoi(val);
	printf("for %ld test 1 ok\n", nbr);
	if (ft_exist(aroot, nbr) || ft_islong(nbr))
		return (0);
	printf("for %ld test 2 ok\n", nbr);
	ft_stkadd_top(aroot, NULL, nbr, NULL);
	return (1);
}

t_stack	*ft_setup(int ac, char **av, t_stack *aroot, t_stack *broot)
{
	int		i;
	t_stack	*mv;

	if (ac < 2)
		return (0);
	i = ac;
	mv = ft_createstk();
	while (--i > 0)
	{
		if (!(ft_fill_stack_a(aroot, av[i])))
		{
			ft_putstr_fd("Error\n", 2);
			ft_stkclean(broot);
			ft_stkclean(aroot);
			ft_stkclean(mv);
			return (0);
		}
	}
	ft_setidx(aroot);
	return (mv);
}

int	main(int ac, char **av)
{
	t_stack	*aroot;
	t_stack	*broot;
	t_stack	*mv;
	t_stack	*it;

	aroot = ft_createstk();
	broot = ft_createstk();
	if (!(aroot) || !(broot))
		return (0);
	mv = ft_setup(ac, av, aroot, broot);
	if (!mv)
		return (0);
	ft_set_rank(aroot);
	printf("\n%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d with rank : %d\n", it->nbr, it->idx, it->rank);
	ft_stk_supercleaner(mv, broot, aroot, NULL);
}

/*
	ft_stkadd_top(broot, NULL, 75, NULL);
	printf("\n%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d\n", it->nbr, it->idx);
	mv_push(broot, aroot, mv, 'a');
	printf("\nPUSH : %d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d\n", it->nbr, it->idx);
	mv_rotate(aroot, mv, 'a');
	printf("\nROTATE : %d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d\n", it->nbr, it->idx);
	mv_swap(aroot, mv, 'a');
	printf("\nSWAP : %d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d\n", it->nbr, it->idx);
	mv_reverse_rotate(aroot, mv, 'a');
	printf("\nREVERSE R : %d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d\n", it->nbr, it->idx);
	printf("\nMOOVES :\n");
	for (it = mv->next ; it != mv ; it = it->next)
		printf("%s\n", it->mv);
*/