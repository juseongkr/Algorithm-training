#include <iostream>
using namespace std;

char solve(long long idx, string s)
{
	if (idx < s.length())
		return s[idx];

	long long len = s.length();
	while (len * 2 <= idx)
		len *= 2;

	if (len == idx)
		return solve(idx-1, s);
	return solve(idx-len-1, s);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	long long n;
	string s;

	cin >> s >> n;
	n--;
	cout << solve(n, s) << '\n';

	return 0;
}
