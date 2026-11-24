#include "push.h"

int swap(t_stack *stack)
{
	t_node *first;
	t_node *second;
	t_node *third;
	
	if (!stack || stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	third = second->next;

	second->next = first;
	second->prev = NULL;
	first->prev = second;
	first->next = third;
	if(third)
		third->prev = first;
	else
		stack->bottom = first;
	stack->top = second;
	return (1);
}
void sa(t_stack *a, t_info *info)
{
	if (swap(a))
	{
		ft_putstr_fd("sa\n",1);
		if(info)
		{
			info->sa++;
			info->total++;
		}		
	}

}
void sb(t_stack *b, t_info *info)
{
	if(swap(b))
	{
		ft_putstr_fd("sb\n",1);
		if(info)
		{
			info->sb++;
			info->total++;
		}		
	}

}
void ss(t_stack *a, t_stack *b, t_info *info)
{
	int swa;
	int swb;

	swa = swap(a);
	swb = swap(b);
	if(swa || swb)
	{
		ft_putstr_fd("ss\n",1);
		if(info)
		{
			info->ss++;
			info->total++;
		}		
	}
}

int push(t_stack *a , t_stack *b)
{
	t_node *Anode;
	t_node *Bnode;

	if (!a || !b || !b->top)
		return (0);
	Anode = a->top;
	Bnode = b->top;
	b->top = Bnode->next;
	if(b->top)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	Bnode->next = Anode;
	Bnode->prev = NULL;
	if (Anode)
		Anode->prev = Bnode;
	else
		a->bottom = Bnode;
	a->top = Bnode;
	a->size++;
	b->size--;
	return (1);
}

void pa(t_stack *a, t_stack *b, t_info *info)
{
	if(push(a,b))
	{
		ft_putstr_fd("pa\n",1);
		if(info)
		{
			info->pa++;
			info->total++;
		}		
	}
}

void pb(t_stack *a, t_stack *b, t_info *info)
{
	if(push(b,a))
	{
		ft_putstr_fd("pb\n",1);
		if(info)
		{
			info->pb++;
			info->total++;
		}		
	}
}

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

