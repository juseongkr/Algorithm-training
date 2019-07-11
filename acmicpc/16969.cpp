#include <iostream>
using namespace std;
#define MOD 1000000009

int main()
{
	long long ans;
	string s;

	cin >> s;
	if (s[0] == 'c')
		ans = 26;
	else
		ans = 10;
	for (int i=1; i<s.length(); ++i) {
		if (s[i] == 'd') {
			if (s[i-1] == 'd')
				ans *= 9;
			else
				ans *= 10;
		}
		if (s[i] == 'c') {
		       if (s[i-1] == 'c')
			       ans *= 25;
		       else
			       ans *= 26;
		}
		ans %= MOD;
	}
	cout << ans << '\n';

	return 0;
}
