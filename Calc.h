#include <cmath>
#include <vector>
#include <array>
#include <stack>
#include <map>

unsigned long long factorial(const unsigned n) {
	unsigned long long tmp = 1;
	for (unsigned i = 1; i <= n; ++i)
		tmp *= i;
	return tmp;
}

unsigned long long permutation(const unsigned n, const unsigned m) {
	unsigned long long tmp = 1;
	for (unsigned i = n; i <= m; ++i)
		tmp *= i;
	return tmp;
}

unsigned long long combination(const unsigned n, const unsigned m) {
	if (n - m < m)
		return combination(n, n - m);
	else
		return permutation(n, m) / factorial(m);
}

template<class T> T average(T* arr, size_t arrlen) {
	T sum = 0;
	for (size_t i = 0; i < arrlen; ++i) {
		sum += *(arr + i);
	}
	return sum;
}

#ifdef _STL_VECTOR_H
	template<class T> T average(std::vector<T>& vec) {
		T sum = 0;
		for (const auto& r : vec) {
			sum += r;
		}
		return sum / vec.size();
	}
#ifdef _STL_ALGO_H
	template<class T> T median(std::vector<T>& vec) {
		std::sort(vec.begin(), vec.end());
		if (vec.size() % 2)
			return (vec.at(vec.size() / 2) + 1);
		else
			return (vec.at(vec.size() / 2) + vec.at(vec.size() / 2 + 1));
	}
#endif // _STL_ALGO_H
#endif // _STL_VECTOR_H

#ifdef _GLIBCXX_ARRAY
	template<class T, size_t n> T average(std::array<T, n>& arr) {
		T sum = 0;
		for (const auto& r : arr) {
			sum += r;
		}
		return sum / n;
	}
#ifdef _STL_ALGO_H
	template<class T, size_t n> T median(std::array<T, n>& arr) {
		std::sort(arr.begin(), arr.end());
		if (arr.size() % 2)
			return (arr.at(arr.size() / 2) + 1);
		else
			return (arr.at(arr.size() / 2) + arr.at(arr.size() / 2 + 1)) / 2;
	}
#endif // _STL_ALGO_H
#endif // _GLIBCXX_ARRAY

#ifdef _STL_STACK_H
	template<class T> T average(std::stack<T>& st) {
		T sum = 0;
		for (const auto& r : st) {
			sum += r;
		}
		return sum / st.size();
	}
#endif // _STL_STACK_H