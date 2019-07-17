#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;
	int ans = 1, cnt = 4;
	for (int i=1; i<n; ++i) {
		ans += cnt;
		cnt += 4;
	}

	cout << ans << '\n';

	return 0;
}
