#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 100001

int n;
long long k;
vector<long long> num;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		num.push_back(k);
	}

	stack<long long> st;
	long long ans = 0;
	for (int i=0; i<=n; ++i) {
		while (!st.empty()) {
			long long h = st.top();
			if (num[h] < num[i])
				break;
			st.pop();

			long long w = i;
			if (!st.empty())
				w = i - st.top() - 1;

			ans = max(ans, num[h] * w);
		}
		st.push(i);
	}
	cout << ans << '\n';

	return 0;
}
