#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Trie {
public:
	class Node {
	public:
		vector<int> next;
		int fail, valid;
		Node(int n) : fail(0), valid(-1) { next.resize(n); }
	};

	vector<Node> node;
	int nsz, len, digit;

	Trie(int n, int d) : len(n), digit(d), nsz(0)
	{
		node.resize(len, Node(digit));
	}

	void insert(const string &p, int tag)
	{
		int cur = 0;
		for (int i=0; i<p.length(); ++i) {
			int n = p[i]-'a';
			if (node[cur].next[n] == 0) {
				node[cur].next[n] = ++nsz;
				cur = nsz;
			} else {
				cur = node[cur].next[n];
			}
		}
		node[cur].valid = tag;
	}

	void failure()
	{
		int root = 0;
		queue<int> que;
		node[root].fail = root;
		que.push(root);

		while (!que.empty()) {
			int cur = que.front();
			que.pop();

			for (int i=0; i<digit; ++i) {
				int child = node[cur].next[i];
				if (!child)
					continue;
				if (cur == root) {
					node[child].fail = root;
				} else {
					int t = node[cur].fail;

					while (t != root && !node[t].next[i])
						t = node[t].fail;

					if (node[t].next[i])
						t = node[t].next[i];

					node[child].fail = t;
				}
				if (node[node[child].fail].valid != -1)
					node[child].valid = node[node[child].fail].valid;

				que.push(child);
			}
		}
	}

	int aho(const string &s)
	{
		int cnt = 0, cur = 0, root = 0;
		for (int i=0; i<s.length(); ++i) {
			int n = s[i]-'a';

			while (cur != root && !node[cur].next[n])
				cur = node[cur].fail;

			if (node[cur].next[n])
				cur = node[cur].next[n];

			if (node[cur].valid != -1)
				cnt++;
		}
		return cnt;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int n, q;

	cin >> n;
	Trie root(100001, 26);
	for (int i=0; i<n; ++i) {
		cin >> s;
		root.insert(s, i);
	}
	root.failure();

	cin >> q;
	for (int i=0; i<q; ++i) {
		cin >> s;
		if (root.aho(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
