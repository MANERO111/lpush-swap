#include "push.h"

static int get_bit_count(int size)
{
    int max_index;
    int bits;

    max_index = size - 1;
    bits = 0;
    while (max_index > 0)
    {
        bits++;
        max_index >>= 1;
    }
    return (bits);
}


void ft_radix(t_stack *a, t_stack *b, t_info *info)
{
    int bit;
    int i;
    int stk_size;
    int bit_count;

    if (!a || !b || a->size < 2 || is_sorted(a->top))
        return ;
    stk_size = a->size;
    bit_count = get_bit_count(stk_size);
    bit = 0;
    while (bit < bit_count)
    {
        i = 0;
        while (i < stk_size)
        {
            if ((a->top->index >> bit) & 1)
                ra(a, info);
            else
                pb(a, b, info);
            i++;
        }
        while (b->size > 0)
            pa(a, b, info);
        bit++;
    }
}