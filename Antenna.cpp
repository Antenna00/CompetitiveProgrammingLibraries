#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

template<class T> long long findFactorial(T nElem){
	long long temp = 1;
	for(int i = N; i > nElem; i--){
    temp *= i;   
  	}
 	return temp;
}

template<class T> long long convertStrToInt(T str){
	int temp = atoi(str.c_str());
	return temp;
}

template<class T> string convertIntToString(T value){
	stringstream ss;
	ss << value;
	string temp = ss.str();
	return temp;
}

template<class T> string convertIntToString2(T value){
	string temp = to_string(value);
	return temp;
}


