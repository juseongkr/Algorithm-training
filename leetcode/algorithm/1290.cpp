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
	int getDecimalValue(ListNode* head) {
		int len = 0, ans = 0;
		ListNode *node = head;
		while (node->next) {
			node = node->next;
			len++;
		}

		node = head;
		while (len--) {
			if (node->val)
				ans += (1 << (len+1));
			node = node->next;
		}
		if (node->val)
			ans += 1;

		return ans;   
	}
};
