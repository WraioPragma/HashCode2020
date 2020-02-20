#include "global_include.hpp"
#include <bits/stdc++.h>
using namespace std;


class Output{
public:
	/* all of our data attributes */

	void write_to_file(vector<pair<int,vector<Book*>>> activity) {
		cout << activity.size() << endl;
		for (int i = 0; i < activity.size(); i++) {
			cout << activity[i].first << " " << activity[i].second.size() << endl;
			for (int j = 0; j < activity[i].second.size(); j++) {
				cout << activity[i].second[j]->id << " ";
			} cout << endl;
		}
	}

};






