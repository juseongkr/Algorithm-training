#include <iostream>
using namespace std;
#define MAX 1000001
#define INF 1000000000000

int n, m;
long long num[MAX];

bool check(long long k)
{
	long long ret = 0;
	for (int i=0; i<n; ++i)
		ret += k/num[i];
	return ret >= m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	long long l = 0, r = INF;
	while (l <= r) {
		long long mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	return 0;
}
