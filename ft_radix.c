#include "push.h"


void ft_radix(t_stack *a, t_stack *b, t_info *info)
{
	//t_node *cur;
	int bit = 0;
	int i = 0;
	int stkSize ;

	stkSize = a->size;
	while (!is_sorted(a->top))
	{
		i = 0;
		while (i < stkSize)
		{
			if(((a->top->index >> bit) & 1) == 0)
				pb(a, b, info);
			else
				ra(a, info);
			i++;	
		}
		while (b->size > 0)
		{
			pa(a, b, info);
		}
		bit++;
	}
}
