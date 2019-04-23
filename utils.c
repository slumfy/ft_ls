/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2019/04/14 21:07:00 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/23 15:54:02 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_create_elem(struct dirent *dp, t_data *data)
{
	t_file	*new;
	char	path_name[PATH_MAX];
	int		len;

	ft_bzero((void *)path_name, PATH_MAX);
	ft_strcpy(path_name, data->dir.path);
	ft_strcat(path_name, dp->d_name);
	len = ft_strlen(path_name);
	if (!(new = (t_file*)ft_memalloc(sizeof(t_file))))
		return(NULL);
	new->dp = dp;
	stat(path_name, &new->sb);
	path_name[len] = '/';
	ft_strcpy(new->path, path_name);
	new->pass = getpwuid(new->sb.st_uid);
	new->grp = getgrgid(new->sb.st_gid);
	new->next = NULL;
//	printf("name = %s\tpathelem= %s\n",dp->d_name , path_name);
	return (new);
}

void	ft_list_insert(t_file **begin_list, struct dirent *dp, t_data *data)
{
	t_file	*tmp;
	t_file	*tmp2;
	t_file	*elem;

	elem = NULL;
	tmp = *begin_list;
	tmp2 = *begin_list;
	if (*begin_list == NULL)
		*begin_list = ft_create_elem(dp, data);
	else if (ft_strcmp(dp->d_name, tmp->dp->d_name) <= 0)
		ft_list_pushfront(begin_list, dp, data);
	else
	{
		while (tmp && ft_strcmp(dp->d_name, tmp->dp->d_name) > 0)
		{
			if (tmp2 != tmp)
				tmp2 = tmp->next;
			tmp = tmp->next;
		}
		if (tmp == tmp2)
			ft_list_pushback(begin_list, dp, data);
		else
		{
			elem = ft_create_elem(dp, data);
			tmp2->next = elem;
			elem->next = tmp;
		}
	}
}

void	ft_list_pushfront(t_file **begin_list, struct dirent *dp, t_data *data)
{
	t_file	*tmp;

	if (*begin_list)
	{
		tmp = ft_create_elem(dp, data);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_create_elem(dp, data);
}

void	ft_list_pushback(t_file **begin_list, struct dirent *dp, t_data *data)
{
	t_file	*tmp;

	tmp = NULL;
	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(dp, data);
	}
	else
		*begin_list = ft_create_elem(dp, data);
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

void	free_list(t_file **begin_list)
{
	t_file *tmp;
	t_file *tmp2;

	tmp = *begin_list;
	tmp2 = *begin_list;
	if (*begin_list != NULL)
	{
		while (tmp)
		{
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
		*begin_list = NULL;
	}
}
