/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:54:31 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/16 02:43:40 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    print_list(t_file *list)
{
	t_file *tmp;

	tmp = list;
	printf("list:\n");
	while (tmp)
	{
		if (tmp->dp->d_name[0] != '.')
			printf("%s\n", tmp->dp->d_name);
		tmp = tmp->next;
	}
	printf("\n");
}
