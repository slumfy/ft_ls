/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:07:00 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/14 21:58:32 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_create_elem(struct dirent *dp)
{
	t_file	*new;

	if (!(new = (t_file*)ft_memalloc(sizeof(t_file))))
		return(NULL);
	new->dp = dp;
	new->next = NULL;
	return (new);
}

void	ft_list_pushback(t_file **begin_list, struct dirent *dp)
{
	t_file	*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(dp);
	}
	else
		*begin_list = ft_create_elem(dp);
}

void	print_list(t_file *list)
{
	t_file *tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->dp->d_name[0] != '.')
			printf("%s\t", tmp->dp->d_name);
		tmp = tmp->next;
	}
	printf("\n");
}
