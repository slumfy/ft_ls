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
	unsigned long nblock;
	int linklen;
	int sizelen;

	nblock = 0;
	linklen = 0;
	sizelen = 0;
	if (data->fmt & OPT_l)
	{
		tmp = list;
		while (tmp)
		{
			if (tmp->filename[0] != '.' || data->fmt & OPT_a)
{
				if (ft_nbrlen(tmp->sb.st_nlink) > (size_t)linklen)
					linklen = (int)ft_nbrlen(tmp->sb.st_nlink); 
				if (ft_nbrlen(tmp->sb.st_size) > (size_t)sizelen)
					sizelen = (int)ft_nbrlen(tmp->sb.st_size); 
				nblock = nblock + tmp->sb.st_blocks;
}
			tmp = tmp->next;
		}
		printf("total %ld\n", nblock);
	}
	tmp = list;
	while (tmp)
	{
		if (tmp->filename[0] != '.' || data->fmt & OPT_a)
		{
			if (data->fmt & OPT_l)
			{
				print_detail(data, tmp, linklen, sizelen);
			}
			printf("%s\n", tmp->filename);
		}
		tmp = tmp->next;
	}
	if (data->fmt & OPT_R)
		printf("\n");
}
