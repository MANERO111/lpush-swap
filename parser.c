#include "push.h"

void	ft_error(t_stack *a , char **str)
{
	if(a && a->top)
		free_stack(a->top);
	free_split(str);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int checkdbl(t_node *cur , int n)
{
	if (!cur)
		return (0);
	while (cur)
	{
		if (cur->value == n)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int ft_validate(t_stack *a, char *str )
{
	int value ;
	t_node *new;

	if (ft_atoi(str, &value))
		return (0);
	if (checkdbl(a->top,value))
		return (0);
	new = ft_lstnew(value);
	if (!new)
		return (0);
	ft_lstadd_back(a,new);
	return (1);
}

int check_flag(char *str , t_info *info)
{
	if (!str || !info)
		return (0);
	if (ft_strcmp(str,"--simple") == 0)
	{
		info->strategie = STRAT_SIMPLE;
		return (1);
	}
	else if (ft_strcmp(str,"--medium") == 0)
	{
		info->strategie = STRAT_MEDIUM;
		return (1);
	}
	else if (ft_strcmp(str,"--complex") == 0)
	{	
		info->strategie = STRAT_COMPLEX;
		return (1);
	}
	else if (ft_strcmp(str,"--adaptive") == 0)
	{
		info->strategie = STRAT_ADAPTIVE;
		return (1);
	}
	else if (ft_strcmp(str,"--bench") == 0)
	{
		info->bench = 1;
		return (1);
	}
	return (0);
}

void	parser(char **av, int ac ,t_stack *a, t_info *info)
{
	char **s;
	int i ;
	int j ;

	i = 1;
	if(check_flag(av[1],info))
		i++;
	while (i < ac)
	{
		s = ft_split(av[i], ' ');

		if(!s || *s == NULL)
			ft_error(a, s);
		j = 0;
		while (s[j])
			if(!ft_validate(a, s[j++]))
				ft_error(a, s);
		free_split(s);
		i++;
	}
}

