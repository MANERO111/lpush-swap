#include "push.h"

static t_node *find_min(t_stack *a)
{
	t_node *cur;
	t_node *min;

	if(!a || !a->top)
		return (NULL);
	min = a->top;
	cur = a->top->next;
	while (cur)
	{
		if(cur->index < min->index)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

int find_pos(t_stack *a, t_node *min)
{
	t_node *cur;
	int i ;

	if (!a || !a->top || !min)
		return (-1);
	cur = a->top;
	i = 0;
	while (cur && cur != min)
	{
		i++;
		cur= cur->next;
	}
	if (!cur)
		return (-1);
	return (i);
	
}

void simple(t_stack *a, t_stack *b, t_info *info)
{
	t_node *min;
	int pos;

	if(!a || !b || a->size < 2)
		return ;
	while (a->size > 1)
	{
		min = find_min(a);
		pos = find_pos(a, min);
		if (pos == -1)
			return ;
		if(pos <= a->size / 2)
			while (a->top != min)
				ra(a,info);
		else
			while (a->top != min)
				rra(a,info);
		pb(a, b, info);
	}
	while (b->top)
	{
		pa(a,b,info);
	}
}