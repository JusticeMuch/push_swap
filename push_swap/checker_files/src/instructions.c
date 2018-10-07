/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:08:01 by jronald           #+#    #+#             */
/*   Updated: 2018/09/11 12:43:50 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_instructions(char **str, t_stack *p)
{
	int ret;

	ret = 0;
	if (ft_strcmp(*str, "sa") == 0 || ft_strcmp(*str, "ss") == 0)
		p->a = swap_first_elem(p->a, &ret);
	if (ft_strcmp(*str, "sb") == 0 || ft_strcmp(*str, "ss") == 0)
		p->b = swap_first_elem(p->b, &ret);
	if (ft_strcmp(*str, "pa") == 0)
		p->a = push_first_elem(p, 'a', &ret);
	if (ft_strcmp(*str, "pb") == 0)
		p->b = push_first_elem(p, 'b', &ret);
	if (ft_strcmp(*str, "ra") == 0 || ft_strcmp(*str, "rr") == 0)
		p->a = rotate_up(p->a, &ret);
	if (ft_strcmp(*str, "rb") == 0 || ft_strcmp(*str, "rr") == 0)
		p->b = rotate_up(p->b, &ret);
	if (ft_strcmp(*str, "rra") == 0 || ft_strcmp(*str, "rrr") == 0)
		p->a = rotate_down(p->a, &ret);
	if (ft_strcmp(*str, "rrb") == 0 || ft_strcmp(*str, "rrr") == 0)
		p->b = rotate_down(p->b, &ret);
	ft_strdel(str);
	return (ret);
}

t_push	*swap_first_elem(t_push *lst, int *ret)
{
	t_push *temp2;

	if (lst->next == 0)
	{
		*ret = 0;
		return (lst);
	}
	temp2 = lst->next;
	lst->next = lst->next->next;
	temp2->next = lst;
	*ret = 1;
	return (temp2);
}

t_push	*push_first_elem(t_stack *a, char l, int *ret)
{
	t_push *temp;
	t_push *temp2;

	if ((l == 'a' && a->b == 0) || (l == 'b' && a->a == 0))
		return (0);
	temp2 = (l == 'a') ? a->b : a->a;
	temp = (t_push*)malloc(sizeof(t_push));
	ft_memcpy(temp, temp2, sizeof(t_push));
	a->a = (l == 'a') ? a->a : a->a->next;
	a->b = (l == 'b') ? a->b : a->b->next;
	temp->next = (l == 'a') ? a->a : a->b;
	free(temp2);
	*ret = 1;
	return (temp);
}

t_push	*rotate_up(t_push *lst, int *ret)
{
	t_push *temp;
	t_push *temp2;

	if (lst->next == 0)
	{
		*ret = 0;
		return (lst);
	}
	temp = lst;
	lst = lst->next;
	temp2 = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = temp;
	temp->next = 0;
	*ret = 1;
	return (temp2);
}

t_push	*rotate_down(t_push *lst, int *ret)
{
	t_push *temp;
	t_push *temp2;

	if (lst->next == 0)
	{
		*ret = 0;
		return (lst);
	}
	temp = lst;
	while (temp->next->next)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = 0;
	temp2->next = lst;
	*ret = 1;
	return (temp2);
}
