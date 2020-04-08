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
	ListNode* middleNode(ListNode* head) {
		int len = 1;
		ListNode *cur = head;
		while (cur->next) {
			cur = cur->next;
			len++;
		}

		cur = head;
		for (int i=0; i<len/2; ++i)
			cur = cur->next;

		return cur;
	}
};
