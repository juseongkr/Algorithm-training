#include <iostream>
using namespace std;
#define MAX 10001

int T, n, k, x;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	for (int test_case=1; test_case<=T; ++test_case) {
		cin >> n >> k;
		int len = 0;
		for (int i=0; i<n; ++i) {
			cin >> x;
			int it = lower_bound(num, num+len, x) - num;
			if (it == len)
				len++;
			num[it] = x;
		}
		int ans = (k <= len) ? 1 : 0;
		cout << "Case #" << test_case << '\n' << ans << '\n';
	}

	return 0;
}
