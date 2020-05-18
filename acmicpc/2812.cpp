#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n, k;
string s, ans;
stack<char> st;

int main()
{
	cin >> n >> k >> s;
	for (int i=0; i<s.length(); ++i) {
		while (!st.empty() && k && st.top() < s[i]) {
			st.pop();
			k--;
		}
		st.push(s[i]);
	}

	while (!st.empty() && k--)
		st.pop();

	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

	return 0;
}
