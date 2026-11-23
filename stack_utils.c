#include "push.h"

t_node	*ft_lstnew(int value)
{
	t_node	*ptr ;

	ptr = malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr->value = value;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

void    ft_lstadd_back(t_stack *lst, t_node *new)
{
    if (!lst || !new)
        return ;
    if (lst->top == NULL)
    {
        lst->top = new;
        lst->bottom = new;
    }
    else
    {
        lst->bottom->next = new;
        new->prev = lst->bottom;
        lst->bottom = new;
    }
    lst->size++;
}

size_t	size_of_stack(t_stack *a)
{
	t_node *cur;
	size_t count;

	count = 0;
	cur = a->top;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	a->size = count;
	return (count);
}

int is_sorted(t_node *a)
{
	t_node *next;

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

void free_stack(t_node *a)
{
	t_node *tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);	
	}
}
