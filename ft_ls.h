/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:13:06 by rvalenti          #+#    #+#             */
/*   Updated: 2019/03/19 12:30:03 by rvalenti         ###   ########.fr       */
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

typedef	struct	s_dir
{
	DIR             *curdir;
	struct dirent   *dp;
	struct stat     sb;
	struct passwd   *pass;
	struct group    *grp;
}					t_dir;


#endif
