#include "push.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*ptr ;

	ptr = malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->value = value;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

size_t	size_of_stack(t_stack *a)
{
	size_t count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

int is_sorted(t_stack *a)
{
	t_stack *next;

	if(!a || !a->next)
		return (1);
	while (a->next)
	{
		next = a->next;
		if (a->value > next->value )
			return (0);
		a = a->next;
	}
	return (1);
}

void free_stack(t_stack *a)
{
	t_stack *tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);	
	}
}
