/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:38:24 by rvalenti          #+#    #+#             */
/*   Updated: 2019/08/05 16:29:32 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rev_list(t_file **list)
{
	t_file *tmp;
	t_file *end;
	t_file *start;


	start = *list;
	end = start;
	while (end->next)
		end = end->next;
	tmp = end;
	while (start != tmp)
	{
		while (start->next != tmp)
			start = start->next;
		tmp->next = start;
		tmp = start;
		start = *list;
	}
	tmp->next = NULL;
	*list = end;
}
