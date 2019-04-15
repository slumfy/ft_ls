/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:07:00 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/15 05:00:33 by rvalenti         ###   ########.fr       */
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

void	ft_list_insert(t_file **begin_list, struct dirent *dp)
{
	t_file	*tmp;
	t_file	*tmp2;
	t_file	*elem;

	elem = NULL;
	tmp = *begin_list;
	tmp2 = *begin_list;
	if (*begin_list == NULL)
		*begin_list = ft_create_elem(dp);
	else if (ft_strcmp(dp->d_name, tmp->dp->d_name) <= 0)
		ft_list_pushfront(begin_list, dp);
	else
	{
		while (tmp && ft_strcmp(dp->d_name, tmp->dp->d_name) > 0)
		{
			if (tmp2 != tmp)
				tmp2 = tmp->next;
			tmp = tmp->next;
		}
		if (tmp == tmp2)
			ft_list_pushback(begin_list, dp);
		else
		{
			elem = ft_create_elem(dp);
			tmp2->next = elem;
			elem->next = tmp;
		}
	}
}

void	ft_list_pushfront(t_file **begin_list, struct dirent *dp)
{
	t_file	*tmp;

	if (*begin_list)
	{
		tmp = ft_create_elem(dp);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_create_elem(dp);
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

int		list_size(t_file *list)
{
	t_file *tmp;
	int n;

	n = 0;
	tmp = list;
	while (tmp)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

void	print_list(t_file *list)
{
	t_file *tmp;

	tmp = list;
	printf("list:\n");
	while (tmp)
	{
		if (tmp->dp->d_name[0] != '.')
			printf("%s\t", tmp->dp->d_name);
		tmp = tmp->next;
	}
	printf("\n");
}
