/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 14:33:13 by jronald           #+#    #+#             */
/*   Updated: 2018/09/10 13:30:08 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

# define INT_MAX 2147483647
# define INT_MIN 2147483648

typedef struct		s_push
{
	int				value;
	int				index;
	struct s_push	*next;
}					t_push;

typedef struct		s_stack
{
	t_push			*a;
	t_push			*b;
	int				size;
}					t_stack;

t_push				*swap_first_elem(t_push *lst, int *ret);
t_push				*push_first_elem(t_stack *a, char l, int *ret);
t_push				*rotate_up(t_push *lst, int *ret);
t_push				*rotate_down(t_push *lst, int *ret);
t_push				*add_list(t_push *lst, int value);
int					rm_list(t_push *lst);
int					create_stack(char **num, t_stack *u);
int					sorted(t_stack *u);
int					check_instructions(char **str, t_stack *p);
int					error_checking(char **log);
int					check_duplicates(t_push *a);
int					c_i(char *str, t_stack *p);
int					get_index(t_stack *u);
int					sorted_stack(t_stack *u);
int					sort(t_stack *u);
void				push_stack_b(int max, int min, t_stack *u);
int					get_max(int *dir, t_stack *u);
void				return_stack_a(t_stack *u);
int					small_sort(t_stack *u);
void				small_sort_push_b(t_stack *u);
int					sort_without_count(t_stack *u);
void				free_list(t_push *temp);
#endif
