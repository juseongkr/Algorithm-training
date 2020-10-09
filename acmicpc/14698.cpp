#include <iostream>
#include <queue>
using namespace std;
#define MAX 61
#define ll long long
const int MOD = 1e9+7;

ll k;
int T, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		priority_queue<ll> que;
		for (int i=0; i<n; ++i) {
			cin >> k;
			que.push(-k);
		}

		ll ans = 1;
		while (que.size() > 1) {
			ll x = -que.top();
			que.pop();
			x *= -que.top();
			que.pop();

			que.push(-x);
			ans = ans * (x % MOD) % MOD;
		}

		cout << ans << '\n';
	}

	return 0;
}
