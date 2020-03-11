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
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next)
			return nullptr;

		ListNode *one = head;
		ListNode *two = head;
		while (two) {
			one = one->next;
			two = two->next;
			if (two)
				two = two->next;
			if (one == two)
				break;
		}

		if (!one || !two)
			return  nullptr;

		two = head;
		while (one != two) {
			one = one->next;
			two = two->next;
		}

		return one;
	}
};
