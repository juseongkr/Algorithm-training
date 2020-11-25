#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Trie {
private:
	class Node {
	public:
		int cnt;
		char val;
		bool valid;
		unordered_map<char, Node*> child;
		Node() : val('*'), valid(false), cnt(0) { }
		Node(char c) : val(c), valid(false), cnt(0) { }
	};
	Node *root = nullptr;

public:
	Trie() : root(new Node()) { }

	void insert(const string word) {
		Node *cur = root;
		for (const auto c : word) {
			if (!cur->child.count(c))
				cur->child[c] = new Node(c);
			cur->child[c]->cnt++;
			cur = cur->child[c];
		}
		cur->valid = true;
	}

	bool search(const string word) {
		Node *cur = root;
		for (const auto c : word) {
			if (cur->child.count(c))
				cur = cur->child[c];
			else
				return false;
		}
		return cur->valid;
	}

	int startsWith(const string prefix) {
		Node *cur = root;
		for (const auto c : prefix) {
			if (cur->child.count(c))
				cur = cur->child[c];
			else
				return 0;
		}
		return cur->cnt;
	}
};

int n;
string s;
unordered_map<string, int> dict;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	Trie trie;
	for (int i=0; i<n; ++i) {
		cin >> s;

		if (trie.search(s)) {
			cout << s + to_string(++dict[s]+1) << '\n';
			continue;
		}

		bool flag = false;
		for (int j=s.length()-1; j>=0; j--) {
			string p = s.substr(0, j);
			if (trie.startsWith(p)) {
				trie.insert(s);
				cout << p + s[j] << '\n';
				flag = true;
				break;
			}
		}

		if (!flag) {
			trie.insert(s);
			cout << s[0] << '\n';
		}
	}

	return 0;
}
