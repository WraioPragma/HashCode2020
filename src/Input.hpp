// #include <bits/stdc++.h>
#include "global_include.hpp"
using namespace std;

#ifndef Input_Hpp
# define Input_Hpp


class Input{
public:
	/* all of our data attributes */
	std::vector<std::vector<int >> libraries;
	std::vector<int > book_value,sign_up_time,rate;	
	std::vector<std::tuple<int,int >> sorted_book_values;
	std::vector<std::vector<int>> libraries_containing;
	int b,l,d;

};

std::istream& operator >> (std::istream& is, Input& input){
	int b,l,d,n;
	is >> b >> l >> d;

	std::vector<std::vector<int >> libraries(l),libraries_containing(b);
	std::vector<int > book_value,sign_up_time(l),rate(l);	
	std::vector<std::tuple<int,int >> sorted_book_values(b);
	// std::cout<< b << std::endl;
	
	std::copy_n(std::istream_iterator<int>(is), b, std::back_inserter(book_value));	
	for(int i = 0; i < l; i++){		
		is >> n >> sign_up_time[i] >> rate[i];
		std::copy_n(std::istream_iterator<int>(is), n, std::back_inserter(libraries[i]));
	}

	for(auto&& [i,item] : iter::enumerate(sorted_book_values)){
		item = {book_value[i],i};
	}
	std::sort(sorted_book_values.begin(),sorted_book_values.end(),std::greater{});

	for(auto&& [library,books] : iter::enumerate(libraries)){
		for(auto book : books){
			libraries_containing[book].push_back(library);
		}
		
	}

	for(auto& books : libraries){
		std::sort(books.begin(),books.end(), [&]( const auto a,const auto b){
			if(book_value[a] > book_value[b]){
				return true;
			}
			else if(book_value[a] == book_value[b]){
				return a>b;
			}
			else{
				return false;
			}
		});
	}


			
	input.b = b;
	input.l = l;
	input.d = d;
	input.book_value = book_value;
	input.sorted_book_values = sorted_book_values;
	input.sign_up_time = sign_up_time;
	input.rate = rate;
	input.libraries = libraries;
	input.libraries_containing = libraries_containing;
	
	return is;
}


#endif