// #include <bits/stdc++.h>
#include "global_include.hpp"
using namespace std;

#ifndef Output_Hpp
# define Output_Hpp

class Output{
public:
	/* all of our data attributes */
	std::vector<int> library_order;
	std::vector<std::vector<int >> book_order;
	friend std::ostream& operator << (std::ostream& os,const Output& output);
};

std::ostream & operator << (std::ostream& os,const Output& output){
	std::cout<< output.book_order.size() << std::endl;
	for(auto&& [library,books] : iter::zip(output.library_order,output.book_order)){
		std::cout<< library << " " << books.size() << std::endl;
		// os<< library[0] << std::endl;
		
		std::copy(books.begin(),books.end(),std::ostream_iterator<int>(os," "));
		os << std::endl;
	}	
	return os;
}

std::istream& operator >> (std::istream& is, Output& output){
	int A,l,n;
	is >> A;
	output.library_order.resize(A);
	output.book_order.resize(A);
	for(int i = 0; i < A; i++){
		is >> output.library_order[i] >> n;		
		std::copy_n(std::istream_iterator<int>(is), n, std::back_inserter(output.book_order[i]));
	}	
	return is;
}







#endif