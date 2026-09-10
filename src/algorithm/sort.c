#include "algorithm/sort.h"

#define SORT_IMPLEMENT(type) \
	void SORT_Quick_##type(type *data, size_t size) \
	{ \
		size_t i; \
		size_t j; \
		type pivot; \
		type temporary; \
		if (data == NULL || size < 2) return; \
		i = 0; \
		j = size - 1; \
		pivot = data[size / 2]; \
		while (i <= j) \
		{ \
			while (data[i] < pivot) i++; \
			while (data[j] > pivot) j--; \
			if (i <= j) \
			{ \
				temporary = data[i]; \
				data[i] = data[j]; \
				data[j] = temporary; \
				i++; \
				if (j > 0) j--; \
			} \
		} \
		if (j > 0) SORT_Quick_##type(data, j + 1); \
		if (i < size) SORT_Quick_##type(data + i, size - i); \
	}

SORT_DECLARE(int)
SORT_IMPLEMENT(int)
