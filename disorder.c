#include "push.h"


void	ft_index_stack(t_node *a)
{
	t_node	*comp;
	t_node	*cur;
	int		idx;

	cur = a;
	while (cur)
	{
		idx = 0;
		comp = a;
		while (comp)
		{
			if (comp->value < cur->value)
				idx++;
			comp = comp->next;
		}
		cur->index = idx;
		cur = cur->next;
	}
}

double ft_disorder(t_node *a)
{
	t_node *cur;
	long mistakes;
	long total_pairs;
	
	mistakes = 0;
	total_pairs = 0;
	
	while (a)
	{
		cur = a->next;
		while (cur)
		{
			total_pairs++;
			if (a->value > cur->value)
				mistakes++;
			cur = cur->next;
		}
		a = a->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}