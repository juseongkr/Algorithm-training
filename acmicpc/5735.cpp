#include <iostream>
#include <queue>
using namespace std;

class Trie {
public:
	Trie *next[97];
	Trie *fail;
	bool valid;
	int cnt;

	Trie() : valid(false), fail(nullptr), cnt(0)
	{
		fill(next, next+97, nullptr);
	}

	~Trie()
	{
		for (int i=0; i<97; ++i)
			if (next[i])
				delete next[i];
	}

	void insert(const char *c)
	{
		if (*c == '\0') {
			valid = true;
			return;
		} else {
			int i = *c-32;
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

			for (int i=0; i<97; ++i) {
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

	void aho(const string &s)
	{
		Trie *cur = this;
		for (int i=0; i<s.length(); ++i) {
			int nxt = s[i]-32;

			while (cur != this && !cur->next[nxt])
				cur = cur->fail;

			if (cur->next[nxt])
				cur = cur->next[nxt];

			if (cur->valid) {
				cnt++;
				cur = this;
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

		Trie *root = new Trie();
		for (int i=0; i<n; ++i) {
			string s;
			cin >> s;
			root->insert(s.c_str());
		}
		root->failure();

		getline(cin, flush);
		for (int i=0; i<m; ++i) {
			string s;
			getline(cin, s);
			root->aho(s);
		}
		cout << root->cnt << '\n';
		delete root;
	}

	return 0;
}
