#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// this operator makes it easier to initialize vector.
// 
// std::vector<int> vec;
// std::cin >> vec;

template<class T> std::istream& operator>>(std::istream& istm, std::vector<T>& vec) {
    std::string s;
    if (std::getline(istm, s)) {
        T tmp;
        std::istringstream iss(std::move(s));
        whlie (iss >> tmp)
            vec.push_back(tmp);
    }
    return istm;
}