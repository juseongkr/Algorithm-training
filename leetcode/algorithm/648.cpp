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

	string successor(string prefix) {
		string ret;
		Node *cur = root;
		for (const auto c : prefix) {
			if (cur->valid)
				return ret;
			ret += c;
			if (cur->child.count(c))
				cur = cur->child[c];
			else
				return prefix;
		}
		return ret;
	}
};

class Solution {
public:
	string replaceWords(vector<string>& dict, string sentence) {
		Trie *root = new Trie();
		for (const auto i : dict)
			root->insert(i);

		string ans, p;
		sentence += " #";
		for (int i=0; i<sentence.length(); ++i) {
			if (sentence[i] == ' ') {
				ans += root->successor(p);
				ans += " ";
				p = "";
			} else {
				p += sentence[i];
			}
		}
		ans.pop_back();
		return ans;
	}
};
