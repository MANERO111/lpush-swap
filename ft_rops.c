#include "push.h"

int rotate(t_stack *stack)
{
	t_node *last;
	t_node *first;

	if (!stack || stack->size < 2)
		return (0);
	last = stack->bottom;
	first = stack->top;

	stack->top = first->next;
	stack->top->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->bottom = first;
	
	return (1);
}

void ra(t_stack *a, t_info *info)
{
	if(rotate(a))
	{
		ft_putstr_fd("ra\n",1);
		if(info)
		{
			info->ra++;
			info->total++;
		}		
	}
}

void rb(t_stack *b, t_info *info)
{
	if(rotate(b))
	{
		ft_putstr_fd("rb\n",1);
		if(info)
		{
			info->rb++;
			info->total++;
		}		
	}
}

void rr(t_stack *a, t_stack *b, t_info *info)
{
	int ra_result;
	int rb_result;

	ra_result = rotate(a);
	rb_result = rotate(b);
	if(ra_result || rb_result)
	{
		ft_putstr_fd("rr\n",1);
		if(info)
		{
			info->rr++;
			info->total++;
		}		
	}
}