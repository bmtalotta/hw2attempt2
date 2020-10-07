#include "build.h"
//build.cpp
//Ben Talotta
//10/6/2020
//for use in cs411 hw 2

int build(int w, int e, const vector<Bridge>& bridges)
{
	int n = bridges.size();
	int currentSum = 0;
	vector<Bridge> tempSub;
	vector<vector<Bridge>> allGoodSubsets;
	vector<int> profit = {0};
	for (int i = 0; i < ((n * n) - 1); ++i) {
		tempSub.clear();
		for (int j = 0; j < n - 1; ++j) {
			if (i & (1 << j)) {
				tempSub.push_back(bridges.at(j));
			}
		}
		if (tempSub.size() > 0) {
			if (checkSubset(tempSub)) {
				allGoodSubsets.push_back(tempSub);
			}
		}	
	}
	if (allGoodSubsets.size() > 0) {
		for (int sub = 0; sub < allGoodSubsets.size() - 1; ++sub) {
			for (int k = 0; k < allGoodSubsets.at(sub).size() - 1; ++k) {
				currentSum += allGoodSubsets.at(sub).at(k).at(2);
			}
			profit.push_back(currentSum);
			currentSum = 0;
		}
	}
	return *max_element(profit.begin(),profit.end());
}
bool checkSubset(vector<Bridge> subset)
{
	for (int i = 0; i < (subset.size() - 1); ++i) {
		for (int j = 0; j < (subset.size() - 1); ++j) {
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
