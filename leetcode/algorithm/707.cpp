class MyLinkedList {
public:
	class Node {
	public:
		int val;
		Node *next;
		Node *prev;
		Node(int v) : val(v) { next = nullptr; prev = nullptr; }
	};
	Node *head;
	Node *tail;
	int len;

	/** Initialize your data structure here. */
	MyLinkedList() : len(0) {
		this->head = nullptr;
		this->tail = nullptr;
	}
	
	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= this->len || this->head == nullptr)
			return -1;
		
		if (index == this->len-1)
			return tail->val;
		
		Node *cur = this->head;
		for (int i=0; i<index; ++i)
			cur = cur->next;
		return cur->val;
	}
	
	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node *newNode = new Node(val);
		if (this->head) {
			newNode->next = this->head;
			this->head->prev = newNode;
			this->head = newNode;
		} else {
			this->head = newNode;
			this->tail = newNode;
		}
		this->len++;
	}
	
	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (this->head) {
			Node *newNode = new Node(val);
			this->tail->next = newNode;
			newNode->prev = this->tail;
			this->tail = newNode;
			this->len++;
		} else {
			addAtHead(val);
		}
	}
	
	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index == 0) {
			addAtHead(val);
		} else if (index == this->len) {
			addAtTail(val);
		} else {
			Node *newNode = new Node(val);
			Node *cur = this->head;

			for (int i=0; i<index; ++i)
				cur = cur->next;

			if (cur->prev)
				cur->prev->next = newNode;
			else
				this->head = newNode;

			newNode->prev = cur->prev;
			newNode->next = cur;
			cur->prev = newNode;
			this->len++;
		}
	}
	
	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0 || index >= this->len || this->head == nullptr)
			return;

		if (index == 0) {
			Node *temp = this->head;
			head = head->next;

			if (head)
				head->prev = nullptr;
			
			this->len--;

			delete temp;

		} else if (index == this->len-1) {
			Node *temp = this->tail;
			tail = tail->prev;

			if (tail)
				tail->next = nullptr;

			this->len--;

			delete temp;

		} else {
			Node *cur = this->head;
			for (int i=0; i<index; ++i)
				cur = cur->next;
			Node *temp = cur;

			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;

			this->len--;

			delete temp;
		}
	}
};
