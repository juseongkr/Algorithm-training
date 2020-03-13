class Trie {
private:
	class Node {
	public:
		char val;
		int value;
		bool valid;
		unordered_map<char, Node*> child;
		Node() : val('*'), valid(false), value(0) { }
		Node(char c) : val(c), valid(false), value(0) { }
	};

	Node *root = nullptr;

public:
	Trie() : root(new Node()) { }

	void insert(string word, int value) {
		Node *cur = root;
		for (const auto c : word) {
			if (!cur->child.count(c))
				cur->child[c] = new Node(c);
			cur = cur->child[c];
		}
		cur->value = value;
		cur->valid = true;
	}

	int search(string word) {
		Node *cur = root;
		for (const auto c : word) {
			if (cur->child.count(c))
				cur = cur->child[c];
			else
				return 0;
		}
		if (cur->valid);
			return dfs(cur);
		return 0;
	}

	int dfs(Node *cur) {
		if (!cur)
			return 0;

		int sum = cur->value;
		for (const auto i : cur->child)
			sum += dfs(i.second);
		return sum;
	}
};

class MapSum {
public:
	Trie *root = nullptr;
	/** Initialize your data structure here. */
	MapSum() {
		root = new Trie();
	}

	void insert(string key, int val) {
		root->insert(key, val);
	}

	int sum(string prefix) {
		return root->search(prefix);
	}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
