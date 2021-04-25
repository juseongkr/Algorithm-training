#include <iostream>
#include <cmath>
using namespace std;

bool flag;
string s;

void dfs(string s)
{
	if (flag)
		return;

	long long ret = 0;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '0' || s[i] == '1') {
			ret = ret * 2 + s[i]-'0';
		} else {
			s[i] = '0';
			dfs(s);
			s[i] = '1';
			dfs(s);
			return;
		}
	}

	long long k = floor(sqrt(ret)+0.5f);
	if (k*k == ret) {
		cout << s << '\n';
		flag = true;
		return;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t;

	cin >> t;
	for (int i=1; i<=t; ++i) {
		cin >> s;
		flag = false;
		cout << "Case #" << i << ": ";
		dfs(s);
	}

	return 0;
}
