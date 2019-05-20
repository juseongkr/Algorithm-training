#include <iostream>
#include <iomanip>
using namespace std;

class Trie {
private:
	Trie *next[26];
	int child;
	int words;
	bool end;

public:
	Trie() : child(0), words(0), end(false)
	{
		fill(next, next+26, nullptr);
	}

	~Trie()
	{
		for (int i=0; i<26; ++i)
			if (next[i])
				delete next[i];
	}

	void insert(const char *key)
	{
		if (*key == '\0') {
			end = true;
			child++;
		} else {
			if (!next[*key-'a']) {
				child++;
				next[*key-'a'] = new Trie();
			}
			words++;
			next[*key-'a']->insert(key+1);
		}
	}

	long long count(bool root=false)
	{
		long long ret = 0;
		if (root || child > 1)
			ret = words;

		for (int i=0; i<26; ++i)
			if (next[i])
				ret += (next[i]->count());
		return ret;
	}
};

int main()
{
	string s;
	int n;

	while (cin >> n) {
		Trie *t = new Trie();
		for (int i=0; i<n; ++i) {
			cin >> s;
			t->insert(s.c_str());
		}
		cout << fixed << setprecision(2) << (double)t->count(true)/n << '\n';
		delete t;
	}

	return 0;
}
