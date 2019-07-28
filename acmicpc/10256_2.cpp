#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int to_index(char c)
{
	if (c == 'A')
		return 0;
	else if (c == 'C')
		return 1;
	else if (c == 'G')
		return 2;
	return 3;
}

class Trie {
public:
	class Node {
	public:
		int fail, valid;
		vector<int> next;
		Node(int n) : fail(0), valid(-1)
		{
			next.resize(n);
		}
	};

	vector<Node> node;
	int nsz, MX, digit;

	Trie(int n, int d) : MX(n), digit(d), nsz(0)
	{
		node.resize(MX, Node(digit));
	}

	void insert(const string &p, int tag)
	{
		int cur = 0;
		for (int i=0; i<p.length(); ++i) {
			int n = to_index(p[i]);
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
		failure();
		int cnt = 0, cur = 0, root = 0;
		for (int i=0; i<s.length(); ++i) {
			int n = to_index(s[i]);

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

	set<string> p;
	string s, k;
	int t, n, m;
	
	cin >> t;
	while (t--) {
		cin >> n >> m >> s >> k;
		for (int i=0; i<m; ++i) {
			for (int j=i+1; j<=m; ++j) {
				reverse(k.begin()+i, k.begin()+j);
				p.insert(k);
				reverse(k.begin()+i, k.begin()+j);
			}
		}

		Trie root(p.size() * m + 100, 4);
		for (auto it : p)
			root.insert(it, 0);

		cout << root.aho(s) << '\n';

		p.clear();
	}

	return 0;
}
