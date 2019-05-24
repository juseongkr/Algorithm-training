#include <iostream>
using namespace std;
#define MOD 1234567891

int main()
{
	string s;
	int n;
	long long r = 1, ans = 0;

	cin >> n >> s;
	for (int i=0; i<n; ++i) {
		ans += (s[i]-'a'+1) * r;
		r *= 31;
		ans %= MOD;
		r %= MOD;
	}

	cout << ans << '\n';

	return 0;
}
