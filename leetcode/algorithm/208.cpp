class Trie {
private:
	class Node {
	public:
		char val;
		bool valid;
		unordered_map<char, Node*> child;
		Node() : val('*'), valid(false) { }
		Node(char c) : val(c), valid(false) { }
	};

	Node *root = nullptr;

public:
	/** Initialize your data structure here. */
	Trie() : root(new Node()) { }

	/** Inserts a word into the trie. */
	void insert(string word) {
		Node *cur = root;
		for (const auto c : word) {
			if (!cur->child.count(c))
				cur->child[c] = new Node(c);
			cur = cur->child[c];
		}
		cur->valid = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node *cur = root;
		for (const auto c : word) {
			if (cur->child.count(c))
				cur = cur->child[c];
			else
				return false;
		}
		return cur->valid;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node *cur = root;
		for (const auto c : prefix) {
			if (cur->child.count(c))
				cur = cur->child[c];
			else
				return false;
		}
		return true;
	}
};
