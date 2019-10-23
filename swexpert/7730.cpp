#include <iostream>
using namespace std;
#define MAX 1000001
#define INF 2000000000

int n;
long long m;
int tree[MAX];

bool check(int k)
{
	long long ret = 0;
	for (int i=0; i<n; ++i) {
		if (tree[i] - k > 0)
			ret += (tree[i] - k);
	}
	return ret >= m;
}

int main()
{
	int T;

	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> n >> m;
		for (int i=0; i<n; ++i)
			cin >> tree[i];

		int l = 0, r = INF;
		while (l <= r) {
			int mid = (l+r)/2;
			if (check(mid)) {
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		cout << "#" << t << " " << r << '\n';
	}

	return 0;
}
