#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>


template<class T> std::string convertIntToString(T value){
	stringstream ss;
	ss << value;
	string temp = ss.str();
	return temp;
}

template<class T> std::string convertIntToString2(T value){
	string temp = to_string(value);
	return temp;
}

template<class T> long long convertStrToInt(T str){
	long long temp = atoi(str.c_str());
	return temp;
}

template<class T> long long findFactorial(T nElem){
	long long temp = 1;
	for(int i = N; i > nElem; i--){
    temp *= i;   
  	}
 	return temp;
}

//最大公約数（ユークリッド互除法）
template<class T> long long eucridTwo(T A, T B){
	while(A >= 1 && B >= 1){
		if(A < B) B = B % A;
		else A = A % B;
	}
	if (A >= 1) return A;
	return B;
}

template<class T> long long eucridThree(T A, T B, T C){
	while(A >= 1 && B >= 1){
		if(A < B) B = B % A;
		else A = A % B;
	}
	if (A >= 1){
		while(A >= 1 && C >= 1){
			if(A < C) C = C % A;
			else A = A % C;
		}
	if (A >= 1) return A;
	return C;
	}else{
		while(B >= 1 && C >= 1){
			if(B < C) C = C % B;
			else B = B % C;
		}
	if (B >= 1) return B;
	return C;
	}
}

//素数判定
template<class T> bool isPrime(T value){
	for(long long i = 2; i * i <= N; ++i){
		if(N % i == 0) return false;
	}
	return true;
}

//約数列挙
template<class T> std::vector<long long> divisorList(T value){
	std::vector<long long> vec;
	for(long long i = 1; i * i <= value; ++i){
		if(value % i != 0) continue;
			vec.push_back(i);
		if(i != value / i){
			vec.push_back(value / i);
		}
	}
	return vec;
}

//エラトステネスのふるい
template<class T> std::vector<long long> eratosthenesPrimeList(T N, bool greater){
	
	std::vector<long long> vec;
	std::vector<bool> vprime(N + 1, true)


	for(int i = 2; i * i <= N; i++){
		if(vprime[i]){
			for(int x = 2 * 1; x <= N; x += i) vprime[x] = false;
		}
		if(!greater){
			for(int i = 2; i <= N; i++){
				if(vprime[i]){
					vec.push_back(i);
				}
				return vec;
			}
		}else{
			for(int i = 2; N >= i; i--){
				if(vprime[i]){
					vec.push_back(i);
				} 
				return vec;
			}
		}
	}
}

#include <iostream>
#include <vector>

template<class T> std::vector<long long> eratosthenesPrimeList(T N){
	
	std::vector<long long> vec;
	std::vector<bool> vprime(N + 1, true);


	for(int i = 2; i * i <= N; i++){
		if(vprime[i]){
			for(int x = 2 * 1; x <= N; x += i) vprime[x] = false;
		}
	}			

	for(int i = 2; i <= N; i++){
		if(vprime[i]){
			vec.push_back(i);
		}

	}		return vec;
}