#include <iostream>
#include <stack>
using namespace std;
#define MAX 100001

int main()
{
	int n, ans = 0;
	int num[MAX];
	stack<int> st;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<=n; ++i) {
		while (!st.empty()) {
			int t = st.top();
			if (num[t] < num[i])
				break;
			st.pop();

			int w = i;
			if (!st.empty())
				w = i - st.top() - 1;

			ans = max(ans, num[t] * w);
		}
		st.push(i);
	}
	cout << ans << '\n';

	return 0;
}
