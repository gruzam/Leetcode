#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> hash;

		int temp;
		for (int i = 0; i < nums.size(); i++) {
			temp = target - nums[i];
			auto iter = hash.find(temp);

			if (iter != hash.end())
				return { i, iter->second };

			hash.insert({ nums[i], i });
		}
		return { 0, 0 };
	}
};

int main()
{
	Solution* solve = new Solution;

	vector<int> nums;
	vector<int> result;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	result = solve->twoSum(nums, 9);
	cout << "[ ";
	for (auto iter : result) {
		cout << iter << " ";
	}
	cout << "]" << endl;

	delete solve;
	return 0;
}