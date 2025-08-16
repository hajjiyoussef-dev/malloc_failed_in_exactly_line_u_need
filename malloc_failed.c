// line for malloc failed only!!!!

#include <string.h>
static inline void *p(size_t size, char *file, int line)
{
	if (strstr(file, "main.c") && line == 22)
		return (NULL);
	return (malloc(size));
}
#define malloc(x) p((x), __FILE__, __LINE__)


// only write in the header file to worke
