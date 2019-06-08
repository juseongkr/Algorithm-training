#include <iostream>
#include <cmath>
using namespace std;

int num[6][2];

int main()
{
	int n, k, s, g, ans = 0;

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> s >> g;
		num[g-1][s]++;
	}

	for (int i=0; i<6; ++i)
		for (int j=0; j<2; ++j)
			if (num[i][j])
				ans += ceil(num[i][j]/(double)k);

	cout << ans << '\n';

	return 0;
}
