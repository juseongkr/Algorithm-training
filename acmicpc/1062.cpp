#include <iostream>
#include <vector>
using namespace std;
#define MAX 51

int n, k;
int word[MAX];

int count(int m)
{
	int ret = 0;
	for (int i=0; i<n; ++i)
		if ((word[i] & ((1 << 26) - 1 - m)) == 0)
			ret++;
	return ret;
}

int solve(int cur, int m, int k)
{
	if (k < 0)
		return 0;
	if (cur == 26)
		return count(m);

	int ans = 0;
	int ret = solve(cur+1, m | (1 << cur), k-1);
	ans = max(ans, ret);
	if (cur != 'a'-'a' && cur != 'n'-'a' && cur != 't'-'a' && cur != 'i'-'a' && cur != 'c'-'a') {
		ret = solve(cur+1, m, k);
		ans = max(ans, ret);
	}

	return ans;
}

int main()
{
	string s;

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<s.length(); ++j)
			word[i] |= (1 << (s[j]-'a'));
	}

	cout << solve(0, 0, k) << '\n';

	return 0;
}
