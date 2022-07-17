#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
#include <stack>

#ifdef _STL_VECTOR_H
#	ifdef _BASIC_STRING_H
#		ifdef _GLIBCXX_SSTREAM
			namespace std {
				using istringstream = basic_string<char>;
			}
			template<class T> std::istream& operator>>(std::istream& istm, std::vector<T>& vec) {
				std::string s;
				if (std::getline(istm, s)) {
					T tmp;
					std::istringstream iss(std::move(s));
					while (iss >> tmp)
						vec.push_back(tmp);
				}
				return istm;
			}
#		endif // _GLIBCXX_IOSFWD
#	endif // _BASIC_STRING_H

	template<class T> std::ostream& operator<<(std::ostream& ostm, std::vector<T>& vec) {
		for (const auto& r : vec)
			ostm << r << ' ';
		return ostm;
}
#endif // _STL_VECTOR_H

#ifdef _GLIBCXX_ARRAY
	template<class T, size_t n, size_t m> std::istream& operator>>(std::istream& istm, std::array<std::array<T, n>, m>& arr) {
		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < m; ++j) {
				istm >> arr[i][j];
			}
		}
		return istm;
	}

	template<class T, size_t n> std::ostream& operator<<(std::ostream& ostm, std::array<T, n>& arr) {
		for (const auto& r : arr)
			ostm << r << ' ';
		return ostm;
	}
#endif // _GLIBCXX_ARRAY

#ifdef _STL_PAIR_H
	template<class T1, class T2> std::ostream& operator<<(std::ostream& ostm, std::pair<T1, T2>& p) {
		ostm << '{' << p.first << ", " << p.second << '}' << std::endl;
		return ostm;
	}
#endif // _STL_PAIR_H

#ifdef _STL_LIST_H
	template<class T> std::ostream& operator<<(std::ostream& ostm, std::list<T>& li) {
		for (const auto& r : li)
			ostm << r << ' ';
		return ostm;
	}
#endif // _STL_LIST_H

#ifdef _STL_DEQUE_H
	template<class T> std::ostream& operator<<(std::ostream& ostm, std::deque<T>& dq) {
		for (const auto& r : dq)
			ostm << r << ' ';
		return ostm;
	}
#endif // _STL_DEQUE_H

#ifdef _STL_STACK_H
	template<class T> std::ostream& operator<<(std::ostream& ostm, std::stack<T>& st) {
		for (const auto& r : st)
			ostm << r << ' ';
		return ostm;
	}
#endif // _STL_STACK_H

namespace utils {
	using HANDLE = void*;
#	ifdef _STL_ALGO_H
		template<class T, class _Pr> void sort(std::vector<T>& vec, _Pr pr) {
			std::sort(vec.begin(), vec.end(), pr);
		}
#	endif // _STL_ALGO_H
}