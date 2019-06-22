#include <iostream>
using namespace std;

int main()
{
	long long ans = 0;
	string s;
	int n;

	cin >> n >> s;
	for (int i=0; i<s.length(); ++i) {
		if (i+1 == n) {
			cout << ans + s[i]-'a' + 1 << '\n';
			return 0;
		}
		long long k = 26;
		for (int j=i+2; j<n; ++j)
			k = (k * 26) + 26;

		ans += (s[i]-'a') * k + (s[i]-'a')+1;
	}
	cout << ans << '\n';

	return 0;
}
