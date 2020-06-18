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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head)
			return nullptr;

		ListNode *front = head;
		ListNode *tail = head;
		while (n--)
			front = front->next;

		if (!front)
			return head->next;

		while (front->next) {
			front = front->next;
			tail = tail->next;
		}
		tail->next = tail->next->next;

		return head;
	}
};
