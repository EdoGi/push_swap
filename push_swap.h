/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:21:14 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/04 23:00:56 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*prev;
	struct s_list	*next;
}					t_stack;

t_stack	*ft_createstk(void);
void	ft_stkadd_next(t_stack *element, t_stack *new);
void	ft_stkadd_prev(t_stack *element, t_stack *new);
void	ft_stkadd_top(t_stack *root, t_stack *element, int val);
void	ft_stkadd_bot(t_stack *root, t_stack *element, int val);
void	ft_delstk(t_stack *element, t_stack *root);
void	ft_stkclean(t_stack *root);
void	mv_swap(t_stack *root);
void	mv_swap_swap(t_stack *aroot, t_stack *broot);
void	mv_push(t_stack *root_give, t_stack *root_receive);
void	mv_rotate(t_stack *root);
void	mv_reverse_rotate(t_stack *root);
void	mv_reverse_rotate_rotate(t_stack *aroot, t_stack *broot);
int		main(int ac, char **av);
long	ft_atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isnumber(char *arg);
int		ft_exist(t_stack *aroot, int nbr);
int		ft_islong(long nbr);
int		ft_isspace(int c);
int		ft_isdigit(int c);

#endif
