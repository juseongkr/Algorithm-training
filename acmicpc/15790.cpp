#include <iostream>
using namespace std;
#define MAX 1001

int n, m, k;
int cut[MAX];

bool check(int p)
{
	for (int i=0; i<m; ++i) {
		int cnt = 0, prev = i;
		for (int j=i+1; j<m; ++j) {
			if (cut[j] - cut[prev] >= p) {
				prev = j;
				if (++cnt == k)
					return true;
			}
		}
		if (n + cut[i] - cut[prev] >= p)
			cnt++;
		if (cnt >= k)
			return true;
	}
	return false;
}

int main()
{
	cin >> n >> m >> k;
	for (int i=0; i<m; ++i)
		cin >> cut[i];

	int l = 0, r = n+1;
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
