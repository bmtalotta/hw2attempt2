#include "build.h"
//build.cpp
//Ben Talotta
//10/6/2020
//for use in cs411 hw 2

int build(int w, int e, const vector<Bridge>& bridges)
{
	int n = bridges.size();
	int currentSum = 0;
	int posProf = 0;
	vector<Bridge> tempSub;
	vector<vector<Bridge>> allGoodSubsets;
	vector<vector<Bridge>> allSubsets;
	vector<int> profit = { 0 };
	for (int i = 0; i < n*n; i++) {
		int temp = i;
		posProf = 0;
		tempSub.clear();
		for (int j = 0; j < n; j++) {
			if ((temp & 1)) {
				posProf += bridges.at(j).at(2);
				tempSub.push_back(bridges.at(j));
			}
			temp >>= 1;
		}
		allSubsets.push_back(tempSub);
		if (checkSubset(tempSub)) {
			allGoodSubsets.push_back(tempSub);
			profit.push_back(posProf);
		}
			
	}
	for (auto n : profit) {
		cout << n << ", ";
	}
	cout << "\n";
	//cout << *max_element(profit.begin(), profit.end()) << "\n";
/*
	if (allGoodSubsets.size() > 0) {
		for (int sub = 0; sub < allGoodSubsets.size(); sub++) {
			for (int k = 0; k < allGoodSubsets.at(sub).size(); k++) {
				currentSum += allGoodSubsets.at(sub).at(k).at(2);
			}
			profit.push_back(currentSum);
			currentSum = 0;
		}
	}
	*/
	return *max_element(profit.begin(),profit.end());
}
bool checkSubset(vector<Bridge> subset)
{
	for (int i = 0; i < subset.size(); i++) {
		for (int j = 0; j < subset.size(); j++) {
			if (j > i) {
				if (((subset.at(i).at(0) == subset.at(j).at(0)) || (subset.at(i).at(1) == subset.at(j).at(1))) ||  //two bridges same city
					((subset.at(i).at(0) > subset.at(j).at(0)) && (subset.at(i).at(1) < subset.at(j).at(1))) ||	//first way bridges can cross
					((subset.at(i).at(0) < subset.at(j).at(0)) && (subset.at(i).at(1) > subset.at(j).at(1)))) {	//second way bridges can cross
					return false;
				}
			}
		}
	}
	return true;
}
