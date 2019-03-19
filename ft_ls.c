/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:31:27 by rvalenti          #+#    #+#             */
/*   Updated: 2019/03/19 15:53:23 by rvalenti         ###   ########.fr       */
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



int		main(int ac, char **av)
{
	t_dir data;
	char    path[PATH_MAX];
	int     len;

	ft_memset(&data, 0, sizeof(t_dir));
	if (ac < 2)
	{
		data.curdir = opendir(".");
		strcat(path, ".");
	}
	else
	{
		data.curdir = opendir(av[1]);
	strcat(path, av[1]);
	}
	len = strlen(path);
	path[len] = '/';
	path[len + 1] = '\0';
	len = strlen(path);
	printf ("\npath=%s\n", path);
	while ((data.dp = readdir(data.curdir)) != NULL)
	{
		strcpy((path + len), data.dp->d_name);
		stat(path, &data.sb);
		data.pass = getpwuid(data.sb.st_uid);
		data.grp = getgrgid(data.sb.st_gid);
		if (data.dp->d_name[0] != '.')
			printf("%s\n", data.dp->d_name);
	}
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
	printf("\n");
	closedir(data.curdir);
	if (ac < 2)
		data.curdir = opendir(".");
	else
		data.curdir = opendir(av[1]);
	while ((data.dp = readdir(data.curdir)) != NULL)
	{
		strcpy((path + len), data.dp->d_name);
		av[1] = path;
		stat(path, &data.sb);
		if ((data.sb.st_mode & S_IFMT) == S_IFDIR)
		if (data.dp->d_name[0] != '.' && (data.sb.st_mode & S_IFMT) == S_IFDIR)
		{
			main(2, av);
		}
	}
	closedir(data.curdir);
	return (0);
}
