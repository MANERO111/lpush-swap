#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

# define STRAT_SIMPLE   1
# define STRAT_MEDIUM   2
# define STRAT_COMPLEX  3
# define STRAT_ADAPTIVE 4

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_info
{
	int	strategie;
	double disorder;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
} t_info;

char	**ft_split(char const *s, char c);
t_stack	*ft_lstnew(int value);
int		ft_atoi(const char *nptr, int *n);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	parser(char **av, int ac ,t_stack **a, t_info *info);
void	ft_index_stack(t_stack *a);
double 	ft_disorder(t_stack *a);
int 	is_sorted(t_stack *a);
size_t	size_of_stack(t_stack *a);
void	free_split(char **str);
void 	free_stack(t_stack *a);
int		ft_strcmp(const char *s1, const char *s2);

#endif