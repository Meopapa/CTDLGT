#ifndef SORT_H
#define SORT_H

#include <stddef.h>

#define SORT_DECLARE(type) \
	void SORT_Quick_##type(type *data, size_t size);

#endif
