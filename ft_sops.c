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


