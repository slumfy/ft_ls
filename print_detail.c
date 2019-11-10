#include "ft_ls.h"

void print_detail(t_data *data, t_file *list, int blocklen, int sizelen)
{
	char *type;
	char *st_time;
	time_t test;
	char **time_tab;
	char perm[10] = "---------";

	time_tab = NULL;	
	st_time = NULL;
	type = NULL;
	(void)data;
	time(&test);
	st_time = ctime(&test);
	//printf("current= %s \n", st_time);

	if ((list->sb.st_mode & S_IFMT) == S_IFBLK)
		type = "b";
	else if ((list->sb.st_mode & S_IFMT) == S_IFCHR)
		type = "c";
	else if ((list->sb.st_mode & S_IFMT) == S_IFDIR)
		type = "d";
	else if ((list->sb.st_mode & S_IFMT) == S_IFIFO)
		type = "FIFO";
	else if ((list->sb.st_mode & S_IFMT) == S_IFLNK)
		type = "l";
	else if ((list->sb.st_mode & S_IFMT) == S_IFREG)
		type = "-";
	else if ((list->sb.st_mode & S_IFMT) == S_IFSOCK)
		type = "s";
	else
		type = "?";

if (list->sb.st_mode & S_IRUSR)
		perm[0] = 'r';
if (list->sb.st_mode & S_IWUSR)
		perm[1] = 'w';
if (list->sb.st_mode & S_IXUSR)
		perm[2] = 'x';
if (list->sb.st_mode & S_IRGRP)
		perm[3] = 'r';
if (list->sb.st_mode & S_IWGRP)
		perm[4] = 'w';
if (list->sb.st_mode & S_IXGRP)
		perm[5] = 'x';
if (list->sb.st_mode & S_IROTH)
		perm[6] = 'r';
if (list->sb.st_mode & S_IWOTH)
		perm[7] = 'w';
if (list->sb.st_mode & S_IXOTH)
		perm[8] = 'x';


	st_time = ctime(&list->sb.st_mtimespec.tv_sec);
	time_tab = ft_strsplit(st_time, ' ');
	if ((test - list->sb.st_mtimespec.tv_sec) > 15552000)
{
		time_tab[3] = time_tab[4];
		time_tab[3][4] = '\0';
}
else
{
time_tab[3][5] = '\0';
}
	printf("%s%s %*d %s  %s  %*lld %*s %s %*s ",
			type, perm, blocklen, list->sb.st_nlink, list->pass->pw_name,
			list->grp->gr_name, sizelen, list->sb.st_size,
			2, time_tab[2], time_tab[1], 5,time_tab[3]);
}
