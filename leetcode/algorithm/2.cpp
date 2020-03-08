/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *list = new ListNode(0);
		ListNode *cur = list;
		ListNode *left = l1;
		ListNode *right = l2;

		int carry = 0;
		while (left || right) {
			int a = left ? left->val : 0;
			int b = right ? right->val : 0;
			int sum = a + b + carry;
			carry = sum / 10;

			cur->next = new ListNode(sum % 10);
			cur = cur->next;

			if (left)
				left = left->next;
			if (right)
				right = right->next;
		}
		if (carry)
			cur->next = new ListNode(carry);

		return list->next;
	}
};
