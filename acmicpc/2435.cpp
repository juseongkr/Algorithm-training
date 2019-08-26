#include <iostream>
using namespace std;
#define MAX 101

int num[MAX];

int main()
{
	int n, k;

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int sum = 0, ans = -1e9+7;
	for (int i=0; i<=n-k; ++i) {
		sum = 0;
		for (int j=0; j<k; ++j)
			sum += num[i+j];
		ans = max(ans, sum);
	}
	cout << ans << '\n';

	return 0;
}
