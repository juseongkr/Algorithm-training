#include <iostream>
using namespace std;
#define MAX 1000001
const int INF = 1e9+7;

int r, b, n;
int lmax[MAX], rmax[MAX], num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> num[i];

	lmax[0] = -INF;
	for (int i=1; i<=n; ++i)
		lmax[i] = max(lmax[i-1], num[i]);

	rmax[n+1] = -INF;
	for (int i=n; i>=1; i--)
		rmax[i] = max(rmax[i+1], num[i]);

	for (int i=1; i<n; ++i) {
		if (lmax[i] > rmax[i+1])
			r++;
		else if (lmax[i] < rmax[i+1])
			b++;
	}

	if (r > b)
		cout << "R\n";
	else if (r < b)
		cout << "B\n";
	else
		cout << "X\n";

	return 0;
}
