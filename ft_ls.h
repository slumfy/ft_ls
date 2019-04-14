/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:13:06 by rvalenti          #+#    #+#             */
/*   Updated: 2019/04/14 21:46:45 by rvalenti         ###   ########.fr       */
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
}					t_file;


typedef	struct		s_dir
{
	DIR             *curdir;
	t_file			*list;
}					t_dir;

void		ft_ls(t_dir *data, char *path);

void		ft_list_pushback(t_file **begin_list, struct dirent *dp);
t_file		*ft_create_elem(struct dirent *dp);
void		print_list(t_file *list);
#endif
