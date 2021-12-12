/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:03:59 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/12 22:19:52 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			ft_putchar_fd(s[i], fd);
	}
}

void	ft_print_mooves(t_stack *mv)
{
	t_stack	*it;

	it = mv->next;
	while(it != mv)
	{
		ft_putstr_fd(it->mv, 1);
		ft_putchar_fd('\n', 1);
		it = it->next;
	}
}
	