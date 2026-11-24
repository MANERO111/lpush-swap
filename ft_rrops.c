#include "push.h"

int reverse_rotate(t_stack *stack)
{
	t_node *last;

	if (!stack || stack->size < 2)
		return (0);
	last = stack->bottom;

	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
	return (1);
}

void rra(t_stack *a, t_info *info)
{
	if(reverse_rotate(a))
	{
		ft_putstr_fd("rra\n",1);
		if(info)
		{
			info->rra++;
			info->total++;
		}		
	}
}
void rrb(t_stack *b, t_info *info)
{
	if(reverse_rotate(b))
	{
		ft_putstr_fd("rrb\n",1);
		if(info)
		{
			info->rrb++;
			info->total++;
		}		
	}
}

void rrr(t_stack *a, t_stack *b, t_info *info)
{
	int rra_result;
	int rrb_result;

	rra_result = reverse_rotate(a);
	rrb_result = reverse_rotate(b);
	if (rra_result || rrb_result)
	{
		ft_putstr_fd("rrr\n",1);
		if(info)
		{
			info->rrr++;
			info->total++;
		}
	}
}