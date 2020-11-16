#include <iostream>
using namespace std;
#define MAX 300001
const int INF = 1e9+7;

int n, m;
int num[MAX];

bool check(int k)
{
	int ret = 0;
	for (int i=0; i<m; ++i) {
		ret += num[i] / k;
		if (num[i] % k > 0)
			ret++;
	}

	return ret <= n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> num[i];

	int l = 0, r = INF;
	while (l+1 < r) {
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}

	cout << r << '\n';

	return 0;
}
