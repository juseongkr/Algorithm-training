#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 500001

int tree[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, w, x, y, k = 0;

	cin >> n >> w;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		tree[x]++;
		tree[y]++;
	}

	for (int i=2; i<=n; ++i)
		if (tree[i] == 1)
			k++;

	if (tree[1] == 0)
		k++;

	cout << fixed << setprecision(10) << w/(double)k << '\n';

	return 0;
}
