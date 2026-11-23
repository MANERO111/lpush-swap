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
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *s;
	t_info info;

	if(ac == 1)
		return (0);
	a = NULL;
	//b = NULL;
	init_info(&info);
	parser(av, ac, &a, &info);
	ft_index_stack(a);
	info.disorder = ft_disorder(a);
	printf("%.2f\n",info.disorder);
	printf("strategy %d\n", info.strategie);
	if(is_sorted(a))
	{
		printf("the stack already sorted");
		free_stack(a);
		return (0);
	}
	s = a;
	while (s)
	{
		printf("index : %d | value %d\n",s->index,s->value);
		s = s->next;
	}
}
