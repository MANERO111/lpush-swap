#include "push.h"

int count_chunk_size(int n)
{
    int size;

    size = 1;
    while (size * size < n)
        size++;
    return (25);
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
	int chunk_start ;
	int chunk_midpoint;
	int chunk_end;
	int chunk_size;
	int scan_count;
	int pos;
	int i;

	chunk_start = 0;
	chunk_size = count_chunk_size(a->size);
	while (a->size > 0)
	{
		i = 0;
		scan_count = a->size;
		chunk_end = (chunk_start + chunk_size - 1);
		chunk_midpoint = (chunk_end + 1) - (chunk_size / 2);
		while (i < scan_count)
		{
			if(a->top->index >= chunk_start && a->top->index <= chunk_end)
			{
				pb(a, b, info);
				if(b->top->index < chunk_midpoint)
					rb(b,info);
			}
			else
				ra(a, info);
			i++;
		}
		chunk_start += chunk_size;
	}
	while (b->top)
	{
		i = 0;
		pos = find_max_pos(b);

		if(pos <= b->size / 2)
			while (i < pos)
			{
				rb(b, info);
				i++;
			}
		else
			while (i < b->size - pos)
			{
				rrb(b, info);
				i++;
			}
		pa(a, b, info);
	}
}