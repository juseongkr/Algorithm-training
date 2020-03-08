class MyLinkedList {
public:
	class Node {
	public:
		int val;
		Node *next;
		Node(int v) : val(v), next(nullptr) { }
	};
	Node *head;
	int len;

	/** Initialize your data structure here. */
	MyLinkedList() : len(0), head(nullptr) { }
	
	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index >= this->len)
			return -1;

		Node *cur = this->head;
		while (index--)
			cur = cur->next;
		return cur->val;
	}
	
	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node *newNode = new Node(val);
		newNode->next = this->head;
		this->head = newNode;
		this->len++;
	}
	
	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		Node *cur = this->head;
		while(cur->next)
			cur = cur->next;
		Node *newNode = new Node(val);
		cur->next = newNode;
		this->len++;
	}
	
	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index > this->len)
			return;

		if (index == 0) {
			addAtHead(val);
		} else {
			Node *cur = this->head;
			while (--index)
				cur = cur->next;

			Node *newNode = new Node(val);

			newNode->next = cur->next;
			cur->next = newNode;
			this->len++;
		}
		
	}
	
	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index >= this->len)
			return;

		if (index == 0) {
			Node *temp = this->head;
			head = head->next;

			this->len--;
			delete temp;

		} else {
			Node *cur = this->head;

			while (--index)
				cur = cur->next;

			Node *temp = cur->next;
			cur->next = cur->next->next;

			this->len--;
			delete temp;
		}
	}
};
