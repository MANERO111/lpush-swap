#include "push.h"


void	ft_index_stack(t_stack *a)
{
	t_stack	*comp;
	int		idx;

	while (a)
	{
		idx = 0;
		comp = a;
		while (comp)
		{
			if (comp->value < a->value)
				idx++;
			comp = comp->next;
		}
		a->index = idx;
		a = a->next;
	}
}

double ft_disorder(t_stack *a)
{
	t_stack *cur;
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