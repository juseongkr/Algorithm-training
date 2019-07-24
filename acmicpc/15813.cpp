#include <iostream>
using namespace std;

int main()
{
	int n, ans = 0;
	string s;

	cin >> n >> s;
	for (int i=0; i<n; ++i)
		ans += s[i]-'A'+1;
	cout << ans << '\n';

	return 0;
}
