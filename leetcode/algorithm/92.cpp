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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* cur = head;
		ListNode* rev = nullptr;
		int len = n-m+1;

		for (int i=1; i<m; ++i) {
			rev = cur;
			cur = cur->next;
		}

		ListNode* temp = nullptr;
		ListNode* left = rev;
		ListNode* right = cur;

		while (len--) {
			temp = cur->next;
			cur->next = rev;
			rev = cur;
			cur = temp;
		}

		if (left)
			left->next = rev;
		else
			head = rev;
		right->next = cur;

		return head;
	}
};
