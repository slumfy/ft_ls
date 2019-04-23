/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:40:24 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/23 16:36:05 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	insert_back(t_file *file, t_file **dst)
{
	t_file *tmp;

	tmp = *dst;
	if (*dst != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = file;
	}
	else
		*dst = file;
}

void	deleteif_list(t_file **list, t_data *data)
{
	t_file *cur;
	t_file *prev;
	t_file *dst;

	dst = NULL;
	cur = *list;
	prev = *list;
	while (cur)
	{
		if ((cur->sb.st_mode & S_IFMT) == S_IFDIR && cur->dp->d_name[0] != '.')
		{
			prev->next = cur->next;
			cur->next = NULL;
			insert_back(cur, &dst);
			cur = prev;
		}
		if (prev != cur)
			prev = prev->next;
		cur = cur->next;
	}
	if (dst)
	{
		prev = dst;
		while (prev->next)
			prev = prev->next;
		prev->next = data->dir_list;
		data->dir_list = dst;
	}
}
