#ifndef SEARCH_H
#define SEARCH_H

#include <stddef.h>

#define SEARCH_DECLARE(type) \
	int SEARCH_Binary_##type(const type *data, size_t size, type value);

#endif
