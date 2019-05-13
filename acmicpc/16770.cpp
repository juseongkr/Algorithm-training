#include <iostream>
using namespace std;

int dict[1001];
int n, a, b, c, sum, ans, max_val = 1e3;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> c;
		max_val = max(max_val, max(a, b));
		dict[a] += c;
		dict[b] -= c;
	}

	for (int i=0; i<=max_val; ++i) {
		sum += dict[i];
		ans = max(sum, ans);
	}

	cout << ans << '\n';

	return 0;
}
