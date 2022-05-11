#include <iostream>

using namespace std;

 struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* sum_ptr = head;
        int carry = 0;

        
        while (l1 != 0 || l2 != 0) {
            sum_ptr->next = new ListNode(0);
            sum_ptr = sum_ptr->next;

            sum_ptr->val = ((l1 == nullptr)? 0 : l1->val) +
                ((l2 == nullptr)? 0 : l2->val) + 
                carry;
            
            carry = sum_ptr->val / 10;
            sum_ptr->val %= 10;
            
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        if (carry != 0) {
            sum_ptr->next = new ListNode(carry);
        }
        
        return head->next;
    }
};

int main()
{
	Solution* solve = new Solution;
	ListNode* result;
	ListNode *l1, *l2, *temp;

	// Set l1 data
	l1 = new ListNode(3);
	l1 = new ListNode(4, l1);
	l1 = new ListNode(2, l1);

	// Set l2 data
	l2 = new ListNode(4);
	l2 = new ListNode(6, l2);
	l2 = new ListNode(5, l2);

	result = solve->addTwoNumbers(l1, l2);
	cout << "[ ";
	while (result != 0) {
		cout << result->val << " ";
		result = result->next;
	}

	cout << "]" << endl;

	while (l1 != 0) {
		temp = l1;
		l1 = l1->next;
		delete temp;
	}
	while (l2 != 0) {
		temp = l2;
		l2 = l2->next;
		delete temp;
	}

	delete solve;
	return 0;
}