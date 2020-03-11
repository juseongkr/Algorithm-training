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
	bool hasCycle(ListNode *head) {
		if (!head || !head->next)
			return false;

		ListNode *one = head;
		ListNode *two = head->next;

		while (one != two) {
			if (!two || !two->next)
				return false;
			one = one->next;
			two = two->next->next;
		}

		return true;
	}
};
