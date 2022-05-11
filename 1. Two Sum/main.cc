#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	static const int MAX_RECORD = 10000;
	static const int MAX_TABLE = MAX_RECORD * 3 + 7;
    
	int tbl_[MAX_TABLE];

	void push(int Number, int Index) {
		int h = (Number + 1000000000) % MAX_TABLE;
		for (int i = 0; i < MAX_TABLE; i++) {
			int index = tbl_[h];
			if (index == -1 || index == MAX_RECORD) {
				tbl_[h] = Index;
				break;
			}
			h = (h + 1) % MAX_TABLE;
		}
	}

	int find(int Number, const vector<int>& nums) {
		int h = (Number + 1000000000) % MAX_TABLE;
		for (int i = 0; i < MAX_TABLE; i++) {
			int index = tbl_[h];
			if (index == -1) return -1;

			if (nums[index] == Number) {
				return index;
			}
			h = (h + 1) % MAX_TABLE;
		}
		return -1;
	}

public:
	Solution() {
		for (int i = 0; i < MAX_TABLE; i++) tbl_[i] = -1;
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			int temp = target - nums[i];
			int index = find(temp, nums);

			if (index != -1 && nums[index] == temp) {
                return { index, i };
			}
			push(nums[i], i);
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