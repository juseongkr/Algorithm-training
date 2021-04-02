#include <iostream>
#include <stack>
using namespace std;
#define MAX 50001

int n, x, num[MAX];
stack<int> st;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x >> num[i];

	int ans = 0;
	for (int i=0; i<=n; ++i) {
		while (!st.empty() && st.top() > num[i]) {
			st.pop();
			ans++;
		}

		if (st.empty() || st.top() != num[i])
			st.push(num[i]);
	}

	cout << ans << '\n';

	return 0;
}
