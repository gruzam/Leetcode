#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;

                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
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