/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:40:24 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/16 09:35:13 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*a FaiRE EN MIEUX*/


void	deleteif_list(t_file **list, t_data *data)
{
	t_file *cur;
	t_file *prev;

	cur = *list;
	prev = *list;
	while (cur)
	{
		if ((cur->sb.st_mode & S_IFMT) == S_IFDIR && cur->dp->d_name[0] != '.')
			break ;
		cur = cur->next;
	}
	while(prev->next != cur)
		prev = prev->next;
	while (cur)
	{
		if ((cur->sb.st_mode & S_IFMT) == S_IFDIR && cur->dp->d_name[0] != '.')
		{
			prev->next = cur->next;
			data->dir_list = cur;
			cur->next = NULL;
		}
		prev = prev->next;
		cur = cur->next;
	}
}
