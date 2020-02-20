#include "global_include.hpp"
#include <bits/stdc++.h>
using namespace std;


class Output{
public:
	/* all of our data attributes */
	std::vector<int> libraries;
	std::vector<std::vector<int>> books;
	Output();
	void write_to_file(){
		std::cout<<libraries.size() << std::endl;;
		for(int i = 0; i < libraries.size(); i++){
			std::cout<<libraries[i] << " " << books[i].size() << std::endl;
			std::copy(books[i].begin(),books[i].end(),std::ostream_iterator<int>(std::cout," "));
			std::cout<< std::endl;
			
			
			
			
		}
		
		
	};

};






