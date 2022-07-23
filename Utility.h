#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
#include <stack>
#include <thread>
#include <iosfwd>

using llong = long long;

#ifdef _STL_VECTOR_H 
#if defined(_GLIBCXX_SSTREAM) && defined(_BASIC_STRING_H)
	template<class T> std::istream& operator>>(std::istream& istm, std::vector<T>& vec) {
		std::string s;
		if (std::getline(istm, s)) {
			T tmp;
			std::istringstream iss(std::move(s));
			while (iss >> tmp)
				vec.push_back(tmp);
			return istm;
		}
		else
			return istm;
	}
#endif // _GLIBCXX_SSTREAM &&  _BASIC_STRING_H
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
#if defined(_BASIC_STRING_H) && defined (_GLIBCXX_SSTREAM)
	template<class T> std::istream& operator>>(std::istream& istm, std::deque<T>& dq) {
		std::string s;
		if (std::getline(istm, s)) {
			std::istringstream iss(std::move(s));
			T tmp;
			while (iss >> tmp) {
				dq.push_back(tmp);
			}
			return istm;
		}
		return {};
	}
#endif // _GLIBCXX_SSTREAM && _BASIC_STRING_H
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
#ifdef _STL_ALGO_H
#ifdef _STL_VECTOR_H
	template<class T, class _Pr> void sort(std::vector<T>& vec, _Pr pr) {
			std::sort(vec.begin(), vec.end(), pr);
	}

	template<class T> void sort(std::vector<T>& vec) {
		std::sort(vec.begin(), vec.end());
	}

	template<class T> void movetoOneLeft(std::vector<T>& vec) {
		for (size_t i = 0; i < vec.size(); ++i) {
			std::swap(vec.at(i), vec.at(i + 1));
		}
	}

	template<class T> void movetoOneRight(std::vector<T>& vec) {
		for (size_t i = vec.size() - 1; i > 0; ++i) {
			std::swap(vec.at(i), vec.at(i - 1));
		}
	}
#endif // _STL_VECTOR_H
#ifdef _GLIBCXX_ARRAY
	template<class T, size_t n, class _Pr> void sort(std::array<T, n>& arr, _Pr pr) {
		std::sort(arr.begin(), arr.end(), pr);
	}

	template<class T, size_t n> void sort(std::array<T, n>& arr) {
		std::sort(arr.begin(), arr.end());
	}

	template<class T, size_t n> void movetoOneLeft(std::vector<T>& arr) {
		for (size_t i = 0; i < arr.size(); ++i) {
			std::swap(arr.at(i), arr.at(i + 1));
		}
	}

	template<class T, size_t n> void movetoOneRight(std::array<T, n>& arr) {
		for (size_t i = arr.size() - 1; i > 0; ++i) {
			std::swap(arr.at(i), arr.at(i - 1));
		}
	}
#endif // _GLIBCXX_ARRAY
#endif // _STL_ALGO_H
#ifdef _GLIBCXX_STRING
	bool containsString(std::string& s1, const std::string& s2) {
		return (s1.npos != s1.find(s2));
	}

	void movetoOneLeft(std::string& s) {
		for (size_t i = 0; i < s.size() - 1; ++i) {
			std::swap(s.at(i), s.at(i + 1));
		}
	}

	void movetoOneRight(std::string& s) {
		for (size_t i = s.size() - 1; i > 0; --i) {
			std::swap(s.at(i), s.at(i - 1));
		}
	}
#endif // _GLIBCXX_STRING
}

#include <pthread.h>
#if defined(_PTHREAD_H)
#ifdef _LOCAL
static const char* pthread_path = "";
#else
static const char* pthread_path = "/lib/x86_64-linux-gnu/libpthread.so.0";
#endif
extern "C" void* __libc_dlopen_mode(const char* ch, int n);
extern "C" void* __libc_dlsym(void* p, const char* ch);


namespace thread {

}

#endif // _PTHREAD_H