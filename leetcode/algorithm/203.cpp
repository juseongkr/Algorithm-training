/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (!head)
			return nullptr;

		ListNode *cur = head;
		while (cur && cur->next) {
			if (cur->next->val == val)
				cur->next = cur->next->next;
			else
				cur = cur->next;
		}

		if (head->val == val)
			return head->next;

		return head;
	}
};
