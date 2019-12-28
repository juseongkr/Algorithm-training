#include <iostream>
using namespace std;

int n, k, sum;
int mi[7], mx[7];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		sum = (sum+k)%7;
		mx[sum] = i+1;
		if (sum && !mi[sum])
			mi[sum] = i+1;
	}

	int ans = 0;
	for (int i=0; i<7; ++i)
		ans = max(ans, mx[i] - mi[i]);

	cout << ans << '\n';

	return 0;
}
