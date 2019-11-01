#include <iostream>
using namespace std;
#define MAX 1000001
const int INF = 1e9;

int n, m;
int s[MAX];

bool check(int k)
{
	int ret = 0;
	for (int i=0; i<n; ++i)
		ret += s[i]/k;
	return ret >= m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	int l = 1, r = INF;
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
