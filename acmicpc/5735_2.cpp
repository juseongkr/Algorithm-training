#include <iostream>
#include <vector>
#include <queue>
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
	int cnt;

	Trie(int n, int d) : len(n), digit(d), nsz(0), cnt(0)
	{
		node.resize(len, Node(digit));
	}

	void insert(const string &p, int tag)
	{
		int cur = 0;
		for (int i=0; i<p.length(); ++i) {
			int n = p[i]-32;
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

	void aho(const string &s)
	{
		int cur = 0, root = 0;
		for (int i=0; i<s.length(); ++i) {
			int n = s[i]-32;

			while (cur != root && !node[cur].next[n])
				cur = node[cur].fail;

			if (node[cur].next[n])
				cur = node[cur].next[n];

			if (node[cur].valid != -1) {
				cnt++;
				cur = root;
			}
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string flush;
	int n, m;

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		Trie root(n * 16, 97);
		for (int i=0; i<n; ++i) {
			string s;
			cin >> s;
			root.insert(s, i);
		}
		root.failure();

		getline(cin, flush);
		for (int i=0; i<m; ++i) {
			string s;
			getline(cin, s);
			root.aho(s);
		}
		cout << root.cnt << '\n';
	}

	return 0;
}
