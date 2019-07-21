#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10001


int main()
{
	int num[MAX], sum[MAX];
	int n, k;

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	for (int i=0; i<n-1; ++i)
		sum[i] = num[i+1] - num[i];

	sort(sum, sum+n-1);

	int ans = 0;
	for (int i=0; i<n-k; ++i)
		ans += sum[i];

	cout << ans << '\n';

	return 0;
}
