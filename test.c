/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:54:14 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/05 15:40:30 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	int		a;
	int		b;
	int		c;
	t_stack	*aroot;
	t_stack	*broot;
	t_stack	*it;
	t_stack *mv;

	(void)ac;
	a = atoi(av[1]);
	b = atoi(av[2]);
	c = atoi(av[3]);
	aroot = ft_createstk();
	broot = ft_createstk();
	mv = ft_createstk();

	ft_stkadd_top(aroot, NULL, a, NULL);
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	
	ft_stkadd_top(aroot, NULL, b, NULL);
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	
	ft_stkadd_bot(aroot, NULL, c, NULL);
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	
	ft_delstk(aroot->next, aroot);
	printf("%d aroot numbers\n", aroot->nbr);	
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	
	mv_swap(aroot, mv, 'a');
	printf("swapping\n");
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);

	// printf("%d aroot numbers\n", aroot->nbr);	
	// printf("%d broot numbers\n", broot->nbr);	
	// mv_push(broot, aroot);
	// printf("pushing\n");
	// for (it = aroot->next ; it != aroot ; it = it->next)
	// 	printf("aroot %d\n", it->nbr);
	// printf("%d aroot numbers\n", aroot->nbr);
	// for (it = broot->next ; it != broot ; it = it->next)
	// 	printf("broot %d\n", it->nbr);
	// printf("%d broot numbers\n", broot->nbr);	

	// printf("%d aroot numbers\n", aroot->nbr);	
	// printf("%d broot numbers\n", broot->nbr);	
	// mv_push(aroot, broot);
	// printf("pushing\n");
	// for (it = aroot->next ; it != aroot ; it = it->next)
	// 	printf("aroot %d\n", it->nbr);
	// printf("%d aroot numbers\n", aroot->nbr);	
	// for (it = broot->next ; it != broot ; it = it->next)
	// 	printf("broot %d\n", it->nbr);
	// printf("%d broot numbers\n", broot->nbr);

	ft_stkadd_top(aroot, NULL, b, NULL);
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	mv_rotate(aroot, mv, 'a');
	printf("rotating\n");
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);

	mv_reverse_rotate(aroot, mv, 'a');
	mv_reverse_rotate(aroot, mv, 'a');
	printf("2 rev_rotating\n");
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	
	for (it = broot->next ; it != broot ; it = it->next)
		printf("broot %d\n", it->nbr);
	printf("%d broot numbers\n", broot->nbr);
	
	ft_delstk(aroot->next, aroot);
	printf("%d aroot numbers\n", aroot->nbr);	
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	mv_push(aroot, broot, mv, 'b');
	printf("%d aroot numbers\n", aroot->nbr);	
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	printf("%d broot numbers\n", broot->nbr);	
	for (it = broot->next ; it != broot ; it = it->next)
		printf("broot %d\n", it->nbr);

	printf("\nMOOVES :\n");
	for (it = mv->next ; it != mv ; it = it->next)
		printf("%s\n", it->mv);
	ft_stkclean(broot);
	ft_stkclean(aroot);
	ft_stkclean(mv);
	return (0);
}

