#include "build.h"
//build.cpp
//Ben Talotta
//10/6/2020
//for use in cs411 hw 2

//scratch delete me

int build(int w, int e, const vector<Bridge>& bridges)
{
	int n = bridges.size();
	int currentSum = 0;
	int posProf = 0;
	vector<vector<Bridge>> existingSubSets;
	vector<vector<Bridge>> allGoodSubsets;
	vector<vector<Bridge>> allSubSets;
	vector<int> profit = { 0 };
	if (bridges.size() == 1) {
		return bridges.at(0).at(2);
	}
	for (auto curBridge : bridges) {
		vector<vector<Bridge>> cpyAllSubSets = allSubSets;
		for (auto &&subSet: existingSubSets) {
			subSet.push_back(curBridge);
			allSubSets.push_back(subSet);
		}			
	}
	for (int i = 0; i < allSubSets.size(); i++) {
		if (checkSubset(allSubSets.at(i))) {
			profit.push_back(subSetProfit(allSubSets.at(i)));
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
	return 0;
}
