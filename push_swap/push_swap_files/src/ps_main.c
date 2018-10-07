/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 23:03:04 by jronald           #+#    #+#             */
/*   Updated: 2018/09/08 14:19:26 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count(t_stack *u)
{
	t_push *temp;

	temp = u->a;
	u->size = 0;
	while (temp)
	{
		(u->size)++;
		temp = temp->next;
	}
}

int		main(int ac, char **av)
{
	int		ret;
	t_stack	*temp;

	if (ac > 1)
	{
		ret = 0;
		temp = (t_stack *)malloc(sizeof(t_stack));
		temp->b = 0;
		if (create_stack(av + 1, temp) == 1)
		{
			ft_putstr("Error\n");
			return (1);
		}
		count(temp);
		if (temp->size <= 20)
			ret = small_sort(temp);
		else
			ret = sort(temp);
		free_list(temp->a);
		free(temp);
		return (ret);
	}
	ft_putchar('\n');
	return (0);
}
