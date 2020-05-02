#include <iostream>
using namespace std;
#define MAX 300001
const int INF = 1e9+7;

int d, n, k;
int sz[MAX], p[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> d >> n;
	sz[0] = INF;
	for (int i=1; i<=d; ++i) {
		cin >> k;
		sz[i] = min(sz[i-1], k);
	}

	for (int i=1; i<=n; ++i)
		cin >> p[i];

	for (int i=d, j=1; i>=1; i--) {
		if (p[j] <= sz[i]) {
			if (++j > n) {
				cout << i << '\n';
				return 0;
			}
		}
	}
	cout << "0\n";

	return 0;
}
