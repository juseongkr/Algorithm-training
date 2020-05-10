#include <iostream>
using namespace std;
#define MAX 8001

int T, n;
bool check[MAX];
int num[MAX], psum[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		fill(psum, psum+MAX, 0);
		fill(check, check+MAX, 0);
		for (int i=1; i<=n; ++i) {
			cin >> num[i];
			psum[i] = psum[i-1] + num[i];
		}

		for (int i=2; i<=n; ++i) {
			for (int j=0; j<i-1; ++j) {
				if (psum[i] - psum[j] <= n)
					check[psum[i] - psum[j]] = 1;
			}
		}

		int ans = 0;
		for (int i=1; i<=n; ++i)
			ans += check[num[i]];

		cout << ans << '\n';
	}

	return 0;
}
