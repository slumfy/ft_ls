/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:30:41 by rvalenti          #+#    #+#             */
/*   Updated: 2019/08/05 16:30:26 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ls(t_data *data, char *current)
{
	struct dirent	*file;
	t_file			*tmp;

	tmp= NULL;
	if ((data->dir.curdir = opendir(current)))
	{
		while ((file = readdir(data->dir.curdir)) != NULL)
		{
			ft_list_insert(&data->list, file, data);
		}
		if (data->fmt & OPT_r)
			rev_list(&data->list);
		print_list(data, data->list);
		closedir(data->dir.curdir);
	}
	else
	{
		printf("ls:%s:%s\n",current , strerror(errno));
	}
	if (data->dir_list)
	{
		tmp = data->dir_list->next;
		free(data->dir_list);
		data->dir_list = tmp;
	}
	if (data->fmt & OPT_R)
	{
		deleteif_list(&data->list, data);
	}
	free_list(&data->list);
}
