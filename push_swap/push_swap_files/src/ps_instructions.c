/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 22:15:05 by jronald           #+#    #+#             */
/*   Updated: 2018/09/08 13:16:45 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sorted_stack(t_stack *u)
{
	int		count;
	t_push	*temp;

	temp = u->a;
	count = 1;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		count++;
		temp = temp->next;
	}
	if (count == u->size)
		return (1);
	return (0);
}

int		get_max(int *dir, t_stack *u)
{
	int		max;
	int		count;
	int		ind;
	t_push	*temp;

	temp = u->b;
	max = 0;
	ind = 0;
	count = 1;
	while (temp)
	{
		if (max < temp->index)
		{
			max = temp->index;
			ind = count;
		}
		count++;
		temp = temp->next;
	}
	if (ind > (count / 2))
		*dir = -1;
	else
		*dir = 1;
	return (max);
}

void	return_stack_a(t_stack *u)
{
	int max;
	int dir;

	max = 0;
	dir = 0;
	while (u->b != 0)
	{
		max = get_max(&dir, u);
		while (u->b->index != max)
		{
			if (dir == 1)
				c_i("rb", u);
			else
				c_i("rrb", u);
		}
		c_i("pa", u);
	}
}

int		sort_without_count(t_stack *u)
{
	t_push *temp;

	temp = u->a;
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}
