#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
string str, ans;
bool tag;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	getline(cin, str);
	str += ' ';
	for (const auto s : str) {
		if (s == ' ') {
			while (!st.empty()) {
				ans += st.top();
				st.pop();
			}
			ans += s;
		} else if (s == '<') {
			while (!st.empty()) {
				ans += st.top();
				st.pop();
			}
			ans += s;
			tag = true;
		} else if (s == '>') {
			ans += s;
			tag = false;
		} else if (tag) {
			ans += s;
		} else {
			st.push(s);
		}
	}

	cout << ans << '\n';

	return 0;
}
