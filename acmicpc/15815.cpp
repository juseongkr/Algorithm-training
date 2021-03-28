#include <iostream>
#include <stack>
using namespace std;

string s;
stack<int> st;

int main()
{
	cin >> s;
	for (int i=0; i<s.length(); ++i) {
		if ('0' <= s[i] && s[i] <= '9') {
			st.push(s[i]-'0');
		} else {
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();

			if (s[i] == '+')
				st.push(x+y);
			else if (s[i] == '-')
				st.push(y-x);
			else if (s[i] == '*')
				st.push(x*y);
			else
				st.push(y/x);
		}
	}

	cout << st.top() << '\n';

	return 0;
}
