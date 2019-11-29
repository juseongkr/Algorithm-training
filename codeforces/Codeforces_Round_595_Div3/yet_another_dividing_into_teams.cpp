#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

int num[MAX];

int main()
{
	int q, n;

	cin >> q;
	while (q--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		sort(num, num+n);

		int ans = 0;
		for (int i=1; i<n; ++i) {
			if (num[i] - num[i-1] == 1) {
				ans++;
				break;
			}
		}
		cout << ans + 1 << '\n';
	}

	return 0;
}
