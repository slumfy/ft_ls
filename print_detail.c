#include "ft_ls.h"

void print_detail(t_data *data, t_file *list)
{
	char *type;
	char *time;
	
	time = NULL;
	type = NULL;
	(void)data;

	if ((list->sb.st_mode & S_IFMT) == S_IFBLK)
		type = "block device";
	else if ((list->sb.st_mode & S_IFMT) == S_IFCHR)
		type = "character device";
	else if ((list->sb.st_mode & S_IFMT) == S_IFDIR)
		type = "directory";
	else if ((list->sb.st_mode & S_IFMT) == S_IFIFO)
		type = "FIFO/pipe";
	else if ((list->sb.st_mode & S_IFMT) == S_IFLNK)
		type = "symlink";
	else if ((list->sb.st_mode & S_IFMT) == S_IFREG)
		type = "regular file";
	else if ((list->sb.st_mode & S_IFMT) == S_IFSOCK)
		type = "socket";
	else
		type = "unknown?";
	
	time = ctime(&list->sb.st_mtimespec.tv_sec);
		printf("%s\t%d\t%s\t%s\t%lld\t%s\t",
		type, list->sb.st_nlink, list->pass->pw_name,
		list->grp->gr_name, list->sb.st_size, time);
}
