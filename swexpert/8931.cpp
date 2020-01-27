#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int t, n, k;

	cin >> t;
	for (int T=1; T<=t; ++T) {
		stack<int> st;
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> k;
			if (k)
				st.push(k);
			else
				st.pop();
		}

		int ans = 0;
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		cout << "#" << T << " " << ans << '\n';
	}

	return 0;
}
