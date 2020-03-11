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
	Trie() : root(new Node()) { }

	void insert(string word) {
		Node *cur = root;
		for (const auto c : word) {
			if (!cur->child.count(c))
				cur->child[c] = new Node(c);
			cur = cur->child[c];
		}
		cur->valid = true;
	}

	bool search(string word, Node *cur=nullptr) {
		if (!cur)
			cur = root;
		for (int i=0; i<word.size(); ++i) {
			char c = word[i];
			if (c == '.') {
				for (const auto next : cur->child)
					if (search(word.substr(i+1), next.second))
						return true;
				return false;
			}

			if (cur->child.count(c))
				cur = cur->child[c];
			else
				return false;
		}
		return cur->valid;
	}
};

class WordDictionary {
public:
	Trie *trie = nullptr;

	/** Initialize your data structure here. */
	WordDictionary() {
		trie = new Trie();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		trie->insert(word);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return trie->search(word);
	}
};
