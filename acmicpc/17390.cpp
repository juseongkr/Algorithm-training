#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 300001

int a[MAX], p[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;

	cin >> n >> q;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	sort(a, a+n);

	for (int i=0; i<=n; ++i)
		p[i+1] = p[i] + a[i];

	int l, r;
	while (q--) {
		cin >> l >> r;
		cout << p[r] - p[l-1] << '\n';
	}

	return 0;
}
