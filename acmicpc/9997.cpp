#include <iostream>
using namespace std;
#define MAX 26

string s;
int n, ans;
int str[MAX];

void dfs(int idx, int bit)
{
	if (idx == n) {
		if (bit == (1 << MAX)-1)
			ans++;
		return;
	}

	dfs(idx+1, bit | str[idx+1]);
	dfs(idx+1, bit);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> s;
		for (int j=0; j<s.length(); ++j)
			str[i] |= (1 << (s[j]-'a'));
	}

	dfs(0, 0);

	cout << ans << '\n';

	return 0;
}
