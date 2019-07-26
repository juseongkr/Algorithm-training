#include <iostream>
#include <cstring>
using namespace std;

class Trie {
public:
	Trie *next[26];
	int child, words;
	bool vaild;

	Trie() : child(0), words(0), vaild(false)
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
			vaild = true;
			child++;
		} else {
			int i = *c-'a';
			if (!next[i]) {
				child++;
				next[i] = new Trie();
			}
			words++;
			next[i]->insert(c+1);
		}
	}

	bool search(Trie *root, const char *c)
	{
		Trie *now = root;
		for (int i=0; i<strlen(c); ++i) {
			int k = c[i]-'a';
			if (!now->next[k])
				return false;
			now = now->next[k];
		}
		return true;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int n, m;

	Trie *t = new Trie();
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		t->insert(s.c_str());
	}

	int ans = 0;
	for (int i=0; i<m; ++i) {
		cin >> s;
		if (t->search(t, s.c_str()))
			ans++;
	}
	cout << ans << '\n';

	return 0;
}
