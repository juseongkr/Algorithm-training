#include <iostream>
using namespace std;
#define MAX 5001

int fail[MAX];

int solve(string s)
{
	int ret = 0;
	for (int i=1, j=0; i<s.length(); ++i) {
		while (j && s[i] != s[j])
			j = fail[j-1];
		if (s[i] == s[j])
			ret = max(ret, fail[i] = ++j);
	}
	return ret;
}

int main()
{
	int n, ans = 0;
	string s;

	cin >> s;
	n = s.length();
	for (int i=0; i<n; ++i) {
		fill(fail, fail+MAX, 0);
		string next = s.substr(i, n);
		ans = max(ans, solve(next));
	}

	cout << ans << '\n';

	return 0;
}
