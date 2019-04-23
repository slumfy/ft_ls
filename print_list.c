/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:54:31 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/23 17:28:02 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_list(t_file *list, char *comment)
{
	t_file *tmp;

	tmp = list;
	printf("%s:\n", comment);
	while (tmp)
	{
		if (tmp->filename[0] != '.')
		{
			printf("%s\t", tmp->filename);
			if ((tmp->sb.st_mode & S_IFMT) == S_IFBLK)
				printf("block device\n");
			else if ((tmp->sb.st_mode & S_IFMT) == S_IFCHR)
				printf("character device\n");
			else if ((tmp->sb.st_mode & S_IFMT) == S_IFDIR)
				printf("directory\n");
			else if ((tmp->sb.st_mode & S_IFMT) == S_IFIFO)
				printf("FIFO/pipe\n");
			else if ((tmp->sb.st_mode & S_IFMT) == S_IFLNK)
				printf("symlink\n");
			else if ((tmp->sb.st_mode & S_IFMT) == S_IFREG)
				printf("regular file\n");
			else if ((tmp->sb.st_mode & S_IFMT) == S_IFSOCK)
				printf("socket\n");
			else
				printf("unknown?\n");
		}
		tmp = tmp->next;
	}
	printf("\n");
}
