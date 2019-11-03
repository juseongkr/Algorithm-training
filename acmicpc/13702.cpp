#include <iostream>
#include <climits>
using namespace std;
#define MAX 10001

int n, k;
int drink[MAX];

bool check(int t)
{
	int ret = 0;
	for (int i=0; i<n; ++i)
		ret += drink[i]/t;

	return ret >= k;
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> drink[i];

	int l = 0, r = INT_MAX;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	cout << r << '\n';

	return 0;
}
