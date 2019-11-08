/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:54:31 by rvalenti          #+#    #+#             */
/*   Updated: 2019/08/05 16:39:04 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_list(t_data *data, t_file *list)
{
	t_file *tmp;
	unsigned long nlink;

	nlink = 0;
if (data->fmt & OPT_l)
{
	tmp = list;
	while (tmp)
{
	nlink = nlink + tmp->sb.st_nlink;
	tmp = tmp->next;
}
printf("total %ld\n", nlink);
}
	tmp = list;
	while (tmp)
	{
		if (tmp->filename[0] != '.' || data->fmt & OPT_a)
		{
			if (data->fmt & OPT_l)
			{
				print_detail(data, tmp);
			}
			printf("%s\n", tmp->filename);
		}
		tmp = tmp->next;
	}
	if (data->fmt & OPT_R)
		printf("\n");
}
