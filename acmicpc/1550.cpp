#include <iostream>
using namespace std;

const int num[6] = {10, 11, 12, 13, 14, 15};

int main()
{
	string s;
	int ans = 0, k = 1;

	cin >> s;
	for (int i=s.length()-1; i>=0; i--) {
		if ('0' <= s[i] && s[i] <= '9')
			ans += (s[i]-'0') * k;
		else
			ans += num[s[i]-'A'] * k;
		k *= 16;
	}
	cout << ans << '\n';

	return 0;
}
