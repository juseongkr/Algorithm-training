#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string n;
	int b, len;
	ll ans = 0;

	cin >> n >> b;
	len = n.length();
	for (int i=0; i<len; ++i) {
		if ('A' <= n[i] && n[i] <= 'Z')
			ans += (n[i]-55) * pow(b, len-i-1);
		else
			ans += (n[i]-'0') * pow(b, len-i-1);
	}

	cout << ans << '\n';

	return 0;
}
