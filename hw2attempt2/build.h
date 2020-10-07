//build.h
//Ben Talotta
//9/28/2020
//for use in cs411 hw 2

#ifndef build_HPP
#define build_HPP
#include <vector>
#include <algorithm>
using std::vector;
using Bridge = vector<int>;
int build(int w, int e, const vector<Bridge>& bridges);
bool checkSubset(vector<Bridge> subset);
int subSetProfit(vector<Bridge> subset);
#endif "!build_H"