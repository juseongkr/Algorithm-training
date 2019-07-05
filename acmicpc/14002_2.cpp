#include <iostream>
#include <stack>
using namespace std;
#define MAX 1001

int n, s, ans;
int num[MAX], dp[MAX], p[MAX];

int main()
{
	cin >> n;
	fill(dp, dp+MAX, 1);
	fill(p, p+MAX, -1);
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<=i; ++j) {
			if (num[i] > num[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					p[i] = j;
				}
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
			s = i;
		}
	}

	stack<int> st;
	cout << ans << '\n';
	for (int i=s; i!=-1; i=p[i])
		st.push(num[i]);

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}
