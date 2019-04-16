/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:31:27 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/16 09:12:26 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
 * 1: fonction pour check et set les options
 * 2: fonction pour creer la list
 * 3: gestion des options
 * 4: fonctions d'affichage
 * 5: fonctions gestions d'erreur suivant les retours des fonctions precedantes
 */

void ft_ls(t_data *data)
{
	struct dirent	*file;
	t_file			*tmp;
	int len;

	len = 0;
	tmp = data->list;
	while ((file = readdir(data->dir.curdir)) != NULL)
	{
	//		printf("elem= %s\n", file->d_name);
		ft_list_insert(&data->list, file, data);
	}
	len = list_size(data->list);
	print_list(data->list);
	deleteif_list(&data->list, data);
	print_list(data->dir_list);
	/*
	 ** partie pour afficher les information des different fichier/dir/etc
	 */

	/*	printf("File type:                ");
		if ((data.sb.st_mode & S_IFMT) == S_IFBLK)
		printf("block device\n");
		else if ((data.sb.st_mode & S_IFMT) == S_IFCHR)
		printf("character device\n");
		else if ((data.sb.st_mode & S_IFMT) == S_IFDIR)
		printf("directory\n");
		else if ((data.sb.st_mode & S_IFMT) == S_IFIFO)
		printf("FIFO/pipe\n");
		else if	((data.sb.st_mode & S_IFMT) == S_IFLNK)
		printf("symlink\n");
		else if ((data.sb.st_mode & S_IFMT) == S_IFREG)
		printf("regular file\n");
		else if ((data.sb.st_mode & S_IFMT) == S_IFSOCK)
		printf("socket\n");
		else
		printf("unknown?\n");
		}

		printf("I-node number:            %ld\n", (long) data.sb.st_ino);
		printf("Mode:                     %lo (octal)\n",(unsigned long) data.sb.st_mode);
		printf("Link count:               %ld\n", (long) data.sb.st_nlink);
		printf("Ownership:                UID=%ld   GID=%ld\n",(long) data.sb.st_uid, (long) data.sb.st_gid);
		printf("uid-name:	%s\t%s\n", data.pass->pw_name, data.grp->gr_name);
		printf("Preferred I/O block size: %ld bytes\n",(long) data.sb.st_blksize);
		printf("File size:                %lld bytes\n",(long long) data.sb.st_size);
		printf("Blocks allocated:         %lld\n",(long long) data.sb.st_blocks);
		printf("Last status change:       %s", ctime(&data.sb.st_ctime));
		printf("Last file access:         %s", ctime(&data.sb.st_atime));
		printf("Last file modification:   %s", ctime(&data.sb.st_mtime));
		printf("\n");*/
	closedir(data->dir.curdir);
	}
