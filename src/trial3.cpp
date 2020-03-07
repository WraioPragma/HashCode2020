// #include <bits/stdc++.h>
#include "global_include.hpp"
#include <random>
#include <chrono>
#include "Input.hpp"
#include "Output.hpp"
#include "score.hpp"

void greedy(Input& input, Output& output){
	int days_left = input.d;
	std::vector<bool> book_scanned(input.b,false);
	std::vector<int> library_order;
	std::vector<std::vector<int>> book_order;
	std::vector<std::tuple<int,int>> candidates(input.l);

	for(auto&& [i,item] : enumerate(candidates)){
		auto&& [value,library] = item;
		library = i;
		value = 0;
	}

	auto not_scanned  = [&](auto book){
		return !book_scanned[book];
	};

	auto estimate_value  = [&](auto library){
		int total = 0;
		auto maximum_number  = (days_left-input.sign_up_time[library]) * input.rate[library];		
		auto available_books  = filter(not_scanned,input.libraries[library]);
		for(auto book : only_first(maximum_number,available_books)){
			// std::cerr<< book << std::endl;
			total += input.book_value[book];
		}
		// return total/input.sign_up_time[library]/input.sign_up_time[library];
		return total/input.sign_up_time[library];
	};

	auto library_can_be_included = [&](auto &candidate){
		auto& [value,library]  = candidate;
		return value>0 && input.sign_up_time[library]<days_left;
	};

	auto candidate = candidates.begin();



	while (candidate  != candidates.end()){
		for(auto&& [value,library] : candidates){
			value = estimate_value(library);
		}
		// std::cout<< "something" << std::endl;
		std::sort(candidate,candidates.end(),std::greater{});
		candidate = std::find_if(candidate,candidates.end(),library_can_be_included);
		if(candidate != candidates.end()){
			auto&& [value,library]  = *candidate;
			library_order.push_back(library);
			std::vector<int> temporary;
			auto maximum_number  = (days_left-input.sign_up_time[library]) * input.rate[library];		
			auto available_books  = filter(not_scanned,input.libraries[library]);
			for(auto book : only_first(maximum_number,available_books)){
			
		
			
				temporary.push_back(book);
				book_scanned[book] = true; 
			}
			book_order.push_back(temporary);
			days_left -= input.sign_up_time[library];
			candidate++;
		}
	}
	output.library_order = library_order;
	output.book_order = book_order;
}



auto optimize_book_order(Input &input,std::vector<int> &library_order){
	std::vector<bool> library_included_in_order(input.l,false);
	std::vector<std::vector<int>> book_order(input.l);
	std::vector<std::tuple<	std::vector<int>::iterator,	std::vector<int>::iterator>> state(input.l);

	for(auto library : library_order){
		library_included_in_order[library] = true;
	}

	for(auto& books : input.libraries){
		std::sort(books.begin(),books.end(), [&]( const auto a,const auto b){
			if(input.book_value[a] > input.book_value[b]){
				return true;
			}
			else if(input.book_value[a] == input.book_value[b]){
				return a>b;
			}
			else{
				return false;
			}
		});
	}
	// std::cerr<< "I did not even make it here" << std::endl;

	int time_left = input.d;
	for(auto library : library_order){
		time_left-=input.sign_up_time[library];
		int starting  = time_left*input.rate[library];
		int initial  = std::min(starting,(int)input.libraries[library].size());
		state[library] = {input.libraries[library].begin()+initial,input.libraries[library].end()};
	}
	
	
	auto library_available = [&](auto library){
		// std::cerr<< library << std::endl;
		return library_included_in_order[library];
	};
		
	auto following_books_value = [&](auto item){
		auto [following,ending]  = item;
		if(following==ending){
			return 0;
		}
		// if(following>ending){
		// 	std::cerr<< "Disaster" << std::endl;
		// 	return 0;
		// }
		return input.book_value[*following];
	};	
	int number = 0;
	for(auto&& [value,book] : input.sorted_book_values){
		int minimum = 100000000,position=-1;
		// std::cerr<< book << std::endl;
		for(auto&& library : filter(library_available,input.libraries_containing[book])){
			// std:Glenside:cerr<< library << std::endl;
			int gain = following_books_value(state[library]);
			if(gain<=minimum && gain<=value){
				minimum = gain; position = library;
			}
			if(gain>value){
				// std::cerr<< " we have a problem " << std::endl;
				// std::cerr<< gain << " " << value << std::endl;
			}
		}
		// std::cerr<< book << std::endl;

		if(position==-1){
			// std::cerr<< book << std::endl;
			continue;
		}
		number++;
		book_order[position].push_back(book);
		for(auto&& library : filter(library_available,input.libraries_containing[book])){
			if(library!=position){
				auto&& [following_book,ending]   = state[library];
				if(following_book!=ending){
					++following_book;
				}
			}
		}

	}
	// std::cerr<< book_order.size() << std::endl;
	// book_order.erase(std::remove_if(book_order.begin(),book_order.end(),[=](auto a){return a.size()==0;}),book_order.end());
	std::vector<std::vector<int >> output_order;
	for(auto library : library_order){
		output_order.push_back(book_order[library]);
	}
	
	// std::cerr<< "Optimize received" << " " <<  library_order.size() << " " << " libraries but outputted " << " " << output_order.size() << std::endl;
	// auto theoretical = count_unique(chain.from_iterable(look_up(input.libraries,library_order)));	
	// auto practical = count_unique(chain.from_iterable(output_order));
	// std::cerr<< "These libraries contained" << " " << theoretical << " " << "books and we got" << " " << practical << std::endl;	
	return output_order;
}


auto iterator_optimization(Input& input, Output& output){
	auto best  = output;
	auto best_score  = score(input,output);
	auto& library_order  = best.library_order;
	auto initial  = best.library_order;

	std::random_device rd;
	std::mt19937 generator(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
	// std::mt19937 generator(rd());
	std::vector<int> weights(library_order),weights2(library_order);
	std::transform(weights.begin(),weights.end(),weights.begin(),[&](auto a){return input.sign_up_time[a];});
	auto avg  = std::accumulate(weights.begin(),weights.end(),0)/weights.size();
	std::transform(weights2.begin(),weights2.end(),weights2.begin(),[&](auto a){return (a-avg)*(a-avg);});
	std::discrete_distribution<int> distribution(weights.begin(), weights.end());
	std::discrete_distribution<int> distribution2(weights2.begin(), weights2.end());
	

	for(int i = 0; i < 100; i++){
		// auto u  = distribution(generator);
		// auto v  = distribution(generator);
		int u,v;
		if(best_score<5222140||best_score>5225800){
		// if(best_score<5317960){
			u  = distribution(generator);
		 	v  = distribution(generator);
		}else{
			u  = distribution2(generator);
			v  = distribution2(generator);

		}
		if(u==v){
			continue;
		}
		std::swap(library_order[u],library_order[v]);
		Output trial;
		trial.library_order = library_order;
		trial.book_order = optimize_book_order(input,library_order);
		auto trial_score  = score(input,trial);
		if(trial_score>best_score){
			best = trial;
			best_score = trial_score;
		}else{
			std::swap(library_order[u],library_order[v]);
		}
		auto libraries_used  = std::count_if(trial.book_order.begin(),trial.book_order.end(),[&](auto a){return a.size()!=0;});
		if(libraries_used != library_order.size()){
			std::cerr<< "Out of the" << " " << library_order.size() << " " << " value duration ended with " << " " <<  libraries_used<< std::endl;
		}
	}
	
	output = best;
	output.book_order = optimize_book_order(input,output.library_order);
	std::vector<int> new_library_order;
	for(auto&& [library,books] : zip(output.library_order,output.book_order)){
		if(books.size()!=0){
			new_library_order.push_back(library);
		}		
	}
	output.library_order = new_library_order;
	output.book_order = optimize_book_order(input,output.library_order);

	std::cerr<< "After I duration "<< score(input,output) << std::endl;

	auto theoretical = count_unique(chain.from_iterable(look_up(input.libraries,initial)));	
	auto practical = count_unique(chain.from_iterable(output.book_order));
	std::cerr<< "Optimize Iterator received" << " " <<  initial.size() << " " << " libraries but outputted " << " " << output.library_order.size() << std::endl;
	std::cerr<< "These libraries contained" << " " << theoretical << " " << "books and we got" << " " << practical << std::endl;	

}


int main(){
	Input input;
	Output output;
	std::cin>>input;
	greedy(input,output);
	std::cerr<< score(input,output) << std::endl;
	// std::cout<< output;
	output.book_order = optimize_book_order(input,output.library_order);
	std::vector<int> new_library_order;
	for(auto&& [library,books] : zip(output.library_order,output.book_order)){
		if(books.size()!=0){
			new_library_order.push_back(library);
		}
		
	}
	output.library_order = new_library_order;
	output.book_order = optimize_book_order(input,output.library_order);

	std::cerr<< score(input,output) << std::endl;
	// output.book_order = optimize_book_order(input,output.library_order);

	std::cerr<< score(input,output) << std::endl;


	for(int i = 0; i < 100; i++){
		iterator_optimization(input,output);
	}
	
	std::cout<< output;
	// std::cout<< verify_solution(input,output) << std::endl;


}
