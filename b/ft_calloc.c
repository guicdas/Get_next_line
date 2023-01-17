#include <stdlib.h>

void *calloc(size_t nitems, size_t size)
{
	return (malloc(nitems * size));
}