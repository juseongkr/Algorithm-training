class Node {
public:
	int key, value;
	Node *next, *prev;

	Node(int k, int v) : key(k), value(v) {
		next = prev = nullptr;
	}
};

class LRUCache {
public:
	unordered_map<int, Node*> cache;
	Node *front, *tail;
	int size, capacity;

	LRUCache(int capa) : size(0), capacity(capa) {
		front = tail = nullptr;
	}

	void moveToFront(Node *node) {
		if (front == node || !node)
			return;

		node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		else
			tail = node->prev;

		node->next = front;
		front->prev = node;
		front = node;
		node->prev = nullptr;
	}

	int get(int key) {
		if (cache.count(key)) {
			Node *node = cache[key];
			moveToFront(node);
			return node->value;
		} else {
			return -1;
		}
	}

	void put(int key, int value) {
		if (cache.count(key)) {
			Node *node = cache[key];
			node->value = value;
			moveToFront(node);
		} else {
			Node *node = new Node(key, value);

			if (size == capacity) {
				Node *del = tail;
				cache.erase(del->key);
				tail = del->prev;

				if (tail)
					tail->next = nullptr;

				if (front == del)
					front = nullptr;

				delete del;
				size--;
			}

			cache[key] = node;
			node->next = front;
			if (front)
				front->prev = node;
			else
				tail = node;

			front = node;
			size++;    
		}  
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
