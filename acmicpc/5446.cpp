#include <iostream>
using namespace std;

class Trie {
private:
	Trie *next[128];
	bool del, end;
	int cnt;

public:
	Trie() : del(false), end(false), cnt(0)
	{
		fill(next, next+128, nullptr);
	}

	~Trie()
	{
		for (int i=0; i<128; ++i)
			if (next[i])
				delete next[i];
	}

	void insert(const char *key, bool flag)
	{
		if (*key == '\0') {
			end = del = flag;
		} else {
			if (!next[*key]) {
				next[*key] = new Trie();
			}
			del = flag;
			next[*key]->insert(key+1, flag);
		}
	}

	int dfs(void)
	{
		if (del)
			return cnt+1;
		else if (end)
			cnt++;

		for (int i=0; i<128; ++i)
			if (next[i])
				cnt += next[i]->dfs();

		return cnt;
	}
};

int main()
{
	int t, n, m;
	string s;

	cin >> t;
	while (t--) {
		cin >> n;
		Trie *t = new Trie();
		for (int i=0; i<n; ++i) {
			cin >> s;
			t->insert(s.c_str(), true);
		}

		cin >> m;
		for (int i=0; i<m; ++i) {
			cin >> s;
			t->insert(s.c_str(), false);
		}

		cout << t->dfs() << '\n';

		delete t;
	}

	return 0;
}
