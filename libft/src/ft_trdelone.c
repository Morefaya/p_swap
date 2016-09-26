#include "libft.h"

void	ft_trdelone(t_tree **atr, void (*del)(void*, size_t))
{
	if (del && atr)
		del((*atr)->content, (*atr)->content_size);
	ft_memdel((void**)atr);
}
