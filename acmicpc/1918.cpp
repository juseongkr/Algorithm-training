#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> st;
	string s, ret;

	cin >> s;
	for (int i=0; i<s.length(); ++i) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			ret += s[i];
		} else if (s[i] == '(') {
			st.push(s[i]);
		} else if (s[i] == '*' || s[i] == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				ret += st.top();
				st.pop();
			}
			st.push(s[i]);
		} else if (s[i] == '+' || s[i] == '-') {
			while (!st.empty() && st.top() != '(') {
				ret += st.top();
				st.pop();
			}
			st.push(s[i]);
		} else if (s[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				ret += st.top();
				st.pop();
			}
			st.pop();
		}
	}

	cout << ret;
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}
