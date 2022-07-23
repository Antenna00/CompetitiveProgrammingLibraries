#include <array>
#include <vector>
#include <cmath>
#include <thread>
#include <mutex>

template<class T> size_t abs(int i) {
	if (i > 0)
		return i;
	else
		return -i;
}

template<class T, size_t _nElem> long double abs(const std::array<T, _nElem>& arr) {
	T sum = 0;
	for (const auto& r : arr)
		sum += r * r;
	return std::sqrt(sum);
}

template<class T> long double abs(const std::vector<T>& vec) {
	T sum = 0;
	for (const auto& r : vec)
		sum += r * r;
	return std::sqrt(sum);
}

template<class T> std::array<double, 2> rotateVector(T x, T y, T deg) {
	const double rad = M_PI * deg / 180;
	return {
		x * std::cos(rad) - y * std::sin(rad),
		x * std::sin(rad) + y * std::cos(rad)
	};
}

template<class T> std::vector<double> rotateVector(std::vector<T>& vec, double deg) {
	const double rad = M_PI * deg / 100;
	return {
		vec.at(0) * std::cos(rad) - vec.at(1) * std::sin(rad),
		vec.at(0) * std::sin(rad) + vec.at(1) * std::cos(rad)
	}
}

template<class T> std::array<double, 2> rotateVector(std::array<T, 2>& arr, double deg) {
	const double rad = M_PI * deg / 100;
	return {
		arr.at(0) * std::cos(rad) - arr.at(1) * std::sin(rad),
		arr.at(0) * std::sin(rad) + arr.at(1) * std::cos(rad)
	}
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

template<class T, size_t n> std::array<T, n> operator*(std::array<std::array<T, n>, n>& mat, std::array<T, n>) {
	std::array<T, n> result;
	std::array<std::thread, n> threads;

	for (size_t i = 0; i < n; ++i) {
		threads.at(i) = std::thread([&](std::array<T, n>& matarr, std::array<T, n>& arr, T result) {
			for (size_t j = 0; j < n; ++j) {
				result += matarr.at(j) * arr.at(j);
			}
		}, mat.at(i), arr, result.at(i))
	}
	for (const auto& t : threads)
		t.join();
	
	return result;
}

