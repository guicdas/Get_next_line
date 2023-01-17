#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	size1;
	t size2;
	char *s;

	s = (char *)src;
	size1 = ft_strlen(dst);
	size2 = ft_strlen(s);
	if (size1 < size - 1 && size > 0)
	{
		while (*src && size1 + i < size - 1)
		{
			dst[size2] = *src;
			src++;
			size2++;
		}
		dst[size] = '\0';
	}
	if (size2 >= size)
		size2 = size;
	return (size1 + size2);
}