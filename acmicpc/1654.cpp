#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10001

long long num[MAX];
int k, n;

bool check(long long l)
{
	int ret = 0;
	for (int i=0; i<k; ++i)
		ret += num[i] / l;
	if (ret >= n)
		return true;
	return false;
}

int main()
{

	cin >> k >> n;
	for (int i=0; i<k; ++i)
		cin >> num[i];

	sort(num, num+k);

	long long ans = 0;
	long long l = 1, r = num[k-1];
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
