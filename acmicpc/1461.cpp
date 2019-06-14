#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10001

int main()
{
	int pos[MAX], neg[MAX];
	int n, m, v;
	int l = 1, r = 1, ans = 0;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> v;
		if (v > 0)
			pos[l++] = v;
		else
			neg[r++] = -v;
	}
	sort(pos, pos+l);
	sort(neg, neg+r);

	if (pos[l-1] < neg[r-1]) {
		ans += neg[r-1];
		r -= m;
	} else {
		ans += pos[l-1];
		l -= m;
	}

	while (l > 0 || r > 0) {
		if (l > 0) {
			ans += pos[l-1] * 2;
			l -= m;
		}
		if (r > 0) {
			ans += neg[r-1] * 2;
			r -= m;
		}
	}

	cout << ans << '\n';

	return 0;
}
