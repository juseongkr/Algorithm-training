#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 100001

int num[MAX];
char c[33];

class Trie {
public:
	Trie *next[2];
	bool vaild;

	Trie() : vaild(false)
	{
		fill(next, next+2, nullptr);
	}

	~Trie()
	{
		for (int i=0; i<2; ++i)
			if (next[i])
				delete next[i];
	}

	void insert(const char *c)
	{
		if (*c == '\0') {
			vaild = true;
			return;
		} else {
			int i = *c-'0';
			if (!next[i]) {
				next[i] = new Trie();
			}
			next[i]->insert(c+1);
		}
	}

	void query(char *c)
	{
		if (*c == '\0')
			return;
		
		int i = *c-'0';
		i ^= 1;
		if (next[i]) {
			*c = '1';
			return next[i]->query(c+1);
		} else {
			*c = '0';
			return next[i^1]->query(c+1);
		}
	}
};

void binary(int n)
{
	for (int i=31; i>=0; i--) {
		if (n % 2 == 0)
			c[i] = '0';
		else
			c[i] = '1';
		n /= 2;
	}
	c[32] = '\0';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, ans = 0;

	cin >> n;
	Trie *t = new Trie();
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		binary(num[i]);
		t->insert(c);
	}

	for (int i=0; i<n; ++i) {
		binary(num[i]);
		t->query(c);

		int ret = 0;
		for (int j=31; j>=0; j--)
			ret += (c[j]-'0') * pow(2, 31-j);
		ans = max(ans, ret);
	}
	cout << ans << '\n';

	return 0;
}
