#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	ll n, k;

	cin >> t;
	while (t--) {
		priority_queue<ll, vector<ll>, greater<ll>> que;
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> k;
			que.push(k);
		}

		ll sum = 0;
		while (que.size() != 1) {
			ll a = que.top();
			que.pop();
			ll b = que.top();
			que.pop();
			que.push(a+b);
			sum += a+b;
		}
		cout << sum << '\n';
	}

	return 0;
}
