#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class AhoCorasick {
public:
	struct Node {
		map<int, int> children;
		int pi, len;
		Node()
		{
			pi = -1;
			len = 0;
		}
	};

	vector<Node> trie;
	int root;

	int init()
	{
		Node t;
		trie.push_back(t);
		return (int)trie.size()-1;
	}

	AhoCorasick()
	{
		root = init();
	}

	void insert(int node, const string &s, int index, int string_index)
	{
		if (index == s.size()) {
			trie[node].len = index;
			return;
		}

		int c = s[index] - 'a';
		if (trie[node].children.count(c) == 0) {
			int next = init();
			trie[node].children[c] = next;
		}

		insert(trie[node].children[c], s, index+1, string_index);
	}

	void insert(const string &s, int index)
	{
		insert(root, s, 0, index);
	}

	void failure()
	{
		queue<int> q;
		q.push(root);
		trie[root].pi = root;
		
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i=0; i<26; ++i) {
				if (trie[cur].children.count(i) == 0)
					continue;

				int next = trie[cur].children[i];
				if (cur == root) {
					trie[next].pi = root;
				} else {
					int x = trie[cur].pi;
					while (x != root && trie[x].children.count(i) == 0)
						x = trie[x].pi;

					if (trie[x].children.count(i) > 0)
						x = trie[x].children[i];

					trie[next].pi = x;
				}

				int pi = trie[next].pi;
				trie[next].len = max(trie[next].len, trie[pi].len);
				q.push(next);
			}
		}
	}

	int next(int node, char ch)
	{
		int c = ch - 'a';
		while (node != root && trie[node].children.count(c) == 0)
			node = trie[node].pi;

		if (trie[node].children.count(c) > 0)
		node = trie[node].children[c];

		return node;
	}

	int aho(const string &s)
	{
		int node = root;
		vector<pair<int, int>> matches;

		for (int i=0; i<s.size(); ++i) {
			node = next(node, s[i]);
			if (trie[node].len > 0) {
				matches.push_back({i-trie[node].len+1, -1});
				matches.push_back({i, 1});
			}
		}

		sort(matches.begin(), matches.end());

		int ans = 0, start = 0, open = 0;
		for (auto &p : matches) {
			if (p.second == -1) {
				if (open++ == 0)
					start = p.first;
			} else {
				if (--open == 0)
					ans += p.first - start + 1;
			}
		}
		return ans;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m;
	string s;

	cin >> n;
	AhoCorasick c = AhoCorasick();
	for (int i=0; i<n; ++i) {
		cin >> s;
		c.insert(s, i);
	}
	c.failure();

	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> s;
		if (c.aho(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
