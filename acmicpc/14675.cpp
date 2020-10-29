#include <iostream>
using namespace std;
#define MAX 100001

int n, x, y, q, t, k;
int cnt[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		cnt[x]++;
		cnt[y]++;
	}

	cin >> q;
	while (q--) {
		cin >> t >> k;
		if (t == 2 || cnt[k] > 1)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
