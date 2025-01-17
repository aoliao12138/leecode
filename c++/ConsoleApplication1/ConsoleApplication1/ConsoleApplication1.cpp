// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		map<int, int> dict;
		for (int a = 0; a<nums.size(); a++) {
			int b = dict.count(nums[a]);
			if (b != 0) {
				result.push_back(dict[nums[a]]);
				result.push_back(a);
				return result;
			}
			else {
				dict.insert(pair<int, int>(target - nums[a], a));
			}
		}
	}
};

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	int target = 6;
	Solution Solution1;
	vector<int> ans=Solution1.twoSum(v, target);
	for (int i = 0; i<ans.size(); i++) {
		cout << ans[i] << endl;
	}
	system("pause");
	return 0;
}
