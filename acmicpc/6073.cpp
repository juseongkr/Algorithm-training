#include <iostream>
using namespace std;

class Trie {
public:
	Trie *child[2];
	int valid, cnt;

	Trie() : cnt(0), valid(0) { child[0] = child[1] = nullptr; }
};

int m, n, k, p;
Trie *root = new Trie();

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i=0; i<m; ++i) {
		cin >> k;
		Trie *cur = root;
		for (int j=0; j<k; ++j) {
			cin >> p;
			if (!cur->child[p])
				cur->child[p] = new Trie();
			cur = cur->child[p];
			cur->cnt++;
		}
		cur->valid++;
	}

	for (int i=0; i<n; ++i) {
		cin >> k;
		int ans = 0;
		Trie *cur = root;
		for (int j=0; j<k; ++j) {
			cin >> p;
			if (cur) {
				ans += cur->valid;
				cur = cur->child[p];
			}
		}
		if (cur)
			ans += cur->cnt;
		cout << ans << '\n';
	}

	return 0;
}
