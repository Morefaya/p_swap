#include "push_swap.h"

void	del_content(void *content, size_t size)
{
	ft_bzero(content, size);
	free(content);
}
