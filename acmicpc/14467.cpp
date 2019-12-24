#include <iostream>
using namespace std;

int dict[11];
int n, x, k, ans;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> k;
		k++;
		if (dict[x] != 0 && dict[x] != k)
			ans++;
		dict[x] = k;
	}
	cout << ans << '\n';

	return 0;
}
