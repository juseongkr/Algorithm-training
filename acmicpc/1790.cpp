#include <iostream>
using namespace std;

int main()
{
	int n, k, i, len = 0;
	cin >> n >> k;

	for (i=1; i<=n; ++i) {
		int t = i;
		int cnt = 0;
		while (t) {
			cnt++;
			t /= 10;
		}
		len += cnt;
		if (len >= k)
			break;
	}

	while (len > k) {
		i /= 10;
		len--;
	}

	if (len == k)
		cout << i % 10 << '\n';
	else
		cout << "-1\n";

	return 0;
}
