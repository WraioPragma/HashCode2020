#include "global_include.hpp"
#include "Input.hpp"
#include "Output.hpp"

using namespace iter;

bool verify_solution(Input& input, Output& output){
	std::vector<bool> visited(input.b,false);
	for(auto&& book:chain.from_iterable(output.book_order)){
		if(visited[book]){
			return false;
		}
		visited[book] = true;
	}
	for(auto&& books : output.book_order){
		if(!check_decreasing(look_up(input.book_value,books))){
			std::cerr<< "We'Ve Got A Problem" << std::endl;
		}
	}
	return true;	
}


int score(Input& input, Output& output){	
	int total_sum = 0;
	auto rates  = look_up(input.rate,output.library_order);
	auto times	= iter::accumulate(look_up(input.sign_up_time,output.library_order)) ;
	for(auto&& [r,t,books] : zip(rates,times,output.book_order)){
		for(auto&& book : only_first(r*(input.d-t),books)){
			total_sum += input.book_value[book];
		}		
	}
	return total_sum;
}













