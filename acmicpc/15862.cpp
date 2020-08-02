#include <iostream>
using namespace std;
#define MAX 200001

int n, k, r, x, y;
int dna[MAX], cnt[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k >> r;
	for (int i=0; i<n; ++i)
		cin >> dna[i];

	for (int i=0; i<r; ++i) {
		cin >> x >> y;
		cnt[x] += y;
	}

	int e = 0, check = r, ans = n+1;
	for (int s=0; s<n; ++s) {
		while (check && e < n) {
			if (--cnt[dna[e]] == 0)
				check--;
			e++;
		}
		if (check == 0)
			ans = min(ans, e-s);
		if (cnt[dna[s]]++ == 0)
			check++;
	}

	if (ans == n+1)
		cout << "impossible\n";
	else
		cout << ans << '\n';

	return 0;
}
