#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001

int n, m;
long long num[MAX], sum[MAX], ans[MAX];

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		cin >> num[i];

	sort(num+1, num+n+1);

	for (int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + num[i];

	for (int i=1; i<=n; ++i) {
		ans[i%m] += sum[i];
		cout << ans[i%m] << ' ';
	}

	return 0;
}
