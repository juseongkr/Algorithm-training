#include <iostream>
using namespace std;
#define MAX 100001
const long long INF = 1e18+7;

long long num[MAX];
long long ans = INF;
long long m;
int n;

bool check(long long t)
{
	long long sum = 0;
	for (int i=0; i<n; ++i) {
		sum += t / num[i];
		if (sum >= m)
			return true;
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	long long l = 0, r = INF;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
