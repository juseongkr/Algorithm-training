#include <iostream>
using namespace std;
#define MAX 100001

int n, k, b, x;
int num[MAX];

int main()
{
	cin >> n >> k >> b;
	for (int i=0; i<b; ++i) {
		cin >> x;
		num[x] = 1;
	}

	for (int i=1; i<=n; ++i)
		num[i] += num[i-1];

	int ans = 1e9+7;
	for (int i=1; i<=n-k; ++i)
		ans = min(ans, num[i+k] - num[i]);

	cout << ans << '\n';

	return 0;
}
