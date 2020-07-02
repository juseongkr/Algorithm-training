/*
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
	ListNode *merge(ListNode *left, ListNode *right) {
		if (!left)
			return right;
		if (!right)
			return left;


		if (left->val < right->val) {
			left->next = merge(left->next, right);
			return left;
		} else {
			right->next = merge(left, right->next);
			return right;
		}
	}

	ListNode *mergeSort(ListNode *head) {
		if (!head->next)
			return head;

		ListNode *temp = head;
		ListNode *prev = head;
		ListNode *cur = head;

		while (cur && cur->next) {
			prev = temp;
			temp = temp->next;
			cur = cur->next->next;
		}

		prev->next = nullptr;

		ListNode *left = mergeSort(head);
		ListNode *right = mergeSort(temp);

		return merge(left, right);
	}

	ListNode* sortList(ListNode* head) {
		if (!head)
			return head;

		return mergeSort(head);
	}
};
