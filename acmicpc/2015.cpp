#include <iostream>
#include <map>
using namespace std;
#define MAX 200001

int n, k, t;
int sum[MAX];
map<int, int> m;
long long ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i=1; i<=n; ++i) {
		cin >> t;
		sum[i] = sum[i-1] + t;
	}

	m[0] = 1;
	for (int i=1; i<=n; ++i) {
		ans += m[sum[i]-k];
		m[sum[i]]++;
	}
	cout << ans << '\n';

	return 0;
}
