// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <iterator>
#include <fstream>
#include <utility>
#include <tuple>
#ifndef Competition
# define Competition
#include "..\\..\\cppitertools\\itertools.hpp"



template<class T,class U>
auto look_up(const T& t,const U& u){
	return iter::imap([&](auto a){return t[a];},u);
}

template<class T>
auto only_first(int n,const T& t){
	return iter::starmap([&](auto a,auto b){return b;},iter::zip(iter::range(n),t));
	// return iter::slice(t,0,n,1);
}


template<class T>
auto check_decreasing(const T& t){
	return std::adjacent_find(t.begin(),t.end(),std::less<>{}) == t.end();
}

template<class T>
auto check_increasing(const T& t){
	return std::adjacent_find(t.begin(),t.end(),std::greater<>{}) == t.end();
}


template<class T>
auto count_unique(const T& t){
	auto unique = iter::unique_everseen(t);
	return std::count_if(unique.begin(),unique.end(),[](auto a){return true;});
}

// template <class ...Args>

//     return std::tuple_cat(std::tie(args)...);
// }

template <class ...Args>
auto make_flat(Args&& ...args) {
    return std::tuple_cat(std::tie(args)...);
}



// auto make_flat(long long unsigned int& x, std::tuple<int, const int&>&y) {
//     return std::tuple_cat(std::tie(x),y);
// }

// template <typename... Args>
// auto make_flat(Args &args,T) {
//     return std::tuple_cat(std::tie(args)...);
// }


template<class T>
auto flatten(const T& t){
	return iter::imap([](auto a){return a;},t);
}







#endif




