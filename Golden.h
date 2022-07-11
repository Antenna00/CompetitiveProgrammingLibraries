#include <array>
#include <vector>
#include <cmath>

template<class T> std::array<double, 2> rotateMatrix(T x, T y, T deg) {
	const double rad = M_PI * deg / 180;
	return {
		x * std::cos(rad) - y * std::sin(rad),
		x * std::sin(rad) + y * std::cos(rad)
	};
}

template<class T, size_t _nElem> T innerProduct(std::array<T, _nElem>& lhs, std::array<T, _nElem>& rhs) {
	T product = 0;
	for (int i = 0; i < _nElem; ++i) {
		product += lhs[i] * rhs[i];
	}
	return product;
}

template<class T, size_t _nElem> T innerProduct(std::array<T, _nElem>&& lhs, std::array<T, _nElem>&& rhs) {
	T product = 0;
	for (int i = 0; i < _nElem; ++i) {
		product += lhs[i] * rhs[i];
	}
	return product;
}

template<class T> double innerProduct(T abslhs, T absrhs, double theta) {
	return abslhs * absrhs * std::cos(theta);
}

template<class T> T innerProduct(std::vector<T>& lhs, std::vector<T>& rhs) {
	T product = 0;
	for (int i = 0; i < lhs.size(); ++i) {
		product += lhs[i] * rhs[i];
	}
	return product;
}

template<class T> std::array<T, 3> crossProduct(std::array<T, 3>& lhs, std::array<T, 3>& rhs) {
	return {
		lhs[1] * rhs[2] - lhs[2] * rhs[1],
		lhs[2] * rhs[0] - lhs[0] * rhs[2],
		lhs[0] * rhs[1] - lhs[1] * rhs[0]
	};
}

template<class T> std::array<T, 3> crossProduct(std::vector<T>& lhs, std::vector<T>& rhs) {
	return {
		lhs[1] * rhs[2] - lhs[2] * rhs[1],
		lhs[2] * rhs[0] - lhs[0] * rhs[2],
		lhs[0] * rhs[1] - lhs[1] * rhs[0]
	};
}

#include <iostream>
#include <vector>

using namespace std;
  