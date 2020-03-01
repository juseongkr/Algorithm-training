#include <iostream>
using namespace std;

int main()
{
	int n, v;

	cin >> n >> v;
	int idx = 2;
	int ans = min(n-1, v);
	for (int i=v; i<n-1; ++i)
		ans += idx++;

	cout << ans << '\n';

	return 0;
}
