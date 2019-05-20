#include "ft_ls.h"

void	rev_list(t_file **list)
{
	t_file *tmp;
	t_file *end;
	t_file *start;


	start = *list;
	end = start;
	while (end->next)
		end = end->next;
	tmp = end;
	while (start != tmp)
	{
		while (start->next != tmp)
			start = start->next;
		tmp->next = start;
		tmp = start;
		start = *list;
	}
	start->next = NULL;
	*list = end;
}
