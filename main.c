/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:55:15 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/24 20:34:53 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_option(char **av, t_data *data)
{
	int n;
	int idx;

	n = 1;
	while (av[n] && av[n][0] == '-')
	{
		idx = 1;
		while(av[n][idx] != '\0')
		{
			if (av[n][idx] == 'l')
				data->fmt = data->fmt | OPT_l;
			else if (av[n][idx] == 'R')
				data->fmt = data->fmt | OPT_R;
			else if (av[n][idx] == 'a')
				data->fmt = data->fmt | OPT_a;
			else if (av[n][idx] == 'r')
				data->fmt = data->fmt | OPT_r;
			else if (av[n][idx] == 't')
				data->fmt = data->fmt | OPT_t;
			else
			{
				printf("error\n");
				exit(0); //mauvaise gestion a gerer avec strerror et perror
			}
			idx++;
		}
		n++;
	}
	return (n);
}

void	manage_arg(t_data *data)
{
	int		len;

	len = strlen(data->dir.path);
	if (data->dir.path[len - 1] != '/')
		data->dir.path[len] = '/';
	data->dir.path[len + 1] = '\0';
	len = strlen(data->dir.path);
	ft_ls(data, data->dir.path);
	while (data->dir_list && data->fmt & OPT_R)
	{
		ft_strcpy(data->dir.path, data->dir_list->path);
		printf ("%s\n", data->dir.path);
		ft_ls(data, data->dir_list->path);
	}
}

int		main(int ac, char **av)
{
	t_data			data;
	int				n;

	ft_memset(&data, 0, sizeof(t_data));
	n = get_option(av, &data);
	if (av[n] == NULL)
	{
		strcat(data.dir.path, ".");
		manage_arg(&data);
	}
	else
	{
		while (ac -1 >= n)
		{
			strcat(data.dir.path, av[ac -1]);
			manage_arg(&data);
			ac--;
		}
	}
	return (0);
}
