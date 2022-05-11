#include <iostream>
#include <memory>

using namespace std;

class Solution {
    int table_[256];
    int len_;
    int begin_, end_;
    int max_;

public:
    Solution() {
        for (int i = 0; i < 256; i++) {
            table_[i] = -1;
        }
        len_ = begin_ = end_ = max_ = 0;
    }

    int lengthOfLongestSubstring(string s) {
        int i;
        for (i = 0; i < s.length(); i++) {
            int temp = s[i] - ' ';

            if (table_[temp] == -1) {
                table_[temp] = i;
            }
            else { // find repeating charater
                len_ = i - begin_;
                if (max_ < len_) max_ = len_;

                if (begin_ < (table_[temp] + 1)) 
                    begin_ =  table_[temp] + 1;

                table_[temp] = i;
            }
        }

        len_ = i - begin_;
        if (max_ < len_) max_ = len_;

        return max_;
    }
};

int main()
{
	unique_ptr<Solution> solve = make_unique<Solution>();
	string s = "abcabcbb";

	int result = solve->lengthOfLongestSubstring(s);
	cout << result << endl;

	return 0;
}