/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:21:14 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/05 23:14:53 by egiacomi         ###   ########.fr       */
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
	int				idx;
	int				rank;
	char			*mv;
	struct s_list	*prev;
	struct s_list	*next;
}					t_stack;

/* EXECUTION */
int		main(int ac, char **av);
t_stack	*ft_setup(int ac, char **av, t_stack *aroot, t_stack *broot);
int		ft_fill_stack_a(t_stack *aroot, char *val);
void	ft_set_rank(t_stack *aroot);

/* PARSING */
long	ft_atoi(const char *nptr);
int		ft_isnumber(char *arg);
int		ft_exist(t_stack *aroot, int nbr);
int		ft_islong(long nbr);
int		ft_is_sorted(t_stack *aroot);

/* STACK MANAGER */
t_stack	*ft_createstk(void);
void	ft_stkadd_next(t_stack *element, t_stack *new);
void	ft_stkadd_prev(t_stack *element, t_stack *new);
void	ft_stkadd_top(t_stack *root, t_stack *element, int val, char *s);
void	ft_stkadd_bot(t_stack *root, t_stack *element, int val, char *s);
void	ft_setidx(t_stack *root);
void	ft_delstk(t_stack *element, t_stack *root);
void	ft_stkclean(t_stack *root);
void	ft_stk_supercleaner(t_stack *a, t_stack *b, t_stack *c, t_stack *d);

/* MOVES */
void	mv_swap(t_stack *root, t_stack *mv, char s);
void	mv_swap_swap(t_stack *aroot, t_stack *broot, t_stack *mv);
void	mv_push(t_stack *root_give, t_stack *root_receive, t_stack *mv, char s);
void	mv_rotate(t_stack *root, t_stack *mv, char s);
void	mv_rotate_rotate(t_stack *aroot, t_stack *broot, t_stack *mv);
void	mv_reverse_rotate(t_stack *root, t_stack *mv, char s);
void	mv_reverse_rotate_rotate(t_stack *aroot, t_stack *broot, t_stack *mv);

/* SORTING */
void	ft_sort_small(t_stack *aroot, t_stack *broot, t_stack *mv);

/* UTILS */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_strlen(char *str);

#endif
