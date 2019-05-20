#include <iostream>
using namespace std;

#define MAX 10

class Trie {
private:
	Trie *next[MAX];
	bool end;
	bool child;

public:
	Trie() : end(false), child(false)
	{
		fill(next, next+MAX, nullptr);
	}

	~Trie()
	{
		for (int i=0; i<MAX; ++i)
			if (next[i])
				delete next[i];
	}

	void insert(const char *key)
	{
		if (*key == '\0') {
			end = true;
		} else {
			int num = *key-'0';
			if (next[num] == nullptr)
				next[num] = new Trie();
			child = true;
			next[num]->insert(key+1);
		}
	}

	bool check()
	{
		if (child && end)
			return false;

		for (int i=0; i<MAX; ++i)
			if (next[i] && !next[i]->check())
				return false;

		return true;
	}
};

int main()
{
	string s;
	int t, n;

	cin >> t;
	while (t--) {
		Trie *root = new Trie();
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> s;
			root->insert(s.c_str());
		}

		if (root->check())
			cout << "YES\n";
		else
			cout << "NO\n";

		delete root;
	}

	return 0;
}
