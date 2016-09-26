#include "libft.h"
#include <stdlib.h>

t_tree	*ft_trnew(const void *content, size_t content_size)
{
	t_tree	*new;

	if (!content || !content_size)
		return (NULL);
	if (!(new = (t_tree*)ft_memalloc(sizeof(*new))))
		return (NULL);
	if (content)
	{
		if (!(new->content = ft_memalloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->left = NULL;
	new->right = NULL;
	return (new);
}
