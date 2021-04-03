#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int n, k, num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	long long ans = 0;
	for (int i=n-1; i>=0; i--)
		ans += max(0, num[i]-(++k)+1);

	cout << ans << '\n';

	return 0;
}
