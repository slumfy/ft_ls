/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:40:24 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/23 14:32:41 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*a FaiRE EN MIEUX*/

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

	cur = *list;
	prev = *list;
	while (cur)
	{
		if ((cur->sb.st_mode & S_IFMT) == S_IFDIR && cur->dp->d_name[0] != '.')
		{
			prev->next = cur->next;
			cur->next = NULL;
			insert_back(cur, &data->dir_list);
			cur = prev;
		}
		if (prev != cur)
			prev = prev->next;
		cur = cur->next;
	}
}
