#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;
	size_t	total_size;

	total_size = count * size;
	arr = malloc(total_size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, total_size);
	return (arr);
}
