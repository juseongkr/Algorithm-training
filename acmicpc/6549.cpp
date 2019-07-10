#include <iostream>
#include <stack>
using namespace std;
#define MAX 100001

int main()
{
	long long num[MAX];
	int n;

	while (cin >> n && n != 0) {
		long long ans = 0;
		stack<int> st;
		fill(num, num+MAX, 0);
		for (int i=0; i<n; ++i)
			cin >> num[i];

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
	}

	return 0;
}
