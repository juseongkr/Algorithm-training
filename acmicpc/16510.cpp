#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001

int n, m, k;
int psum[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		cin >> k;
		psum[i] = psum[i-1] + k;
	}

	while (m--) {
		cin >> k;
		int it = upper_bound(psum+1, psum+n+1, k) - psum;
		cout << it-1 << '\n';
	}

	return 0;
}
