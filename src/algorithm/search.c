#include "algorithm/search.h"

#define SEARCH_IMPLEMENT(type) \
	int SEARCH_Binary_##type(const type *data, size_t size, type value) \
	{ \
		size_t left = 0; \
		size_t right = size; \
		while (left < right) \
		{ \
			size_t middle = left + (right - left) / 2; \
			if (data[middle] == value) return (int)middle; \
			if (data[middle] < value) left = middle + 1; \
			else right = middle; \
		} \
		return -1; \
	}

SEARCH_DECLARE(int)
SEARCH_IMPLEMENT(int)
