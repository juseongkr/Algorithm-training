#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 601

int n, num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	int ans = num[2] + num[3] - (num[0] + num[1]);
	for (int i=0; i<n; ++i) {
		for (int j=i+3; j<n; ++j) {
			int x = num[i] + num[j];
			int l = i+1, r = j-1;
			while (l < r) {
				int y = num[l] + num[r];
				ans = min(ans, abs(x-y));
				if (y >= x)
					r--;
				if (y <= x)
					l++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
