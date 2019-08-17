#include <iostream>
using namespace std;

int main()
{
	int n, k, ans = 0;

	cin >> n >> k;
	for (int i=1; i<=n; ++i)
		ans = (ans + k) % i;

	cout << ans+1 << '\n';

	return 0;
}
