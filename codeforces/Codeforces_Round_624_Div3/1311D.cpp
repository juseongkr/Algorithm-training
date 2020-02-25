#include <iostream>
using namespace std;
#define MAX 20002
const int INF = 1e18+7;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, a, b, c, A, B, C;

	cin >> t;
	while (t--) {
		int ans = INF;
		cin >> a >> b >> c;
		for (int i=1; i<=MAX; ++i) {
			for (int j=i; j<=MAX; j+=i) {
				for (int k=j; k<=MAX; k+=j) {
					int sum = abs(i-a) + abs(j-b) + abs(k-c);
					if (ans > sum) {
						ans = sum;
						A = i;
						B = j;
						C = k;
					}
				}
			}
		}
		cout << ans << '\n' << A << " " << B << " " << C << '\n';
	}

	return 0;
}
