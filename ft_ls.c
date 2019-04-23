/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:31:27 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/23 15:29:26 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ls(t_data *data, char *current)
{
	struct dirent	*file;
	t_file			*tmp;
	int len;

	len = 0;
	if (data->dir_list)
	{
		tmp = data->dir_list->next;
		free(data->dir_list);
		data->dir_list = tmp;
	}
	tmp = data->list;
	data->dir.curdir = opendir(current);
	while ((file = readdir(data->dir.curdir)) != NULL)
	{
		ft_list_insert(&data->list, file, data);
	}
	len = list_size(data->list);
	print_list(data->list);
	deleteif_list(&data->list, data);
	print_list(data->dir_list);
	free_list(&data->list);
	closedir(data->dir.curdir);
}
