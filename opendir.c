/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:31:27 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/29 15:27:24 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

int		main(int ac, char **av)
{
	DIR				*curdir;
	struct dirent	*dp;
	struct stat		sb;
	struct passwd	*pass;
	struct group	*grp;

	if (ac < 2)
		curdir = opendir(".");
	else
		curdir = opendir(av[1]);

	while ((dp = readdir(curdir)) != NULL)
	{
		stat(dp->d_name, &sb);
		pass = getpwuid(sb.st_uid);
		grp = getgrgid(sb.st_gid);

		printf("%s\n", dp->d_name);
		printf("File type:                ");
		if ((sb.st_mode & S_IFMT) == S_IFBLK)
			printf("block device\n");
		else if ((sb.st_mode & S_IFMT) == S_IFCHR)
			printf("character device\n");
		else if ((sb.st_mode & S_IFMT) == S_IFDIR)
			printf("directory\n");
		else if ((sb.st_mode & S_IFMT) == S_IFIFO)
			printf("FIFO/pipe\n");
		else if	((sb.st_mode & S_IFMT) == S_IFLNK)
			printf("symlink\n");
		else if ((sb.st_mode & S_IFMT) == S_IFREG)
			printf("regular file\n");
		else if ((sb.st_mode & S_IFMT) == S_IFSOCK)
			printf("socket\n");
		else
			printf("unknown?\n");

	printf("I-node number:            %ld\n", (long) sb.st_ino);
	printf("Mode:                     %lo (octal)\n",(unsigned long) sb.st_mode);
	printf("Link count:               %ld\n", (long) sb.st_nlink);
	printf("Ownership:                UID=%ld   GID=%ld\n",(long) sb.st_uid, (long) sb.st_gid);
	printf("uid-name:	%s\t%s\n", pass->pw_name, grp->gr_name);
	printf("Preferred I/O block size: %ld bytes\n",(long) sb.st_blksize);
	printf("File size:                %lld bytes\n",(long long) sb.st_size);
	printf("Blocks allocated:         %lld\n",(long long) sb.st_blocks);
	printf("Last status change:       %s", ctime(&sb.st_ctime));
	printf("Last file access:         %s", ctime(&sb.st_atime));
	printf("Last file modification:   %s", ctime(&sb.st_mtime));
	printf("\n");
	}
return (0);
}
