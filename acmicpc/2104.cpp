#include <iostream>
#include <stack>
using namespace std;
#define MAX 100001

long long num[MAX], p[MAX];

int main()
{
	stack<pair<int, int>> st;
	long long ans = 0;
	int n;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> num[i];
		p[i] = p[i-1] + num[i];
	}

	for (int i=1; i<=n+1; ++i) {
		while (!st.empty()) {
			long long m = st.top().first;
			if (m < num[i])
				break;

			st.pop();
			long long sub = 0;
			if (!st.empty())
				sub = st.top().second;

			long long sum = p[i-1] - p[sub];
			ans = max(ans, sum * m);
		}
		st.push({num[i], i});
	}
	cout << ans << '\n';

	return 0;
}
