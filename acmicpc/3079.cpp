#include <iostream>
#include <climits>
using namespace std;
#define MAX 100001

long long num[MAX];
long long ans = LLONG_MAX;
int n, m;

bool check(long long t)
{
	long long sum = 0;
	for (int i=0; i<n; ++i)
		sum += t / num[i];

	if (sum >= m)
		return true;
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	long long l = 1, r = 1000000000000000000;
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
