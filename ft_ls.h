/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:13:06 by rvalenti          #+#    #+#             */
/*   Updated: 2019/03/19 15:43:49 by rvalenti         ###   ########.fr       */
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


typedef	struct	s_dir
{
	DIR             *curdir;
	struct dirent   *dp;
	struct stat     sb;
	struct passwd   *pass;
	struct group    *grp;
}					t_dir;


#endif
