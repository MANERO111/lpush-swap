#include "push.h"

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