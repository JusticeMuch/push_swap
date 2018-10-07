/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 14:46:14 by jronald           #+#    #+#             */
/*   Updated: 2018/08/28 14:43:41 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sorted(t_stack *u)
{
	int count;

	count = 1;
	while (u->a->next)
	{
		if (u->a->value > u->a->next->value)
			return (0);
		count++;
		u->a = u->a->next;
	}
	if (count == u->size)
		return (1);
	return (0);
}

t_push	*add_list(t_push *lst, int value)
{
	t_push *n_list;

	n_list = (t_push*)malloc(sizeof(t_push));
	n_list->value = value;
	n_list->next = 0;
	if (lst != 0)
		lst->next = n_list;
	return (n_list);
}

void	free_arr(char ***arr)
{
	char	**temp;
	int		i;

	i = 0;
	temp = *arr;
	while (temp[i])
	{
		free((void*)temp[i]);
		i++;
	}
	free(temp);
}

int		create_stack(char **num, t_stack *u)
{
	int		i;
	t_push	*temp1;
	t_push	*temp2;
	char	**log;
	int		j;

	i = -1;
	log = 0;
	temp1 = 0;
	temp2 = 0;
	while (num[++i])
	{
		log = ft_strsplit(num[i], ' ');
		if (error_checking(log) == 1)
			return (1);
		j = -1;
		while (log[++j])
		{
			temp1 = add_list(temp2, ft_atoi(log[j]));
			u->a = (temp2 == 0) ? temp1 : u->a;
			temp2 = temp1;
		}
		free_arr(&log);
	}
	return (check_duplicates(u->a));
}
