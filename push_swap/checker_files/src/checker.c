/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 12:02:30 by jronald           #+#    #+#             */
/*   Updated: 2018/09/10 13:31:14 by jronald          ###   ########.fr       */
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

int		display_error(t_stack *u, char *msg)
{
	free_list(u->a);
	if (u->b != 0)
		free_list(u->b);
	free(u);
	ft_putstr(msg);
	return (1);
}

int		main(int ac, char **av)
{
	t_stack	*temp;
	char	*line;

	temp = (t_stack*)malloc(sizeof(t_stack));
	line = 0;
	temp->b = 0;
	if (ac > 1)
	{
		if (create_stack(av + 1, temp) == 1)
			return (display_error(temp, "Error\n"));
		count(temp);
		while (get_next_line(0, &line) > 0)
		{
			if (check_instructions(&line, temp) == 0)
				return (display_error(temp, "Error\n"));
		}
		if (sorted(temp) == 0)
			return (display_error(temp, "KO\n"));
		else
			return (display_error(temp, "OK\n"));
	}
	ft_putchar('\n');
	return (0);
}
