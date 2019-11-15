#include <iostream>
#include <stack>
using namespace std;
#define MAX 100001

int num[MAX];

int main()
{
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	stack<int> st;
	int ans = 0;
	for (int i=0; i<=n; ++i) {
		while (!st.empty()) {
			int h = st.top();
			if (num[h] < num[i])
				break;
			st.pop();

			int w = i;
			if (!st.empty())
				w = i - st.top() - 1;

			ans = max(ans, num[h] * w);
		}
		st.push(i);
	}
	cout << ans << '\n';

	return 0;
}
