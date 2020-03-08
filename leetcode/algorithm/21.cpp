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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *list = new ListNode(0);
		ListNode *cur = list;
		ListNode *left = l1;
		ListNode *right = l2;

		while (left && right) {
			if (left->val < right->val) {
				cur->next = new ListNode(left->val);
				cur = cur->next;
				left = left->next;
			} else {
				cur->next = new ListNode(right->val);
				cur = cur->next;
				right = right->next;
			}
		}
		if (left)
			cur->next = left;

		if (right)
			cur->next = right;

		return list->next;
	}
};
