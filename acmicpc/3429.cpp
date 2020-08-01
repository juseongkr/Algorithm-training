#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001
const int INF = 1e9+7;

int T, n;
int num[MAX], L[MAX], R[MAX], arr[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		L[0] = R[n-1] = 1;
		for (int i=1; i<n; ++i)
			L[i] = num[i-1] < num[i] ? L[i-1] + 1 : 1;

		for (int i=n-2; i>=0; i--)
			R[i] = num[i] < num[i+1] ? R[i+1] + 1 : 1;

		int ans = 0;
		fill(arr, arr+n+1, INF);
		for (int i=0; i<n; ++i) {
			int it = lower_bound(arr+1, arr+i+1, num[i]) - arr;
			ans = max(ans, R[i] + it - 1);
			arr[L[i]] = min(arr[L[i]], num[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}
