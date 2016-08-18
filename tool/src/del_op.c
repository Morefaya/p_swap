#include "tool.h"

void	del_op(void *content, size_t size)
{
	free(((t_op*)(content))->op);
	ft_bzero(content, size);
	free(content);
}
