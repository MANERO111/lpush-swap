#include "push.h"
#include <stdio.h>

void init_info(t_info *i)
{
	i->disorder = 0;
	i->strategie = STRAT_ADAPTIVE;
	i->bench = 0;
	i->pa = 0;
	i->pb = 0;
	i->ra = 0;
	i->rb = 0;
	i->rr = 0;
	i->rra = 0;
	i->rrb = 0;
	i->rrr = 0;
	i->sa = 0;
	i->sb = 0;
	i->ss = 0;
	i->total = 0;
}
void init(t_stack *a)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
}

int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	t_node *s;
	t_info info;

	if(ac == 1)
		return (0);
	
	init(&a);
	init(&b);
	init_info(&info);
	parser(av, ac, &a, &info);
	ft_index_stack(a.top);
	info.disorder = ft_disorder(a.top);
	//printf("%.2f\n",info.disorder);
	//printf("strategy %d\n", info.strategie);
	if(is_sorted(a.top))
	{
		printf("the stack already sorted");
		free_stack(a.top);
		init(&a);
		return (0);
	}
	ft_radix(&a,&b,&info);
	s = a.top;
	while (s)
	{
		printf("index : %d | value %d\n",s->index,s->value);
		s = s->next;
	}
	s= b.top;
	printf("stack b\n");
	while (s)
	{
		printf("index : %d | value %d\n",s->index,s->value);
		s = s->next;
	}
	printf("%d\n",info.total);
	free_stack(b.top);
	free_stack(a.top);
}
