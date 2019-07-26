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
	Trie *next[4];
	Trie *fail;
	bool valid;

	Trie() : valid(false), fail(nullptr)
	{
		fill(next, next+4, nullptr);
	}

	~Trie()
	{
		for (int i=0; i<4; ++i)
			if (next[i])
				delete next[i];
	}

	void insert(const char *c)
	{
		if (*c == '\0') {
			valid = true;
			return;
		} else {
			int i = to_index(*c);
			if (!next[i])
				next[i] = new Trie();
			next[i]->insert(c+1);
		}
	}

	void failure()
	{
		queue<Trie*> que;
		this->fail = this;
		que.push(this);

		while (!que.empty()) {
			Trie *cur = que.front();
			que.pop();

			for (int i=0; i<4; ++i) {
				Trie *next = cur->next[i];
				if (!next)
					continue;

				if (cur == this) {
					next->fail = this;
				} else {
					Trie *dest = cur->fail;

					while (dest != this && !dest->next[i])
						dest = dest->fail;

					if (dest->next[i])
						dest = dest->next[i];

					next->fail = dest;
				}

				if (next->fail->valid)
					next->valid = true;

				que.push(next);
			}
		}
	}

	int aho(const string &s)
	{
		Trie *cur = this;
		int cnt = 0;
		for (int i=0; i<s.length(); ++i) {
			int nxt = to_index(s[i]);

			while (cur != this && !cur->next[nxt])
				cur = cur->fail;

			if (cur->next[nxt])
				cur = cur->next[nxt];

			if (cur->valid)
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
		cin >> n >> m;
		cin >> s >> k;
		for (int i=0; i<m; ++i) {
			for (int j=i+1; j<=m; ++j) {
				reverse(k.begin()+i, k.begin()+j);
				p.insert(k);
				reverse(k.begin()+i, k.begin()+j);
			}
		}

		Trie *root = new Trie();
		for (auto &it : p)
			root->insert(it.c_str());

		root->failure();
		cout << root->aho(s) << '\n';

		delete root;
		p.clear();
	}

	return 0;
}
