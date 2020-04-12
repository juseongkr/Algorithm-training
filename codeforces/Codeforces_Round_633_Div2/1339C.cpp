#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100001
 
int T, n;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		for (int i=1; i<n; ++i) {
			if (num[i-1] > num[i]) {
				int p = 0;
				int sub = num[i-1] - num[i];
				while (sub) {
					sub /= 2;
					p++;
				}
				num[i] = num[i-1];
				ans = max(ans, p);
			}
		}
		cout << ans << '\n';
	}
 
	return 0;
}
