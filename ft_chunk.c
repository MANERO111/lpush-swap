#include "push.h"

int count_chunk_size(int n)
{
	if (n <= 100)
		return (15);
	if (n <= 500)
		return (30);
	return (45);
}

int find_max_pos(t_stack *b)
{
	t_node *cur;
	int max_pos;
	int max_idx;
	int pos;
	
	if (!b || !b->top)
		return (0);
	cur = b->top;
	max_pos = 0;
	pos = 0;
	max_idx = cur->index;
	while (cur)
	{
		if (cur->index > max_idx)
		{
			max_idx = cur->index;
			max_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (max_pos);
}

void    ft_chunk_sort(t_stack *a, t_stack *b, t_info *info)
{
	int chunk_size;
	int pos;
	int i;

	chunk_size = count_chunk_size(a->size);
	i = 0;
	while (a->top)
	{
		if (a->top->index <= i)
		{
			pb(a, b, info);
			rb(b, info);
			i++;
		}
		else if (a->top->index <= i + chunk_size)
		{
			pb(a, b, info);
			i++;
		}
		else
			ra(a, info);
	}
	while (b->top)
	{
		pos = find_max_pos(b);
		if (pos <= b->size / 2)
		{
			while (pos-- > 0)
				rb(b, info);
		}
		else
		{
			pos = b->size - pos;
			while (pos-- > 0)
				rrb(b, info);
		}
		pa(a, b, info);
	}
}