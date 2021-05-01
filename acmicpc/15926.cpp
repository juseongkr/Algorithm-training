#include <iostream>
#include <stack>
using namespace std;

string s;
int n, ans;
stack<int> st;

int main()
{
	cin >> n >> s;
	st.push(-1);
	for (int i=0; i<n; ++i) {
		if (s[i] == '(') {
			st.push(i);
		} else {
			st.pop();
			if (!st.empty())
				ans = max(ans, i - st.top());
			else
				st.push(i);
		}
	}

	cout << ans << '\n';

	return 0;
}
