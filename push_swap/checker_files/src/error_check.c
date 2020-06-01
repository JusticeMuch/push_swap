/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 03:03:07 by jronald           #+#    #+#             */
/*   Updated: 2018/09/10 13:10:00 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_duplicates(t_push *a)
{
	t_push *temp1;
	t_push *temp2;

	temp1 = a;
	temp2 = a;
	while (temp1->next)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->value == temp2->value)
				return (1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (0);
}

int		error_checking(char **log)
{
	int j;

	j = -1;
	while (log[++j])
	{
		if (ft_strlen(log[j]) == 10)
		{
			if (ft_atoi(log[j]) < 1000000000)
				return (1);
		}
		else if (ft_strlen(log[j]) == 11)
		{
			if (ft_atoi(log[j]) > -1000000000)
				return (1);
		}
		else if (ft_strlen(log[j]) > 11 || !(ft_isdigit(log[j][0])))
			return (1);
	}
	return (0);
}

void	free_list(t_push *temp)
{
	t_push *temp1;

	temp1 = 0;
	while (temp)
	{
		temp1 = temp->next;
		free(temp);
		temp = temp1;
	}
	temp = 0;
}
