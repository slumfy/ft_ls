/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:55:15 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/16 00:56:58 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_data			data;
	int				len;

	ft_memset(&data, 0, sizeof(t_dir));
	if (ac < 2)
	{
		data.dir.curdir = opendir(".");
		strcat(data.dir.path, ".");
	}
	else
	{
		data.dir.curdir = opendir(av[1]);
		strcat(data.dir.path, av[1]);
	}
	len = strlen(data.dir.path);
	data.dir.path[len] = '/';
	data.dir.path[len + 1] = '\0';
	len = strlen(data.dir.path);
	printf ("path=%s\n", data.dir.path);
	ft_ls(&data);
	free_list(data.list);
	return (0);
}
