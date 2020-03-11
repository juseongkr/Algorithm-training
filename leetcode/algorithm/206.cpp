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
	ListNode* reverseList(ListNode* head) {
		ListNode *cur = head;
		ListNode *rev = nullptr;
		ListNode *temp = nullptr;

		while (cur) {
			temp = cur->next;
			cur->next = rev;
			rev = cur;
			cur = temp;
		}

		return rev;
	}
};
