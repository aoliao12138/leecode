#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
		ListNode Zero(0);
		int sum = l1->val + l2->val + carry;
		ListNode ans(sum % 10);
		carry = sum / 10;
		if ((l1->next == NULL) && (l2->next == NULL)) {
		}
		else if (l1->next == NULL) {
			l1->next = &Zero;
			ans.next = addTwoNumbers(l1->next, l2->next, carry);
		}
		else if (l2->next == NULL) {
			l2->next = &Zero;
			ans.next = addTwoNumbers(l1->next, l2->next, carry);
		}
		else {
			ans.next = addTwoNumbers(l1->next, l2->next, carry);
		}
		return &ans;
	}
};

int main()
{
	ListNode L1(3);
	ListNode L2(4);
	L2.next = &L1;
	ListNode L3(2);
	L3.next = &L2;
	ListNode L4(4);
	ListNode L5(6);
	L5.next = &L4;
	ListNode L6(5);
	L6.next = &L5;
	Solution Solution1;
	ListNode* result = Solution1.addTwoNumbers(&L3, &L6);
	cout << result->val << endl;
	/*cout << result->val << endl;
	cout << (*result).next->val << endl;
	cout << (*(*result).next).next->val << endl;*/
	/*while (result->next != NULL) {
	cout << result->val << endl;
	result = result->next;
	}*/
	return 0;
}