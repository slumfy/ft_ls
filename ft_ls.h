/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:13:06 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/23 14:19:21 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include "libft/libft.h"
# include <limits.h>
# include <errno.h>

#define OPT_l 1
#define OPT_R 2
#define OPT_a 4
#define OPT_r 8
#define OPT_t 16


typedef struct		s_file
{
	struct dirent   *dp;
	struct stat     sb;
	struct passwd   *pass;
	struct group    *grp;
	struct s_file	*next;
	char			path[PATH_MAX];
}					t_file;


typedef	struct		s_dir
{
	DIR             *curdir;
	char			path[PATH_MAX];
}					t_dir;

typedef struct		s_data
{
	int			fmt;
	t_dir		dir;
	t_file		*list;
	t_file		*dir_list;
}					t_data;

void		ft_ls(t_data *data, char *current);

void		ft_list_insert(t_file **begin_list, struct dirent *dp, t_data *data);
void		ft_list_pushfront(t_file **begin_list, struct dirent *dp, t_data *data);
void		ft_list_pushback(t_file **begin_list, struct dirent *dp, t_data *data);
t_file		*ft_create_elem(struct dirent *dp, t_data *data);
void		free_list(t_file **list);
void		deleteif_list(t_file **list, t_data *data);
int			list_size(t_file *list);
void		print_list(t_file *list);

#endif
