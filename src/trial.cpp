// #include <bits/stdc++.h>
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
	auto homelandtimes	= iter::accumulate(look_up(input.sign_up_time,output.library_order)) ;
	for(auto&& [r,t,books] : zip(rates,times,output.book_order)){
		for(auto&& book : only_first(r*(input.d-t),books)){
			total_sum += input.book_value[book];
		}		
	}
	return total_sum;

	// int total_sum = 0;
	// int total_time = 0;
	// int o = 0;
	// int counter = 0;
	// for(auto& x:output.book_order){
	// 	o = output.library_order[counter];
	// 	total_time += input.sign_up_time[o];
	// 	if(total_time>=input.d){
	// 		break;
	// 	}
	// 	auto ending = x.end();
	// 	if((input.d-total_time)*input.rate[o]<x.size()){
	// 		std::cout<< ((input.d-total_time)*input.rate[o]) << std::endl;
	// 		ending = x.begin() + ((input.d-total_time)*input.rate[o]);
	// 	}
	// 	counter++;
	// 	total_sum += std::accumulate(x.begin(),ending,0,[&](auto a,auto b){return a + input.book_value[b];});
	// }

	// return total_sum;
}





int main(){
	Input input;
	Output output;
	std::ifstream is,fo;
	is.open(std::string("input\\b.txt"));
	fo.open(std::string("best\\b.txt"));
	std::cout<< "hello" << std::endl;
	fo >> output;
	std::cout<< "Don output" << std::endl;
	// std::cout<< output;	
	is >> input;
	std::cout<< "done input" << std::endl;
	std::cout<< score(input,output) << std::endl;		
	std::cout<< verify_solution(input,output) << std::endl;

}
