#include <iostream>
#include <stack>
using namespace std;
#define MAX 100001
#define ll long long

ll num[MAX], p[MAX];
ll ans;
int n;

int main()
{
	stack<pair<int, int>> st;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> num[i];
		p[i] = p[i-1] + num[i];
	}

	int a = 1, b = n;
	for (int i=1; i<=n+1; ++i) {
		while (!st.empty()) {
			ll m = st.top().first;
			if (m < num[i])
				break;

			st.pop();
			ll sub = 0;
			if (!st.empty())
				sub = st.top().second;

			ll sum = p[i-1] - p[sub];
			if (ans < sum * m) {
				ans = sum * m;
				a = sub+1;
				b = i-1;
			}
		}
		st.push({num[i], i});
	}
	cout << ans << '\n' << a << " " << b << '\n';

	return 0;
}
