#include <cmath>

unsigned long long factorial(const unsigned n) {
	unsigned long long tmp = 1;
	for (unsigned i = 1; i <= n; ++i)
		tmp *= i;
	return tmp;
}

unsigned long long permutation(const unsigned n, const unsigned m) {
	unsigned long long tmp = 1;
	for (unsigned i = 1; i <= m; ++i)
		tmp *= i;
	return tmp;
}

unsigned long long combination(const unsigned n, const unsigned m) {
	if (n - m < m)
		return combination(n, n - m);
	else
		return permutation(n, m) / factorial(m);
}