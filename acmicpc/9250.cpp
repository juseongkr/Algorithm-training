#include <iostream>
#include <queue>
using namespace std;

class Trie {
public:
	Trie *next[26];
	Trie *fail;
	bool valid;

	Trie() : valid(false), fail(nullptr)
	{
		fill(next, next+26, nullptr);
	}

	~Trie()
	{
		for (int i=0; i<26; ++i)
			if (next[i])
				delete next[i];
	}

	void insert(const char *c)
	{
		if (*c == '\0') {
			valid = true;
			return;
		} else {
			int i = *c-'a';
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

			for (int i=0; i<26; ++i) {
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
			int nxt = s[i]-'a';

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

	string s;
	int n, m;

	cin >> n;
	Trie *root = new Trie();
	for (int i=0; i<n; ++i) {
		cin >> s;
		root->insert(s.c_str());
	}
	root->failure();

	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> s;
		if (root->aho(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	delete root;

	return 0;
}
