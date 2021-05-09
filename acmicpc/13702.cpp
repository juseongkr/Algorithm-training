#include <iostream>
using namespace std;
const int INF = 1e18+7;
#define MAX 10001

int n, k;
int drink[MAX];

bool check(int t)
{
	long long ret = 0;
	for (int i=0; i<n; ++i)
		ret += drink[i]/t;

	return ret >= k;
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> drink[i];

	long long l = 0, r = INF;
	while (l <= r) {
		long long mid = (l+r)/2;
		if (check(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	cout << r << '\n';

	return 0;
}
