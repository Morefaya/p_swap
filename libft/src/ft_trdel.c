#include "libft.h"

void	ft_trdel(t_tree **atr, void (*del)(void*, size_t))
{
	if (!atr || !del)
		return ;
	if (!*atr)
		return ;
	if ((*atr)->left)
		ft_trdel(&(*atr)->left, del);
	if ((*atr)->right)
		ft_trdel(&(*atr)->right, del);
	ft_trdelone(atr, del);
}
