/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:25:12 by jronald           #+#    #+#             */
/*   Updated: 2018/09/08 13:01:51 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		small_sort(t_stack *u)
{
	get_index(u);
	while (sorted_stack(u) == 0)
	{
		if (u->size > 3)
			small_sort_push_b(u);
		while (sort_without_count(u) == 0)
		{
			if (u->a->index > u->a->next->index)
				c_i("sa", u);
			else
				c_i("rra", u);
		}
		if (u->b != 0)
			return_stack_a(u);
	}
	return (0);
}

void	small_sort_push_b(t_stack *u)
{
	int i;

	i = u->size - 3;
	while (i > 0)
	{
		if (u->a->index <= (u->size - 3))
		{
			c_i("pb", u);
			i--;
		}
		else
			c_i("ra", u);
	}
}

int		get_index(t_stack *u)
{
	t_push	*temp1;
	t_push	*temp2;
	int		index;

	temp1 = u->a;
	while (temp1)
	{
		temp2 = u->a;
		index = u->size;
		while (temp2)
		{
			index = (temp2->value > temp1->value) ? (index - 1) : index;
			temp2 = temp2->next;
		}
		temp1->index = index;
		temp1 = temp1->next;
	}
	return (0);
}

int		sort(t_stack *u)
{
	int		low;
	int		high;
	int		inc;

	high = u->size;
	get_index(u);
	inc = (u->size > 20 && u->size < 250) ? (u->size / 4) : (u->size / 9.5);
	while (sorted_stack(u) == 0)
	{
		low = (high - inc) <= 0 ? 1 : (high - inc - 1);
		push_stack_b(high, low, u);
		if (high != u->size)
		{
			while (u->a->index != (high + 1))
				c_i("ra", u);
		}
		return_stack_a(u);
		high = (high - inc) <= 0 ? (low - 1) : (high - inc);
	}
	return (0);
}

void	push_stack_b(int max, int min, t_stack *u)
{
	int		i;

	min = (min == 0) ? 1 : min;
	i = max - min + 1;
	while (i > 0)
	{
		if (u->a->index <= max && u->a->index >= min)
		{
			c_i("pb", u);
			i--;
		}
		else
			c_i("rra", u);
	}
}
