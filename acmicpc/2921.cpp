#include <iostream>
using namespace std;

int main()
{
	int n, ans = 0;

	cin >> n;
	for (int i=0; i<=n; ++i)
		for (int j=i; j<=n; ++j)
			ans += i + j;

	cout << ans << '\n';

	return 0;
}
