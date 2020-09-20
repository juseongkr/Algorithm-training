#include <iostream>
using namespace std;
#define MAX 100001

int n, k;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int sum = 0;
	for (int i=0; i<k; ++i)
		sum += num[i];

	int ans = sum;
	for (int i=k; i<n; ++i) {
		sum += num[i];
		sum -= num[i-k];
		ans = max(ans, sum);
	}

	cout << ans << '\n';

	return 0;
}
