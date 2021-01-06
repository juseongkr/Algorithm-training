#include <iostream>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

int k[MAX];
int n, q, u, v, c, a, b;

int main()
{
	cin >> n >> q >> u >> v;
	for (int i=1; i<=n; ++i) {
		cin >> k[i];
		k[i] = u * k[i] + v;
	}

	while (q--) {
		cin >> c >> a >> b;
		if (c) {
			k[a] = u * b + v;
		} else {
			int sum = -INF, ret = -INF;
			for (int i=a; i<=b; ++i) {
				sum = max(sum, 0) + k[i];
				ret = max(ret, sum);
			}
			cout << ret - v << '\n';
		}
	}

	return 0;
}
