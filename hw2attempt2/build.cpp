#include "build.h"
//build.cpp
//Ben Talotta
//10/6/2020
//for use in cs411 hw 2


int build(int w, int e, const vector<Bridge>& bridges)
{
	vector<vector<Bridge>> allSubSets{ vector<Bridge>() };
	vector<int> profit = { 0 };

	if (bridges.size() == 1) {
		return bridges.at(0).at(2);
	}

	for (const auto curBridge : bridges) {
		vector<vector<Bridge>> cpyAllSubSets = allSubSets;
		for (auto &subSet : cpyAllSubSets) {
			subSet.push_back(curBridge);
			allSubSets.push_back(subSet);
			if (checkSubset(subSet)) {
				profit.push_back(subSetProfit(subSet));
			}
		}			
	}
	return *max_element(profit.begin(),profit.end());
}
bool checkSubset(vector<Bridge> subset)
{
	for (int i = 0; i < subset.size(); i++) {
		for (int j = i+1; j < subset.size(); j++) {
			if (((subset.at(i).at(0) == subset.at(j).at(0)) || (subset.at(i).at(1) == subset.at(j).at(1))) ||  //two bridges same city
				((subset.at(i).at(0) > subset.at(j).at(0)) && (subset.at(i).at(1) < subset.at(j).at(1))) ||	//first way bridges can cross
				((subset.at(i).at(0) < subset.at(j).at(0)) && (subset.at(i).at(1) > subset.at(j).at(1)))) {	//second way bridges can cross
				return false;
			}
		}
	}
	return true;
}

int subSetProfit(vector<Bridge> subset)
{
	int profit = 0;
	for (int i = 0; i < subset.size(); i++) {
		profit += subset.at(i).at(2);
	}
	return profit;
}
