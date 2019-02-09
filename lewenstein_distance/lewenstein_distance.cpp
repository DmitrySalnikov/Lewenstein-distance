#include "lewenstein_distance.h"
#include <cstdlib>
#include <cstring>
#include <algorithm>

size_t min(size_t a, size_t b, size_t c) {
	return std::min(std::min(a, b), std::min(a, c));
}

size_t lewenstein_distance(char const * sz1, char const * sz2) {
	size_t n = std::strlen(sz1);
	size_t m = std::strlen(sz2);

	size_t * a = new size_t [n + 1];
	for (size_t i{0}; i <= n; ++i) 
		a[i] = n - i;
	
	for (size_t i{1}; i <= m; ++i) {
		size_t diag = a[n];
		a[n] = i;

		for (size_t j{1}; j <= n; ++j) {
			size_t temp = a[n - j];

			if (sz1[n - j] != sz2[m - i])
				a[n - j] = 1 + min(a[n - j], a[n - j + 1], diag);
			else
				a[n - j] = diag;

			diag = temp;
		}
	}

	size_t answer = a[0];

	delete [] a;

	return answer;
}