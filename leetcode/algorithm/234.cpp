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
	bool isPalindrome(ListNode* head) {
		if (!head)
			return true;

		ListNode *one = head;
		ListNode *two = head->next;

		while (two && two->next) {
			one = one->next;
			two = two->next->next;
		}

		ListNode *rev = nullptr;
		ListNode *temp = nullptr;
		ListNode *cur = one->next;

		while (cur) {
			temp = cur->next;
			cur->next = rev;
			rev = cur;
			cur = temp;
		}

		while (rev) {
			if (rev->val != head->val)
				return false;
			rev = rev->next;
			head = head->next;
		}
		return true;
	}
};
