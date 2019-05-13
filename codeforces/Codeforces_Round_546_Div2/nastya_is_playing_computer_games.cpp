#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, cnt;

	cin >> n >> k;

	cnt = 3 * n + min(k-1, n-k);

	cout << cnt << '\n';

	return 0;
}
