#include <iostream>
using namespace std;

int main()
{
	int n, k, m;

	cin >> n >> k >> m;
	m--;

	int prev = 0, ans = 1;
	while (1) {
		int next = (prev+k-1) % n;
		if (next == m)
			break;
		if (next < m)
			m--;
		prev = next;
		n--;
		ans++;
	}
	cout << ans << '\n';

	return 0;
}
