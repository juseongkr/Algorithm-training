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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
			return nullptr;

		ListNode *left = headA;
		ListNode *right = headB;

		while (left->next)
			left = left->next;

		while (right->next)
			right = right->next;

		if (left != right)
			return nullptr;

		left = headA;
		right = headB;
		while (left != right) {
			left = left->next;
			right = right->next;
			if (!left)
				left = headB;
			if (!right)
				right = headA;
		}

		return left;
	}
};
